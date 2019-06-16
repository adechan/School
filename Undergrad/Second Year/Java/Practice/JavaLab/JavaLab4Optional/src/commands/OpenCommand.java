package commands;

import java.io.IOException;

import catalog.Catalog;
import catalog.GraphNotFound;

public class OpenCommand extends Command {

	private Catalog catalog;
	private String graphName;
	
	public OpenCommand(Catalog catalog, String graphName)
	{
		this.catalog = catalog;
		this.graphName = graphName;
	}

	@Override
	public void execute() throws GraphNotFound, IOException 
	{
		this.catalog.open(this.graphName);
		System.out.println("Opened graph image: " + this.graphName);
	}
}
