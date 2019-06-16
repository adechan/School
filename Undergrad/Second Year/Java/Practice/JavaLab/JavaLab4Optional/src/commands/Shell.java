package commands;
import java.util.Scanner;

import catalog.Catalog;

public class Shell {
	

    private Scanner scanner;
	
    public Shell()
    {
    	scanner = new Scanner(System.in);
    }
	private String getInput()
	{
		return this.scanner.nextLine();
	}
	
	// Checks if the string looks like "hello there"
	// if it has " at the beginning and end, then it removes them and
	// returns the string in between them
	// otherwise it just returns the original string
	private static String removeFirstLastQuotations(String string)
	{
		int firstIndex = string.indexOf('\"');
		int lastIndex = string.lastIndexOf('\"');
		if (firstIndex == 0 && lastIndex == string.length() - 1)
			return string.substring(1, lastIndex);
		
		return string;
	}

	public Command getCommand(Catalog catalog) throws InvalidCommand
	{
		String[] stringsToCheck = this.getInput().split("\\s*,\\s*");
		String[] commandCheck = stringsToCheck[0].split("\\s+");
		
		if ( commandCheck[0].toLowerCase().equals("add"))
		{
			String name = removeFirstLastQuotations(commandCheck[1]);
			String description = removeFirstLastQuotations(stringsToCheck[1]);
			String definitionPath = removeFirstLastQuotations(stringsToCheck[2]);
			String imagePath = removeFirstLastQuotations(stringsToCheck[3]);
			return new AddCommand(catalog, name, description, definitionPath, imagePath);
		}
		
		else if ( commandCheck[0].toLowerCase().equals("open"))
		{
			return new OpenCommand(catalog, commandCheck[1]);
		}
		
		else if ( commandCheck[0].toLowerCase().equals("save"))
		{
			return new SaveCommand(catalog, commandCheck[1]);
		}
		
		else if ( commandCheck[0].toLowerCase().equals("load"))
		{
			return new LoadCommand(catalog, commandCheck[1]);
		}
		
		else if ( commandCheck[0].toLowerCase().equals("list"))
		{
			return new ListCommand(catalog);
		}

		throw new InvalidCommand("Invalid command");
	}
}
