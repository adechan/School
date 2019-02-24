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
		long startTime = System.currentTimeMillis();
		int n = 0;
		if (Integer.parseInt(args[0]) % 2 != 0)
		{
			n = Integer.parseInt(args[0]);
		}
		else
			System.out.println("The argument is not valid!");
		
		String typeOfGraph = args[1];
		
		// create matrix
		int[][] matrix = AdjacencyMatrix.CreateMatrix(n, typeOfGraph);
		
		// display matrix
		DisplayMatrix.Display(n, matrix);	
		System.out.println();
		
		// edges
		int m = Edges.NumberOfEdges(n, matrix);
		System.out.println("Number of edges is " + m);
		
		// maximum and minimum degree
		Degree.maximumDegree(n, matrix);
		Degree.minimumDegree(n, matrix);
		
		// verify if sum of degrees = 2 * m
		if (SumOfDegrees.IsSumEqualsValue(n, matrix, m) == true)
			System.out.println("Sum of degrees is equal to 2 * m");
		
		System.out.println(System.currentTimeMillis() - startTime);	
	
	}
}
