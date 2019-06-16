package main;

public class Main {

	public static void main(String[] args)
	{
		Catalog catalog = new Catalog("d:/graphs");  
		catalog.add (new Graph("K4", "complete/k4.tgf", "complete/view/k4.png"));  
		catalog.add (new Graph("Petersen", "special/petersen.tgf", "d:/ag/agr1.pdf"));  
		catalog.open("Petersen");
		catalog.save("catalog.dat");
		catalog.load("catalog.dat");
	    catalog.list();
	}
}
