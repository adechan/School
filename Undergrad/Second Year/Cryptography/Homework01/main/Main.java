package main;
import java.io.*;
import filtration.Filtration;

public class Main {

	public static void main(String[] args)
	{
		
		/*
		 * reading from file 
		 * line by line
		 */
		String getArg = args[0];
		
		try
		{
			FileReader reader = new FileReader(getArg);
			BufferedReader bufferedReader = new BufferedReader(reader);
			
			String line;
			
			FileWriter writer = new FileWriter("writeFile.txt", true);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);
			
			// while we still have lines to read
			while ((line = bufferedReader.readLine()) != null)
			{
				// we have to remove everything BUT NOT A-Z
				// and make a-z A-Z
				// System.out.println(Filtration.GetFiltratedString(line));
				
				/*
				 * bufferedWriter.write(line);
				 *	bufferedWriter.write('\n');
				*/
				bufferedWriter.write(Filtration.GetFiltratedString(line));
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
