package main;

import java.io.IOException;

import catalog.*;
import graphs.Graph;
import graphs.InvalidGraphFormat;
import graphs.InvalidImageFormat;

public class Main {

	public static void main(String[] args) throws InvalidImageFormat, InvalidGraphFormat
	{
		try
		{
			Catalog catalog = new Catalog("C:\\Users\\Andreea Rindasu\\eclipse-workspace\\JavaLab\\JavaLab4");
			catalog.add (new Graph("K4", "k4.tgf", "k4.png")); 
			catalog.add (new Graph("K3", "k3.tgf", "k3.png"));
			catalog.save("catalog.dat");
			catalog.list();
			catalog.load("catalog.dat");
			catalog.list();   
			catalog.open("K4");
			catalog.open("K3");
			
			// catalog.add (new Graph("K4", "k4","k4"));
			// catalog.open("K5");
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		catch (InvalidCatalogFormat e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (GraphNotFound e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}
}
