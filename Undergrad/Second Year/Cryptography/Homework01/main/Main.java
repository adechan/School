package main;
import java.io.*;
import filtration.Filtration;
import encryption.Encryption;
import encryption.Key;

public class Main {
	
	public static void rest()
	{		
	}

	public static void main(String[] args)
	{

		// reading from a file line by line
		String getArg = args[0];
		
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
				// and make a-z A-Z
				String filtered = Filtration.getFiltratedString(line);
				bufferedWriter.write(Encryption.encryptPlaintext(filtered, key));
			}

			bufferedWriter.close();
			reader.close();
			
		}
		
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
}
