package graphs;
import java.util.ArrayList;

import graphs.Node;

/**
 * A class decribing an Edge. 
 * An instance of this class will hold a pair of distinct numbers 
 * from 1 to n.
 * @author Andreea Rindasu
 *
 */
public class Edge 
{
	Node start;
	Node end;
	
	// Constructor
	public Edge(Node start, Node end) 
	{
		this.start = start;
		this.end = end;
	}
	
	// Get the start of the Edge
	public Node getStart()
	{
		return this.start;
	}
	
	// Get the end of the Edge
	public Node getEnd()
	{
		return this.end;
	}

	// Get all of the nodes 
	public ArrayList<Node> getNodes()
	{
		ArrayList<Node> nodes = new ArrayList<Node>();
		nodes.add(start);
		nodes.add(end);
		
		return nodes;
	}
	
	@Override
	public boolean equals(Object object)
	{
		Edge other = (Edge)object;
		
		if (other != null)
			return 
				(other.start == this.start && other.end == this.end) || 
				(this.end == other.start && this.start == other.end);
		
		return false;
	}
}
