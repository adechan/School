package sumofdegrees;
import edges.Edges;

// TO DO
// sum of the degrees equals the value 2 * m
// sum EACH row of the matrix 
public class SumOfDegrees {

	public static boolean IsSumEqualsValue(int n, int[][] matrix, int value)
	{
		int sumRow[] = new int[n];
		int sum = 0;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sumRow[i] += matrix[i][j];	
				sum += sumRow[i];
		}
			
		System.out.println("Suma" + sum);
		}
		return true;
	}
}
