package graphs;

import java.io.Serializable;

/**
 * Graph is a class that represents a graph. 
 * @author Andreea Rindasu
 *
 */
public class Graph implements Serializable {

	private static final long serialVersionUID = 1L;
	
	private static final String[] supportedGraphFormats = {
		"tgf"	
	};
	
	private static final String[] supportedImageFormats = {
		"jpg",
		"jpeg",
		"png",
		"pdf"
	};
	
	protected String name;
	protected String description;
	protected String definition;
	protected String image;
	
	// function that checks if the image has valid format (.jpg, .png, .pdf)
	private static boolean checkValidImageFormat(String imagePath)
	{
		for (String extension : supportedImageFormats)
		{
			int index = imagePath.lastIndexOf("." + extension);
			
			// checks if the file extension is the right one 
			if (index == imagePath.length() - extension.length() - 1)
				return true;
		}
		
		return false;
	}
	
	// function that checks if the graph has valid format (.tgf)
	private static boolean checkValidGraphFormat(String graphPath)
	{
		for (String extension : supportedGraphFormats)
		{
			int index = graphPath.lastIndexOf("." + extension);
			
			if (index == graphPath.length() - extension.length() - 1)
				return true;
		}
		
		return false;
	}
	
	public Graph(String name, String description, String image) throws InvalidImageFormat, InvalidGraphFormat
	{
		this.name = name;
		this.description = description;
		this.image = image;

		if (!checkValidGraphFormat(description))
			throw new InvalidGraphFormat("Invalid graph format");

		if (!checkValidImageFormat(image))
			throw new InvalidImageFormat("Invalid image format");
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getDescription() {
		return description;
	}
	
	public String getDefinition() {
		return definition;
	}
		
	public String getImage() {
		return image;
	}
	
	
	public String toString()
	{
		return this.name + ": " + this.description + ", " + this.image;
	}
}
