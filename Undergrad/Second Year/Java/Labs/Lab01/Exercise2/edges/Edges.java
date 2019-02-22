package edges;

public class Edges {

	public static int NumberOfEdges(int n, int[][] matrix)
	{	
		// when you see [1,2] = 1 && [2,1] = 1 => 1 edge
		int edges = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 1 && matrix[j][i] == 1)
					edges++;
			}
		}
		
		// it counts each edge 2 times
		edges = edges/ 2;
		return edges;
	}
}
