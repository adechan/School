package crack;
import java.util.*;
import main.Utility;
/**
 * This class is supposed to take a cryptotext and try to decrypt it until you can get a readable text.
 * The decryption is made using symbol frequency, the most used symbol found in cryptotext is probably
 * the most used symbol in english.
 * @author Andreea Rindasu
 *
 */
/* Frequency Letter:
 * E, T, A, O, I, N, S, H, R, D, L
 * TH THE 
 * 
 */

public class Decryption {

	String[] commonLength1 = {"E", "T", "A", "O", "I", "N", "S"};
	String[] commonLength2 = {"TH", "ER", "ON", "AN", "HE", "IN", "ED", "ND", "HA", "ET", "EN", "ES", "OF", "OR", "NT", "EA", "TO"};
	String[] commonLength3 = {"THE", "AND", "THA", "ENT", "ION", "TIO", "FOR", "NDE"};
	/*
	 * arrayOfHighFrequency = {E, T, A, O, I, N, S}
	 * Having a cryptotext you should replace each letter from it with 
	 * a letter from arrayOfHighFrequency 
	 * till you can't replace anymore. After that you are going to replace groups of letters
	 * {TH, ER, ON, AN, SS, EE, TT, FF, HE, IN, ND, RE, ED, ES, OU, 
	 * 
	 * 
	 * SINGLE LETTERS:  E, T, A, O, I, N, S, H, R, D, L, U
	 * DOUBLE LETTERS: TH, ER, ON, AN, HE, IN, ED, ND, HA, ET, EN, ES, OF
	 * 					OR, NT, EA, TO
	 * 
	 * TRIPLE LETTERS: THE, AND, THA, ENT, ION, TIO, FOR, NDE
	 * COMMON DOUBLES: SS, EE, TT, FF, LL, MM, OO
	 */
	public static String decryptCryptotext(String cryptotext)
	{
		int[] alphabetCount = Utility.countLetters(cryptotext);

		// 
		
		/*int nextIndex = getMaxIndex(alphabetCount);
		
		int maximum = 0;
		
		for (int i = 0; i < cryptotext.length(); i++) 
		{
			maximum = cryptotext.indexOf(i);
			
			int[] alphabetCount = Utility.countLetters(cryptotext);
			for (int j = 0; i < alphabetCount.length; ++j)
			{
				if (alphabetCount[j] > maximum)
					maximum = alphabetCount[j];
			}
				
		}*/
		
		return cryptotext;
			
	}
	
	private static int substringCount(String string, String substring)
	{
		int count = 0;
		int next = 0;
		
		while (next != -1)
		{
			next = string.indexOf(substring);
			count++;
		}
		
		return count;
	}
	
	private static int getMaxIndex(int[] array)
	{
		int max = 0;
		int maxIndex = 0;
		for (int i = 0; i < array.length; ++i)
		{
			if (array[i] > max)
			{
				max = array[i];
				maxIndex = i;
			}
		}
		
		return maxIndex;
	}
}
