package encryption;
import main.Utility;

/**
 * This class is supposed to encrypt a text using a random Key.
 * After getting the filtrated plaintext, which is a text that contains only uppercase letters,
 * we want to start encrypting it. The key used in encryption is a permutation of the letters in the alphabet
 * (26 characters). We are going to use the filtrated plaintext and the key so we can encrypt the text.
 * We check for every letter in the plaintext and encrypt it such that the element of the plaintext will be 
 * changed with the element of the key, knowing that the key is an array that starts from 0 ( 0 representing 
 * the letter A in the plaintext and so on).
 * 
 * @author Andreea Rindasu
 *
 */
public class Encryption {

	/**
	 * The method encryptPlaintext should have as parameters the text we want to encrypt 
	 * This should return a new string which is encrypted.
	 * @param plaintext : the text to encrypt 
	 * @param key : the key to use for encryption. 
	 * @return encrypted plaintext
	 */
	public static String encryptPlaintext(String plaintext, Key key)
	{
		// converts the string to a new character array
		char[] encryptedText = plaintext.toCharArray();
		char[] keyArray = key.toCharArray();
		
		// until you meet the end of the file 
		// check if the next char is a letter
		for (int i = 0; i < plaintext.length(); ++i)
		{
			if (Character.isLetter(plaintext.charAt(i)))
			{
				// keyIndex will be 65 - 65 = 0 -> A
				// keyIndex will be 66 - 65 = 1 -> B
				// keyIndex will be 67 - 65 = 2 -> C
				
				int keyIndex = (int)Character.toUpperCase(plaintext.charAt(i)) - 65;
				
				// when we do keyArray[keyIndex] 
				// it will give us the encrypted version of the 
				// keyIndex'th letter
				encryptedText[i] = keyArray[keyIndex];
			}
		}
		
		// returns the encryptedText as a string
		return Utility.arrayToString(encryptedText);
	}
	
	public static Key generateKey()
	{	
		return new Key();
	}
}
