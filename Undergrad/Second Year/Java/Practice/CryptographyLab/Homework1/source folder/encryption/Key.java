package encryption;

import main.Utility;

/**
 * This class generates randomly a key, which is a permutation of the alphabet.
 * @author Andreea Rindasu
 *
 */
public class Key {

	public static char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
	private char[] key;
	
	// constructor to shuffle the letters in the alphabet
	// which will be the key
	public Key()
	{
		key = alphabet.clone();
	
		// Randomly permute the key around
		Utility.shuffleArray(key);
	}
	
	// method to get the Char Array version of the key
	public char[] toCharArray()
	{
		return key;
	}
	
	@Override
	public String toString()
	{
		return Utility.arrayToString(key);
	}
}