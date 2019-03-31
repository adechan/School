package graphs;
import java.util.ArrayList;

import graphs.Node;

public class Edge 
{
	Node start;
	Node end;
	
	public Edge(Node start, Node end) 
	{
		this.start = start;
		this.end = end;
	}
	
	public Node getStart()
	{
		return this.start;
	}
	
	public Node getEnd()
	{
		return this.end;
	}

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
