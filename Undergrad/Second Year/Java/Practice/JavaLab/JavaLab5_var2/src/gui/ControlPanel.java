package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

/**
 * A control panel for managing items of the catalog (load, save, etc.). 
 * This panel will contains buttons for: load, save, etc.
 * @author Andreea Rindasu
 *
 */
public class ControlPanel extends JPanel {
	
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private final JFrame frame;
    
    private JButton loadButton = new JButton("Load");
    private JButton saveButton = new JButton("List");
    private JButton listButton = new JButton("Save");
    private JButton openButton = new JButton("Open");

    public ControlPanel(JFrame frame) {
        this.frame = frame;
        init();
    }
    
    private void init() {
        this.add(loadButton);
		this.add(listButton);
		this.add(saveButton);
		this.add(openButton);
    }
}
