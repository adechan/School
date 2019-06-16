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
		// long startTime = System.currentTimeMillis();
		
		int n = 0;
		if (Integer.parseInt(args[0]) % 2 != 0)
		{
			n = Integer.parseInt(args[0]);
		}
		else
			System.out.println("The argument is not valid!");
		
		String typeOfGraph = args[1];
		
		// create matrix
		int[][] matrix = AdjacencyMatrix.createMatrix(n, typeOfGraph);
		
		// display matrix
		DisplayMatrix.display(n, matrix);	
		System.out.println();
		
		// edges
		int m = Edges.numberOfEdges(n, matrix);
		System.out.println("Number of edges is " + m);
		
		// maximum and minimum degree
		// Degree.MaximumDegree(n, matrix);
		System.out.println("Maximum degree is " + '\u0394' + "(G)= " + Degree.maximumDegree(n, matrix));
		
		// Degree.MinimumDegree(n, matrix);
		System.out.println("Minimum degree is " + '\u03B4' + "(G)= " + Degree.minimumDegree(n, matrix));
		
		// verify if sum of degrees = 2 * m
		if (SumOfDegrees.isSumEqualsValue(n, matrix, m) == true)
			System.out.println("Sum of degrees is equal to 2 * m");
		
		// verify if the graph is regular graph
		if (Degree.isRegularGraph(n, matrix) == true)
			System.out.println("It is regular graph!");
		else
			System.out.println("It is not regular graph!");
		
		// System.out.println(System.currentTimeMillis() - startTime);	
	
	}
}
