package displaymatrix;

public class DisplayMatrix {
	
	public static void display(int n, int[][] array)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				System.out.print(array[i][j]);
			}
			System.out.println();
		}
	}
}
