package filtration;

/**
 * A class used to filtrate the plaintext we want to encrypt by 
 * deleting everything that it is NOT a letter, and make the 
 * letters a-z in format A-Z.
 * @author Andreea Rindasu
 *
 */
public class Filtration {

		public static String getFiltratedString(String textToEncrypt)
	{
			String encryptInitial = textToEncrypt.replaceAll("[^a-zA-Z]+", "");
			return encryptInitial.toUpperCase();
	}

	
}
