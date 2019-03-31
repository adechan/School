package graphs;

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
