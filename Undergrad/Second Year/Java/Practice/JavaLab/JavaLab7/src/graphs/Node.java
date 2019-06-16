package graphs;

/**
 * A class describing a Node.
 * 2 nodes contructs an edge. 
 * @author Andreea Rindasu
 *
 */
public class Node {

	private int node;
	
	public Node(int node)
	{
		this.node = node;
	}
	
	public int getNode()
	{
		return this.node;
	}
	
	@Override
	public boolean equals(Object object)
	{
		Node other = (Node)object;
		
		if (other != null)
			return other.node == this.node;
		
		return false;
	}
}
