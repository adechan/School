package application;

import javax.swing.JFrame;

public class CatalogFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	GraphForm form;
	CatalogList list;
	ControlPanel control;
	
	public CatalogFrame()
	{
		super("Visual Graph Manager");
		init();
	}
	
	private void init()
	{
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
}
