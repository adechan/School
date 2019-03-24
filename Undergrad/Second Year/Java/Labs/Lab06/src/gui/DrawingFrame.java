package gui;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class DrawingFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel pane;
	
	Canvas canvas;
	DrawingPanel drawingPanel;
	ControlPanel controlPanel;

	/**
	 * Create the frame.
	 */
	public DrawingFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		pane = new JPanel();
		pane.setBorder(new EmptyBorder(5, 5, 5, 5));
		pane.setLayout(new BorderLayout(0, 0));
		this.setContentPane(pane);
		
		this.canvas = new Canvas(this);
		pane.add(canvas, BorderLayout.CENTER);
		
		drawingPanel = new DrawingPanel(this);
		pane.add(drawingPanel, BorderLayout.NORTH);
		
		controlPanel = new ControlPanel(this);
		pane.add(controlPanel, BorderLayout.SOUTH);
	}

}
