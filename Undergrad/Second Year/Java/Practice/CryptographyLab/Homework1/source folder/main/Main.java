package main;
import java.io.*;
import decryption.FrequencyAnalyzer;
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
			
			FileWriter writer = new FileWriter("writeFile.txt", false);
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
				encryptedFrankenstein += encrypted;
				bufferedWriter.write(encrypted);
			}

			bufferedWriter.close();
			reader.close();
			
		}
		
		catch (IOException e)
		{
			e.printStackTrace();
		}
		
		FrequencyAnalyzer frequencyAnalysis = new FrequencyAnalyzer(encryptedFrankenstein);		
		//System.out.println(frequencyAnalysis.getFrequencyTable(1));	// monograms
		System.out.println(frequencyAnalysis.getFrequencyTable(2)); // digrams

		try
		{
			FileWriter writer = new FileWriter("crackedText.txt", false);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);

			bufferedWriter.write(frequencyAnalysis.getFrequencyTable(1).toString() + "\r\n\r\n"); // digrams
			bufferedWriter.write(frequencyAnalysis.getFrequencyTable(2).toString() + "\r\n\r\n"); // digrams
			bufferedWriter.write(frequencyAnalysis.crack());
			bufferedWriter.close();
			
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		
		System.out.println("Done");
	}
}
