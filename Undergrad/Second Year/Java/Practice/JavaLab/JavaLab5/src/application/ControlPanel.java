package application;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JPanel;

public class ControlPanel extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private final CatalogFrame frame;
	public ControlPanel(CatalogFrame frame)
	{
		this.frame = frame;
		FlowLayout flowLayout = (FlowLayout) this.getLayout();
		
		JButton saveButton = new JButton("save");
		this.add(saveButton);
		
		JButton loadButton = new JButton("load");
		this.add(loadButton);
		
		JButton openButton = new JButton("open");
		this.add(openButton);
		
		JButton listButton = new JButton("list");
		this.add(listButton);
	}
	
}
