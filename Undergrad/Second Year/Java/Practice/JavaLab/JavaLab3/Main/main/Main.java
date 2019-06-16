package main;
import locations.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import graphs.*;
import locationproperties.Payable;
import locationproperties.Visitable;

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
		
		ArrayList<Node> nodesGraph = new ArrayList<Node>();
		nodesGraph = map.getNodes();
		
		List<Visitable> v = nodesGraph.stream()
				// returns true if node implements Visitable
				.filter(node ->
				{
					if ((node instanceof Visitable) && !(node instanceof Payable))
						return true;
					return false;
				})
				.map(node -> (Visitable)node)
				.sorted(Comparator.comparing(Visitable::getOpeningHours))
				.collect(Collectors.toList());
	
		Double getEntryFee = nodesGraph.stream()
				.filter(node -> node instanceof Payable)
				.map(node -> (Payable)node)
				.collect(Collectors.averagingInt(p -> p.getEntryFee()));
		
		for (Visitable node : v)
			System.out.println(node);
		
		System.out.println(getEntryFee);
		
		
		/*
		 * node -> "openingHours".equals(node)
		 * this creates a free function
		 * ReturnType lambda(ArgType node)
		 * {
		 * 		return "openingHours".equals(node);
		 * }
		 * 
		 * Java figures out what ReturnType is based on what the type of 
		 * the expression is after "return"
		 * It also figures out what ArgType is based on how node is used in the lambda 
		 */
		
	}
}
