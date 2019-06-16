package commands;

import catalog.Catalog;
import graphs.Graph;
import graphs.InvalidGraphFormat;
import graphs.InvalidImageFormat;

public class AddCommand extends Command {

	Catalog catalog;
	private String name;
	private String description;
	private String definitionPath;
	private String imagePath;
	
	public AddCommand(Catalog catalog, String name, String description, String definitionPath, String imagePath)
	{
		this.catalog = catalog;
		this.name = name;
		this.description = description;
		this.definitionPath = definitionPath;
		this.imagePath = imagePath;
	}
	
	@Override
	public void execute() throws InvalidImageFormat, InvalidGraphFormat 
	{
		this.catalog.add(new Graph(this.name, this.description, this.definitionPath, this.imagePath));
		System.out.println("Added " + this.name +  " to catalog");
	}
}
