package main;
import des.*;

import java.util.Scanner;

public class Main {

	public static void main(String[] args)
	{
		System.out.println("Plaintext: ");
		String input = new Scanner(System.in).nextLine();
		
		// inputBits will store the 64 bits of the input as an int array ofsize 64
		int inputBits[] = new int[64];
		
		// For every character in the 16 bit input, we get its binary value
		// by first parsing it into an int and then converting to a binary
		// string
		for (int i = 0; i < 16; i++)
		{
			String s = Integer.toBinaryString(Integer.parseInt(input.charAt(i) + "", 16));
			
			// add 0 to the binary value 
			// 5: 0111 NOT 111
			while(s.length() < 4)
			{
				s = "0" + s;
			}	
			
			// Add the 4 bits we have extracted into the array of bits.
			for(int j = 0; j < 4; j++)
			{
				inputBits[(4 * i) + j] = Integer.parseInt(s.charAt(j) + "");
			}
		}
		
		System.out.println("Key: ");
		String key = new Scanner(System.in).nextLine();
		
		int keyBits[] = new int[64];
		for (int i = 0; i < 16; i++)
		{
			String s = Integer.toBinaryString(Integer.parseInt(key.charAt(i) + "", 16));
			while(s.length() < 4) {
				s = "0" + s;
			}
			for(int j = 0; j < 4; j++) 
			{
				keyBits[(4 * i) + j] = Integer.parseInt(s.charAt(j) + "");
			}
		}
		
		// permute(int[] inputBits, int[] keyBits, boolean isDecrypt)
		int outputBits[] = Des.permute(inputBits, keyBits, false);
		Des.permute(outputBits, keyBits, true);
	
	}
}
