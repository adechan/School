package catalog;

/**
 * InvalidCatalogFormat is an exception class used for
 * when the catalog has invalid format.
 * @author Andreea Rindasu
 *
 */
public class InvalidCatalogFormat extends Exception {
	
	private static final long serialVersionUID = 1L;

	public InvalidCatalogFormat(String message)
	{
		super(message);
	}
}
