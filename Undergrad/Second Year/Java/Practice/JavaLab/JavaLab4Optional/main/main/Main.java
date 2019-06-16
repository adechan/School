package main;
import java.io.IOException;
import catalog.*;
import graphs.InvalidGraphFormat;
import graphs.InvalidImageFormat;
import commands.*;

public class Main {

	public static void main(String[] args) throws InvalidImageFormat, InvalidGraphFormat
	{
		Catalog catalog = new Catalog("C:\\Users\\Andreea Rindasu\\eclipse-workspace\\JavaLab\\JavaLab4"); 
		
		System.out.println("Execute commands: ");
		System.out.println();
		
		while (true)
		{
			Shell shell = new Shell();
			try
			{
				Command command = shell.getCommand(catalog);
				command.execute();
			}
			catch (InvalidCommand e) {
				System.out.println(e.getMessage());
			} catch (GraphNotFound e) 			{
				e.printStackTrace();
			} catch (InvalidCatalogFormat e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}	
	}
}
