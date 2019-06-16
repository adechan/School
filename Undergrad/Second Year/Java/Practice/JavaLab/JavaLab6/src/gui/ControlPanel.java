package gui;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;

/**
 * A control panel for managing items of the catalog (load, save, etc.). 
 * This panel will contains buttons for: load, save, etc.
 * This will be placed at the bottom of the 
 * @author Andreea Rindasu
 *
 */
public class ControlPanel extends JPanel {
	
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private final DrawingFrame frame;
    
    private JButton loadButton = new JButton("Load");
    private JButton saveButton = new JButton("Save");
    private JButton resetButton = new JButton("Reset");

    public ControlPanel(DrawingFrame frame) {
        this.frame = frame;
        init();
    }
    
    private File selectFile()
    {
		JFileChooser fileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());

		int returnValue = fileChooser.showOpenDialog(null);

		if (returnValue == JFileChooser.APPROVE_OPTION) {
			return fileChooser.getSelectedFile();
		}
    	
		return null;
    }
    
    private void init() {
        this.add(loadButton);
		this.add(saveButton);
		this.add(resetButton);
		
		this.loadButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {

				try 
				{
					File imageFile = selectFile();
					if (imageFile != null)
						frame.canvas.setImage(ImageIO.read(imageFile));
				}
				catch (IOException e1) 
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		
		this.resetButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {
				frame.canvas.resetImage();
			}
		});
		
		// On AddButton click, add the graphForm values to the catalog list
		this.saveButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					File imageFile = selectFile();
					if (imageFile != null)
						ImageIO.write(frame.canvas.getImage(), "png", imageFile);
				} 
				catch (IOException e1) 
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
    }
}
