package main;
import java.io.*;
import java.util.ArrayList;
import java.util.Map;

import crack.Decryption;
import crack.FrequencyAnalyzer;
import filtration.Filtration;
import encryption.Encryption;
import encryption.Key;

public class Main {
	
	public static void main(String[] args)
	{

		// reading from a file line by line
		String getArg = args[0];
		
		String encryptedFrankenstein = "";
				
		try
		{
			FileReader reader = new FileReader(getArg);
			BufferedReader bufferedReader = new BufferedReader(reader);
			
			FileWriter writer = new FileWriter("writeFile.txt", true);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);
			
			Key key = new Key();
			System.out.println(Utility.arrayToString(Key.alphabet));
			System.out.println(key);
			
			String line;
			
			// while we still have lines to read
			while ((line = bufferedReader.readLine()) != null)
			{
				// we have to remove everything BUT NOT A-Z
				// and make a-z in A-Z
				String filtered = Filtration.getFiltratedString(line);
				String encrypted = Encryption.encryptPlaintext(filtered, key);
				encryptedFrankenstein += filtered;
				//bufferedWriter.write(encrypted);
			    // FrequencyLetter.countFrequencyLetter((Encryption.encryptPlaintext(filtered, key)));
			}

			bufferedWriter.close();
			reader.close();
			
		}
		
		catch (IOException e)
		{
			e.printStackTrace();
		}
		
		FrequencyAnalyzer frequencyAnalysis = new FrequencyAnalyzer(encryptedFrankenstein);		
		System.out.println(frequencyAnalysis.getFrequencyTable(1));
		//System.out.println("Cracked text: " + frequencyAnalysis.crack());

		try
		{
			FileWriter writer = new FileWriter("crackedText.txt", true);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);

			//bufferedWriter.write(frequencyAnalysis.crack(2));
			bufferedWriter.close();
			
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		
		System.out.println("Done");
	}
}
