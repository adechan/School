package main;

import java.math.BigInteger;

public class Utility {
	
	/**
	 * Function that computes the greatest common divisor of integers a and b.
	 * @param a integer
	 * @param b integer
	 * @return the greatest common divisor of a and b
	 */
	public static int extendedEuclidianAlgorithm(int a, int b)
	{
		int temp;
		while(true)
		{
			temp = a % b;
			if (temp == 0)
				return b;
			a = b;
			b = temp;
		}
		
	}
	
	/**
	 * Converts an array of bytes into a string representing the array of bytes. Ex: 101, 104, 90
	 * @param array of bytes
	 * @return a String representing the array of bytes 
	 */
	public static String byteString(byte[] bytes) 
	{ 
		String result = "";
		for (byte b : bytes) 
			result += Byte.toString(b) + ", ";
		
		return result;
	}
}