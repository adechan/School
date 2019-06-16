package commands;
import catalog.Catalog;

public class ListCommand extends Command{

	Catalog catalog;
	
	public ListCommand(Catalog catalog)
	{
		this.catalog = catalog;
	}

	@Override
	public void execute() 
	{
		this.catalog.list();
	}
}
