package applicationlogiccode;
/**
 * InvalidImageFormat is an exception class used for
 * when the image has invalid format.
 * @author Andreea Rindasu
 *
 */
public class InvalidImageFormat extends Exception {

	private static final long serialVersionUID = 1L;
	public InvalidImageFormat(String message)
	{
		super(message);
	}
}
