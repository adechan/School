package applicationlogiccode;

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
	
	/*
	 serialization : Converting an object to bytes 
	 _ useful when we want to Persist the Object.
	  When we want the object to exist beyond the 
	  lifetime of the JVM.
	 */
	
	// Serializable: mark interface (has no data and no methods)
	// used to mark java classes so that objects of these
	// classes may get certain capability
	public void serialize(Catalog output) throws IOException
	{
        // Reading the object from a file 
		FileOutputStream file = null; 
		ObjectOutputStream out = null;
        
		try 
		{
	        file = new FileOutputStream(this.filename); 
	        out = new ObjectOutputStream(file); 
			out.writeObject(output);
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
	        in.close(); 
	        file.close();
		}
		
        return temp;
	}
}
