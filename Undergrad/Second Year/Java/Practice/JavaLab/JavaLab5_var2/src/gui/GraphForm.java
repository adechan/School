package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 * A form for adding new graphs to the catalog. This form will contain input fields for name, 
 * type, path of the definition file, path of the image file, number of vertices and number of nodes.
 * The type can be one of the values: simple or directed. The form will also contain a button for adding 
 * a new graph in the catalog. 
 * @author Andreea Rindasu
 *
 */
public class GraphForm extends JPanel {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	// CatalogFrame 
    private final JFrame  catalogFrame;
    
    // private JLabel titleLabel = new JLabel("Name of the graph");
    
    private JRadioButton typeSimple = new JRadioButton("typeSimple");
    private JRadioButton typeDirected = new JRadioButton("typeDirected");
    private JTextField name = new JTextField();
    private JTextField pathDefinitionFile = new JTextField();
    private JTextField pathImageFile = new JTextField();
    private JTextField numberEdges = new JTextField();
    private JTextField numberVertices = new JTextField();
    private JButton addButton = new JButton("Add");
    
    public GraphForm(JFrame frame)
    {
    	this.catalogFrame = frame;
    	this.init();
    }
    
    private void init() 
    {
		name.setText("name");
		name.setColumns(10);
		this.add(name);
		
		this.add(typeSimple);
		this.add(typeDirected);
		
		pathDefinitionFile.setText("pathDefinitionFile");
		pathDefinitionFile.setColumns(10);
		this.add(pathDefinitionFile);
		
		pathImageFile.setText("pathImageFile");
		pathImageFile.setColumns(10);
		this.add(pathImageFile);
		
		numberVertices.setText("numberNodes");
		numberVertices.setColumns(10);
		this.add(numberVertices);
		
		numberEdges.setText("numberEdges");
		numberEdges.setColumns(10);
		this.add(numberEdges);
		
		// On AddButton click, add the graphForm values to the catalog list
		addButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {
				addGraph();
			}
		});
		
		this.add(addButton);
    }
    
    private String getType()
    {
    	if (this.typeDirected.isSelected())
    		return "Directed";

    	return "Simple";
    }
    
    private String getNumVertices()
    {
    	return this.numberVertices.getText();
    }
    
    private String getNumEdges()
    {
    	return this.numberEdges.getText();
    }
    
    private String getDefinition()
    {
    	return this.pathDefinitionFile.getText();
    }
    
    private String getImage()
    {
    	return this.pathImageFile.getText();
    }
    
    private void addGraph() {
    	/*this.catalogFrame.list.addGraph(
    		this.name.getText(),
    		this.getType(),
    		this.getNumVertices(),
    		this.getNumEdges(),
    		this.getDefinition(),
    		this.getImage()
    	);*/
    }
}