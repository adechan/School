import hashlib

def compare_count(a, b):
	count = 0
	for x, y in zip(a,b):
		if x == y:	
			count = count + 1
	return count

with open('fisier1', 'r') as f1:
	data_file1 = f1.read()
with open('fisier2', 'r') as f2:
	data_file2 = f2.read()

print("Informatiile din fisier: ", data_file1, data_file2)

h1_256 = hashlib.sha256(data_file1).hexdigest()
h2_256 = hashlib.sha256(data_file2).hexdigest()

print("Fisier", data_file1, "Hash1", h1_256)
print("Fisier", data_file2, "Hash2", h2_256)

count = compare_count(h1_256, h2_256)
print("Octeti identici in Sha256", count)

h1_md5 = hashlib.md5(data_file1).hexdigest()
h2_md5 = hashlib.md5(data_file2).hexdigest()

print("Fisier", data_file1, "Hash1", h1_md5)
print("Fisier", data_file2, "Hash2", h2_md5)

count1 = compare_count(h1_md5, h2_md5)
print("Octeti identici in Sha256", count1)
