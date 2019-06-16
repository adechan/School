package catalog;
import java.util.*;
import graphs.Graph;
import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.io.Serializable;
/**
 * This class represents a catalog of graphs.
 * @author Andreea Rindasu
 *
 */
public class Catalog implements Serializable {

	private static final long serialVersionUID = 1L;
	
	private ArrayList<Graph> graphs = new ArrayList<Graph>();
	private String directory;
	
	public String getDirectory()
	{
		return this.directory;
	}
	
	public ArrayList<Graph> getGraphs()
	{
		return this.graphs;
	}
	
	public Catalog(String directory)
	{
		this.directory = directory;
	}
	
	public void add(Graph graphItem)
	{
		graphs.add(graphItem);
	}
	
	public void list()
	{
		for(Graph graph : graphs)
			System.out.println(graph);
	}
	
	// opens the image (or the definition) file using the 
	// native operating system application (see the Desktop class);
	public void open(String name) throws GraphNotFound, IOException
	{
		Graph found = null;
		for (Graph graph : this.graphs) 
		{
			if (graph.getName().equals(name))
				found = graph;
		}
		
		if (found == null)
			throw new GraphNotFound("Catalog doesn't have that graph");
		
		File image = new File(this.directory + "/" + found.getImage());
		Desktop d = Desktop.getDesktop();
		d.open(image);
	}
	
	// saves the catalog to an external file (either as 
	// text or binary using object serialization)
	public void save(String filename) throws IOException
	{
		// serialization: mechanism of converting the state
		// of an object into a byte stream
		CatalogIO serializer = new CatalogIO(this.directory + "/" + filename);
		
		serializer.serialize(this);
	}
	
	// loads the catalog from an external file
	public void load(String filename) throws IOException, InvalidCatalogFormat
	{ 
		CatalogIO serializer = new CatalogIO(this.directory + "/" + filename);
		
		// deserialization: the reverse process where the byte 
		// is used to recreate the actual Java object in memory
		Catalog temp = serializer.deserialize();
		this.graphs = temp.getGraphs();
		this.directory = temp.getDirectory();
	}
}
