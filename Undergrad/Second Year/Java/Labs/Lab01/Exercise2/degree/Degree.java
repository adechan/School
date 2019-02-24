package degree;

public class Degree {

	// TO DO:
	// checking sum of each ROW 
	public static void maximumDegree(int n, int[][] matrix)
	{
		int sumRow[] = new int[n];
		int maximum = 0;
		char symbol = '\u0394';
		
		// i = row ; j = column
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sumRow[i] += matrix[i][j];
				
				maximum = sumRow[0];
				if (sumRow[i] > maximum)
					maximum = sumRow[i];
			}
		}
		// you CAN NOT use System.out with Unicode strings
		// UNICODE uses "UTF-16"

		System.out.println("Maximum degree is " + symbol + "(G)= " + maximum);
	}
	
	public static void minimumDegree(int n, int[][] matrix)
	{
		int sumRow[] = new int[n];
		int minimum = 0;
		char symbol = '\u03B4';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sumRow[i] += matrix[i][j];
				minimum = sumRow[0];
				if (sumRow[i] < minimum)
					minimum = sumRow[i];
				
			}
		}
		System.out.println("Minimum degree is " + symbol + "(G)= " + minimum);
	}
}
