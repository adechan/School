package main;
import calcul.Calcul;
import sum.Sum;
import display.Display;
import helloworld.HelloWorld;
import adjancencymatrix.AdjacencyMatrix;
import displaymatrix.DisplayMatrix;
import edges.Edges;
import degree.Degree;
import sumofdegrees.SumOfDegrees;

public class Main {

	public static void main(String[] args)
	{
		// exercise 1
		HelloWorld.helloWorld();
		Display.display(Sum.compute(Calcul.calcul()));		
		System.out.println();
		
		// exercise 2
		int n = 0;
		if (Integer.parseInt(args[0]) % 2 != 0)
		{
			n = Integer.parseInt(args[0]);
		}
		else
			System.out.println("The argument is not valid!");
		
		String typeOfGraph = args[1];
		
		int[][] matrix = AdjacencyMatrix.CreateMatrix(n, typeOfGraph);
		
		DisplayMatrix.Display(n, matrix);	
		
		int m = Edges.NumberOfEdges(n, matrix);
		System.out.println("Number of edges is " + m);
		
		Degree.maximumDegree(n, matrix);
		Degree.minimumDegree(n, matrix);
		
		System.out.println(SumOfDegrees.IsSumEqualsValue(n, matrix, m));
	}
}
