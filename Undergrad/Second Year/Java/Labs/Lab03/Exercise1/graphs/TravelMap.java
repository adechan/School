package graphs;
import graphs.Edge;
import locations.Node;
import java.util.*;

// array of locations, nodes and edges
public class TravelMap {
	
	ArrayList<Edge> edges;
	ArrayList<Node> nodes;
	
	public TravelMap()
	{
		this.edges = new ArrayList<Edge>();
		this.nodes = new ArrayList<Node>();
	}
	
	public void addNode(Node node)
	{
		nodes.add(node);
	}
	
	// overload
	// it is bidirectional by default
	public void addEdge(Node start, Node end, int cost)
	{
		addEdge(start, end, cost, true);
	}
	
	// override : same method name different implementation
	// overload : same method name different parameters
	
	public void addEdge(Node start, Node end, int cost, boolean isBidirectional)
	{
		Edge edge = new Edge(start, end, cost);
		edges.add(edge);
		
		if (isBidirectional)
		{
			Edge edge2 = new Edge(end, start, cost);
			edges.add(edge2);
		}
	}
	
	public ArrayList<Node> getNodes()
	{
		return nodes;
	}
	
}
