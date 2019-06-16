package game;

import graphs.Edge;
import graphs.Graph;

/**
 * A class describing a Board. 
 * An instance of this class will contain at the beginning the 
 * complete graph Kn.
 * @author Andreea Rindasu
 *
 */
public class Board {

	private Graph graph;
	
	// Constructor
	public Board(int size)
	{
		this.graph = Graph.createCompleteGraph(size);
	}
	
	// synchronized: preventing thread interference and memory 
	// Synchronization is build around the MONITOR LOCK
	// every object has a monitor lock associated with it, and a thread
	// may acquire, own, release a lock
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
