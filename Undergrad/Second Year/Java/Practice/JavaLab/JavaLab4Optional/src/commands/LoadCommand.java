package commands;

import java.io.IOException;

import catalog.Catalog;
import catalog.GraphNotFound;
import catalog.InvalidCatalogFormat;

public class LoadCommand extends Command {

	private Catalog catalog;
	private String catalogPath;
	
	public LoadCommand(Catalog catalog, String catalogPath)
	{
		this.catalog = catalog;
		this.catalogPath = catalogPath;
	}

	@Override
	public void execute() throws GraphNotFound, IOException, InvalidCatalogFormat 
	{
		this.catalog.load(this.catalogPath);
		System.out.println("Loaded catalog: " + this.catalogPath);
	}
}
