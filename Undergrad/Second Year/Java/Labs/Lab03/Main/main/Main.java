package main;
import locations.*;
import graphs.*;

public class Main {

	public static void main(String[] args)
	{
		Hotel v1 = new Hotel("Modern California");
		Church v2 = new Church("Modern Church");
		Restaurant v3 = new Restaurant("Modern West Virginia");
		Museum v4 = new Museum("Museum of Modern Arts");
		
		TravelMap map = new TravelMap();
		map.addNode(v1);
		map.addNode(v2);
		map.addNode(v3);
		map.addNode(v4);
		
		map.addEdge(v1, v2, 15); //two way street by default
		map.addEdge(v3, v2, 1, false); //one-way street
		 
		System.out.println("The map is: \n" + map.getNodes());
	}
}
