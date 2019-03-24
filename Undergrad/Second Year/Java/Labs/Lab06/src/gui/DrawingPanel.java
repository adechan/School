package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class DrawingPanel extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private final DrawingFrame drawingFrame;
	
    private JTextField sizeOfNodes = new JTextField();
    private JTextField sizeOfStroke = new JTextField();
  
    public DrawingPanel(DrawingFrame frame)
    {
    	this.drawingFrame = frame;
    	this.init();
    }
    
    public void init()
    {
    	sizeOfNodes.setText("size of nodes");
    	sizeOfNodes.setColumns(10);
		this.add(sizeOfNodes);
		
		sizeOfStroke.setText("size of stroke");
    	sizeOfNodes.setColumns(10);
		this.add(sizeOfStroke);
    }
    
    public int getStrokeSize()
    {
    	try
    	{
        	return Integer.parseInt(this.sizeOfStroke.getText());
    	}
    	catch(NumberFormatException e)
    	{
    		return 5;
    	}
    }
    
    public int getNodeSize()
    {
    	try
    	{
        	return Integer.parseInt(this.sizeOfNodes.getText());
    	}
    	catch(NumberFormatException e)
    	{
    		return 5;
    	}
    }
}
