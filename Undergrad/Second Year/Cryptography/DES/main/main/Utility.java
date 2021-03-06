package main;

public class Utility {

	
	// XOR function between 2 int arrays 
	public static int[] xorFunction(int[] a, int[] b) 
	{
		int result[] = new int[a.length];
		for(int i = 0; i < a.length; i++)
		{
			result[i] = a[i] ^ b[i];
		}
		return result;
	}
	
	// Print bits as hexadecimal string
	public static void displayBits(int[] bits) 
	{
		for(int i = 0; i < bits.length ; i += 4) 
		{
			String result = new String();
			for(int j = 0; j < 4; j++) 
			{
				result += bits[i + j];
			}
			System.out.print(Integer.toHexString(Integer.parseInt(result, 2)));
			}
		System.out.println();
	}
			
}
