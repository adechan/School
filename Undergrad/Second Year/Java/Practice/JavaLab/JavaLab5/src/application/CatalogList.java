package application;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JList;

public class CatalogList extends JList {
    DefaultListModel model = new DefaultListModel<>();
	
    public CatalogList() {
        String title = "<html><i><font color='blue'>" + 
		    "Catalog Graphs" + "</font></i></hmtl>";
        this.setBorder(BorderFactory.createTitledBorder(title));
        this.setModel(model);        
    }    
    public void addGraph(String item) {
        model.addElement(item);
    }
}