package graphs;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Graph {

	protected ArrayList<Edge> edges;
	protected ArrayList<Node> nodes;
	
	public static Graph createCompleteGraph(int size)
	{
		Graph complete = new Graph(size);
		ArrayList<Node> nodes = complete.getNodes();
		
		// Create a complete graph
		for (Node start : nodes)
		{
			for (Node end : nodes)
			{
				if (!start.equals(end) && !complete.hasEdge(start, end))
					complete.addEdge(start, end);
			}
		}
		
		return complete;
	}
	
	public Graph()
	{
		this.edges = new ArrayList<Edge>();
		this.nodes = new ArrayList<Node>();
	}

	public Graph(int size)
	{
		this.edges = new ArrayList<Edge>();
		this.nodes = new ArrayList<Node>();
		
		for (int i = 0; i < size; i++)
			this.nodes.add(new Node(i + 1));
	}
	
	public int order()
	{
		return this.nodes.size();
	}
	
	public int edgeCount()
	{
		return this.edges.size();
	}
	
	public ArrayList<Node> getNodes()
	{
		return this.nodes;
	}
	
	public ArrayList<Edge> getEdges()
	{
		return this.edges;
	}
	
	public void addEdge(Node start, Node end)
	{
		if (!nodes.contains(start) || !nodes.contains(end))
			return;
		
		this.edges.add(new Edge(start, end));
	}
	
	public void addEdge(Edge edge)
	{
		this.addEdge(edge.getStart(), edge.getEnd());
	}
	
	public Edge randomEdge()
	{
		if (this.edges.isEmpty())
			return null;
		
		Random random = new Random();
		return this.edges.get(random.nextInt(this.edges.size()));
	}
	
	public void removeEdge(Edge edge)
	{
		this.edges.remove(edge);
	}
	
	public void addNode(Node node)
	{
		this.nodes.add(node);
	}

	public boolean hasEdge(Edge edge)
	{
		return this.edges.contains(edge);
	}
	
	public boolean hasEdge(Node start, Node end)
	{
		return this.edges.contains(new Edge(start, end));
	}
	
	public boolean isTree()	
	{
		 return this.edges.size() == this.nodes.size() - 1;
	}
	
	public boolean isSpanning()
	{
		List<Node> nodes = new ArrayList<>(this.nodes);
		
		for (Edge edge : this.edges)
		{
			nodes.remove(edge.getStart());
			nodes.remove(edge.getEnd());
		}
		
		return nodes.size() == 0;
	}
	
	public boolean isSpanningTree()
	{
		return this.isSpanning() && this.isTree();
	}
}
