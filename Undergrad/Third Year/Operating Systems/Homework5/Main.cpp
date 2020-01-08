#include <iostream>
#include <Windows.h>
#include <AclAPI.h>
#include <string>

#include <sddl.h>

/*
Create a registry key which can be accessed and modified only by owner. 
After creation, add to this key the right for reading for all users.
The user must not be in admins group; if it is, then the OWNER is the group, and not the user
*/

int main()
{
	// Create a Security Descriptor 

	// Allocate memory for it:
	SECURITY_DESCRIPTOR* security_descriptor = (SECURITY_DESCRIPTOR*)LocalAlloc(0, SECURITY_DESCRIPTOR_MIN_LENGTH);

	// Initialize a Security Descriptor empty
	// without owner, group, SACL, DACL
	if (!InitializeSecurityDescriptor(
		security_descriptor,
		SECURITY_DESCRIPTOR_REVISION
		))
	{
		std::printf("InitializeSecurityDescriptor GLE: %d\n", GetLastError());
		return -1;
	}

	// Add the owner = SID to Security Descriptor

	std::string system_name = "desktop-n2tcmp3";
	std::string account_name = "ade2";

	BYTE sid[SECURITY_MAX_SID_SIZE];
	DWORD sid_size = SECURITY_MAX_SID_SIZE;

	DWORD domain_size = 256;
	std::string referenced_domain_name;
	referenced_domain_name.resize(domain_size, 0);

	SID_NAME_USE sid_type;

	// First get the SID
	if (!LookupAccountName(
		system_name.c_str(),
		account_name.c_str(),
		sid,
		&sid_size,
		referenced_domain_name.data(),
		&domain_size,
		&sid_type
		))
	{
		std::printf("LookupAccountName GLE: %d\n", GetLastError());
		return -1;
	}

	char* sid_string = nullptr;
	ConvertSidToStringSid(sid, &sid_string);
	std::printf("ade2 sid: %s\n", sid_string);

	// Set security descriptor's owner to ade2
	if (!SetSecurityDescriptorOwner(
		security_descriptor,
		sid,
		false
		))
	{
		std::printf("SetSecurityDescriptorOwner GLE: %d\n", GetLastError());
		return -1;
	}

	// Add/Modify DACL and SACL : using ACLs

	// First set the Explicit_Access for Owner
	// Allocate memory for it:
	EXPLICIT_ACCESS ade2_access;
	ade2_access.grfAccessPermissions = KEY_ALL_ACCESS;
	ade2_access.grfAccessMode = SET_ACCESS;
	ade2_access.grfInheritance = NO_INHERITANCE;

	ade2_access.Trustee.TrusteeForm = TRUSTEE_IS_SID;
	ade2_access.Trustee.TrusteeType = TRUSTEE_IS_USER;
	ade2_access.Trustee.ptstrName = (LPSTR)&sid;

	// Set and modify an ACL table 
	PACL new_acl = nullptr;

	DWORD ec = SetEntriesInAcl(
		1,
		&ade2_access,
		nullptr,
		&new_acl
	);

	if (ec != ERROR_SUCCESS)
	{
		std::printf("SetEntriesInAcl ec: %d\n", ec);
		std::printf("SetEntriesInAcl GLE: %d\n", GetLastError());
		return -1;
	}

	// Set ACL list to the Security Descriptor
	if (!SetSecurityDescriptorDacl(
		security_descriptor,
		true,
		new_acl,
		false
		))
	{
		std::printf("SetSecurityDescriptorDacl GLE: %d\n", GetLastError());
		return -1;
	}

	// Security Descriptor is attached to an object using Security_Attributes
	SECURITY_ATTRIBUTES security_attributes = {0};
	security_attributes.nLength = sizeof(security_attributes);
	security_attributes.bInheritHandle = false;
	security_attributes.lpSecurityDescriptor = security_descriptor;

	DWORD disposition = 0;
	HKEY created_key;
	LSTATUS status = RegCreateKeyEx(
		HKEY_CURRENT_USER,
		"Software\\AdeKey2",
		0,
		0,
		REG_OPTION_NON_VOLATILE,
		KEY_READ | KEY_WRITE,
		&security_attributes,
		// handle to the opened or created key
		&created_key,
		// pointer to variable that says if key was Create or Opened
		&disposition
	);

	std::printf("RegCreateKeyEx: %d\n", status);

	PSID everyone_sid;
	SID_IDENTIFIER_AUTHORITY sid_world_authority = SECURITY_WORLD_SID_AUTHORITY;

	// Get the SID for the Everyone group.
	if (!AllocateAndInitializeSid(&sid_world_authority, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &everyone_sid))
	{
		std::printf("AllocateAndInitializeSid GLE: %d\n", GetLastError());
		return -1;
	}

	SECURITY_DESCRIPTOR* security_descriptor2 = (SECURITY_DESCRIPTOR*)LocalAlloc(0, SECURITY_DESCRIPTOR_MIN_LENGTH);

	// Initialize a Security Descriptor empty
	// without owner, group, SACL, DACL
	if (!InitializeSecurityDescriptor(
		security_descriptor2,
		SECURITY_DESCRIPTOR_REVISION
	))
	{
		std::printf("InitializeSecurityDescriptor GLE: %d\n", GetLastError());
		return -1;
	}

	// Set security descriptor's owner to everyone
	if (!SetSecurityDescriptorOwner(
		security_descriptor2,
		&everyone_sid,
		false
	))
	{
		std::printf("SetSecurityDescriptorOwner GLE: %d\n", GetLastError());
		return -1;
	}

	// Now we add the right of reading for all users 
	EXPLICIT_ACCESS everyone_access[2];
	everyone_access.grfAccessPermissions = KEY_READ;
	everyone_access.grfAccessMode = SET_ACCESS;
	everyone_access.grfInheritance = NO_INHERITANCE;

	everyone_access.Trustee.TrusteeForm = TRUSTEE_IS_SID;
	everyone_access.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	everyone_access.Trustee.ptstrName = (LPSTR)&everyone_sid;

	PACL new_acl2 = nullptr;

	if (!SetEntriesInAcl(
		2,
		&everyone_access,
		new_acl,
		&new_acl2
	))
	{
		std::printf("SetEntriesInAcl GLE: %d\n", GetLastError());
		return 0;
	}

	// Set ACL list to the Security Descriptor
	if (!SetSecurityDescriptorDacl(
		security_descriptor2,
		true,
		new_acl2,
		false
	))
	{
		std::printf("SetSecurityDescriptorDacl GLE: %d\n", GetLastError());
		return 0;
	}

	status = RegSetKeySecurity(created_key, DACL_SECURITY_INFORMATION, security_descriptor2);
	std::printf("RegCreateKeyEx 2: %d\n", status);
	RegCloseKey(created_key);

	return 0;

}