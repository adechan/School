package commands;

import java.io.IOException;

import catalog.Catalog;
import catalog.GraphNotFound;
import catalog.InvalidCatalogFormat;

public class SaveCommand extends Command{

	private Catalog catalog;
	private String catalogPath;
	
	public SaveCommand(Catalog catalog, String catalogPath)
	{
		this.catalog = catalog;
		this.catalogPath = catalogPath;
	}

	@Override
	public void execute() throws GraphNotFound, IOException, InvalidCatalogFormat 
	{
		this.catalog.save(this.catalogPath);
		System.out.println("Saved catalog: " + this.catalogPath);
	}
}
