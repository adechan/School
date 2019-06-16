package commands;

import java.io.IOException;

import catalog.GraphNotFound;
import catalog.InvalidCatalogFormat;
import graphs.InvalidGraphFormat;
import graphs.InvalidImageFormat;

public abstract class Command {

	protected String command;

	abstract public void execute() throws InvalidImageFormat, InvalidGraphFormat, GraphNotFound, IOException, InvalidCatalogFormat;
}
