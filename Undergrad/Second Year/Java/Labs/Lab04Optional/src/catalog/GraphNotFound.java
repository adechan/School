package catalog;

/**
 * GraphNotFound is an exception class used for 
 * when a graph is not found.
 * @author Andreea Rindasu
 *
 */
public class GraphNotFound extends Exception {
	
	private static final long serialVersionUID = 1L;
	
	public GraphNotFound(String message)
	{
		super(message);
	}
}
