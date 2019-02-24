package adjancencymatrix;

public class AdjacencyMatrix {
	
	// complete graph
	// only the principal diagonal HAS 0
	public static int[][] CreateMatrix(int n, String typeOfGraph)
	{
		int[][] matrix = new int[n][n];
		if (typeOfGraph.equals("complete"))
		{
			System.out.println("Complete Graph:");
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j)
					{
						matrix[i][j] = 0;
					}
					else 
						matrix[i][j] = 1;
				}
			}
		}
		// graph starts and ends with SAME vertex
		// it has only two of 1 on each ROW
		
		// comparing pointers NOT values 
		// so we CAN NOT use "=="
		else if (typeOfGraph.equals("cycle"))
		{
			System.out.println("Cycle Graph:");
			for (int i = 0; i < n; i++)
			{
				// n = 5
				// example: a[0][4] and a[4][0] always 1
				matrix[0][n - 1] = 1;
				matrix[n - 1][0] = 1;
				
				for (int j = 0; j < n; j++)
				{
					if (i == j)
					{
						matrix[i][j] = 0;
					}
					
					else
					{
						if ((i == j - 1) || (i == j + 1))
						{
							matrix[i][j] = 1;
						}
					}
				}
			}
		}
		
		else if (typeOfGraph.equals("random"))
		{
			
		}
		
		return matrix;
	}
	
}
