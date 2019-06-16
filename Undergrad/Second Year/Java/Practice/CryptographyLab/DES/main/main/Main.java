package main;
import des.*;

import java.util.Scanner;

public class Main {

	public static void main(String[] args)
	{
		System.out.println("Plaintext: ");
		String plaintext = new Scanner(System.in).nextLine();
		int plaintextBits[] = new int[64];
		
		// First convert the plaintext to int, and then to binary string
		for (int i = 0; i < 16; i++)
		{
			String binaryStringPlaintext = Integer.toBinaryString(Integer.parseInt(plaintext.charAt(i) + "", 16));
			
			while(binaryStringPlaintext.length() < 4)
			{
				binaryStringPlaintext = "0" + binaryStringPlaintext;
			}	
			
			// Add the 4 bits we have extracted into the array of bits
			for(int j = 0; j < 4; j++)
			{
				plaintextBits[(4 * i) + j] = Integer.parseInt(binaryStringPlaintext.charAt(j) + "");
			}
		}
		
		System.out.println("Key: ");
		String key = new Scanner(System.in).nextLine();
		int keyBits[] = new int[64];
		
		// First convert the plaintext to int, and then to binary string
		for (int i = 0; i < 16; i++)
		{
			String binaryStringKey = Integer.toBinaryString(Integer.parseInt(key.charAt(i) + "", 16));
			
			while(binaryStringKey.length() < 4) 
			{
				binaryStringKey = "0" + binaryStringKey;
			}
			
			for(int j = 0; j < 4; j++) 
			{
				keyBits[(4 * i) + j] = Integer.parseInt(binaryStringKey.charAt(j) + "");
			}
		}
		
		int cryptotextBits[] = Des.encryptDecrypt(plaintextBits, keyBits, false);
		
		Des.encryptDecrypt(cryptotextBits, keyBits, true);
	
	}
}
