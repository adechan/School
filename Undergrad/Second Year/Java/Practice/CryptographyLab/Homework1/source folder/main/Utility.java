package main;
import java.util.Random;

public class Utility {

	/**
	 * The method shuffleArray shuffles a given array. 
	 * The algorithm starts from the end of the array and gets a random index from array,
	 * and it will swap the element from the random index with the last element from array. 
	 * @param array
	 */
	public static void shuffleArray(char[] array)
	{
		Random random = new Random();
		for (int i = array.length - 1; i > 0; i--)
		{
			int index = random.nextInt(i + 1);
			char temp = array[index];
			array[index] = array[i];
			array[i] = temp;
		}
	}
	
	// converts an array to string
	public static String arrayToString(char[] array)
	{
		String output = "";
		
		// for each element in the array 
		// we concatenate the ouput with the char element
		for (char c : array)
			output += c;
		
		return output;
	}	
}
