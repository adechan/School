package gui;

import javax.swing.*;

/**
 * the list of graphs (JList)
 * @author Andreea Rindasu
 *
 */
public class CatalogList extends JList<String> {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	DefaultListModel<String> model = new DefaultListModel<>();
	
    public CatalogList() {
        String title = "<html><i><font color='blue'>" + 
		    "Catalog Graphs" + "</font></i></hmtl>";
        this.setBorder(BorderFactory.createTitledBorder(title));
        this.setModel(model);        
    }    
    
    public void addGraph(String name, String type, String numVertices, String numEdges, String def, String image) {
        model.addElement(name + " (" + type + ", " + numVertices + ", " + numEdges + "): " + def + ", " + image);
    }
}
