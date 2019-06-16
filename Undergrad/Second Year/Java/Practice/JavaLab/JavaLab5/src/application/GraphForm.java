package application;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;

public class GraphForm extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private final CatalogFrame frame;
	JLabel titleLabel = new JLabel("Name of the graph");
	
	JSpinner verticesField = new JSpinner(new SpinnerNumberModel(0,1000));

	private void init()
	{
		addButton.addActionListener(...);
	}
	
	private void addGraph()
	{
		frame.list.addGraph(...);
	}
}
