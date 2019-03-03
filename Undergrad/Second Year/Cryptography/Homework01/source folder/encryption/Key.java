package encryption;

import main.Utility;

public class Key {

	public static char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
	private char[] key;
	
	// constructor to shuffle the letters in the alphabet
	// which will be the key
	public Key()
	{
		key = alphabet.clone();
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
