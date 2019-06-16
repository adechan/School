package catalog;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


/**
 * CatalogIO is a class that is used for Catalog class.
 * It contains the serialization and deserialization of an object.
 * @author Andreea Rindasu
 *
 */

// serializer takes a catalog and writes it to a file
public class CatalogIO {

	private String filename;
	
	public CatalogIO(String filename)
	{
		this.filename = filename;
	}
	
	
	public void serialize(Catalog catalog) throws IOException
	{
        // Reading the object from a file 
		FileOutputStream file = null; 
		ObjectOutputStream out = null;
        
		try 
		{
	        file = new FileOutputStream(this.filename); 
	        out = new ObjectOutputStream(file); 
			out.writeObject(catalog);
		} 
		catch (IOException e)
		{
			throw e;
		}
		finally
		{
			out.close(); 
	        file.close();
		}
	}
	
	public Catalog deserialize() throws IOException, InvalidCatalogFormat
	{
        // Reading the object from a file 
        FileInputStream file = null; 
        ObjectInputStream in = null;
          
        // Method for deserialization of object 
        Catalog temp = null;
        
		try 
		{
	        file = new FileInputStream(this.filename); 
	        in = new ObjectInputStream(file); 
			temp = (Catalog)in.readObject();
		} 
		catch (IOException e)
		{
			throw e;
		}
		catch (ClassNotFoundException e) 
		{
			throw new InvalidCatalogFormat(e.getMessage());
		}
		finally
		{
			if (in != null)
				in.close();
			
			if (file != null)
				file.close();
		}
		
        return temp;
	}
}
