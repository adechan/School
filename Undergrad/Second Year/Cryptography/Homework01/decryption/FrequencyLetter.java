package decryption;

/**
 * This class counts the frequency for each letter in the cryptotext
 * and returns the number
 * @author Andreea Rindasu
 *
 */
public class FrequencyLetter {

	public static int countFrequencyLetter(String cryptotext)
	{
		char[] decryptedText = cryptotext.toCharArray();
		char character = 0;
		int count = 0;
		
		for (char i = 'A'; i <= 'Z'; i++)
		{
			for (int j = 0; j < decryptedText.length; j++)
			{
				if(decryptedText[i] == character)
					count++;
			}
		}

		return count;
	}
}
