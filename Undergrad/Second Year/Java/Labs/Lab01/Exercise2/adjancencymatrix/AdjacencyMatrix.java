package adjancencymatrix;

public class AdjacencyMatrix {
	
	// complete graph
	// only the principal diagonal HAS 0
	public static int[][] CreateMatrix(int n, String typeOfGraph)
	{
		int[][] matrix = new int[n][n];
		if (typeOfGraph.equals("complete"))
		{
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
		else if (typeOfGraph == "cycle")
		{
			
		}
		
		else if (typeOfGraph == "random")
		{
			
		}
		
		return matrix;
	}
	
}
