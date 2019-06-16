package graphs;
import locations.Node;

// connections between two nodes
public class Edge {

	protected int cost;
	Node start;
	Node end;
	
	public Edge(Node start, Node end, int cost)
	{
		this.start = start;
		this.end = end;
		this.cost = cost;
	}
	
	//public Edge(Node start, Node end, int )

	public int getCostKilometers()
	{
		return cost;
	}
}
