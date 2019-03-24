package gui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JPanel;

import application.NodeShape;

public class Canvas extends JPanel {
	
	private final DrawingFrame frame;
	
	private BufferedImage image;
	private Graphics2D imageGraphics;

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
		
	public BufferedImage getImage()
	{
		return this.image;
	}
	
	public void resetImage()
	{
		this.image = new BufferedImage(800, 600, BufferedImage.TYPE_INT_ARGB);
		// Dispose of old image graphics to prevent memory leaks
		this.imageGraphics.dispose();
		
		// Set new graphics for drawing
		this.imageGraphics = this.image.createGraphics();
	    this.imageGraphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); //for "smooth" drawing
		this.repaint();
	}
	
	public void setImage(BufferedImage image)
	{
		this.image = image;
		
		// Dispose of old image graphics to prevent memory leaks
		this.imageGraphics.dispose();
		
		// Set new graphics for drawing
		this.imageGraphics = this.image.createGraphics();
	    this.imageGraphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); //for "smooth" drawing
		this.repaint();
	}
	
	public Canvas(DrawingFrame frame)
	{
		super();
		this.frame = frame;
		this.init();
	}
	
	public void init()
	{
		setPreferredSize(new Dimension(400, 400));
		
	    this.image = new BufferedImage(800, 600, BufferedImage.TYPE_INT_ARGB);
	    this.imageGraphics = image.createGraphics();
	    this.imageGraphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); //for "smooth" drawing
	    
		this.addMouseListener(new MouseAdapter()
		{
			public void mousePressed(MouseEvent e)
			{
				drawNode(e.getX(), e.getY(), frame.drawingPanel.getNodeSize());
				repaint();
			}
		});
	}
		
	@Override
	public void paintComponent(Graphics g) 
	{
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D)g;
		g2d.drawImage(this.image, 0, 0, null);
	}
	
    public void drawNode(int x, int y, int radius) {
        Random rand = new Random();
        
        this.imageGraphics.setColor(new Color(rand.nextInt(0xFFFFFF))); //you may use a random color or the one specified in the toolbar
        this.imageGraphics.fill(new NodeShape(x, y, radius));
    }
}
