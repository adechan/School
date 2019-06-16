package graphs;

/**
 * InvalidGraphFormat is an exception class used for
 * when the graph has invalid format.
 * @author Andreea Rindasu
 *
 */
public class InvalidGraphFormat extends Exception {

	private static final long serialVersionUID = 1L;
	
	public InvalidGraphFormat(String message)
	{
		super(message);
	}
}
