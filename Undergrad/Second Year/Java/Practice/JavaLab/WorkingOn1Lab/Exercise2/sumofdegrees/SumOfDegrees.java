package sumofdegrees;
import edges.Edges;

public class SumOfDegrees {

	public static boolean isSumEqualsValue(int n, int[][] matrix, int value)
	{
		int sumRow[] = new int[n];
		int totalSum = 0;
		
		// i = row ; j = column
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{	
				sumRow[i] += matrix[i][j];
			}
			
			totalSum += sumRow[i];
		}
		
		if (totalSum != 2 * Edges.numberOfEdges(n, matrix))
			return false;
		return true;
	}
}
