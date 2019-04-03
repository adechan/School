package game;

import graphs.Edge;
import graphs.Graph;

public class Board {

	private Graph graph;
	
	public Board(int Size)
	{
		this.graph = Graph.createCompleteGraph(Size);
	}
	
	public synchronized Edge extract()
	{
		Edge edge = this.graph.randomEdge();
		this.graph.removeEdge(edge);
		return edge;
	}
    
    public boolean isEmpty()
    {
    	return this.graph.order() == 0;
    }
    
    public int nodeCount()
    {
    	return this.graph.order();
    }
    
    public int edgeCount()
    {
    	return this.graph.edgeCount();
    }
}
