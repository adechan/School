package guicode;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;

import applicationlogiccode.Catalog;

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
    
 // choose a file
    private File selectFile()
    {
    	// to select a file using this given file as a path
		JFileChooser fileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());

		// to pop up Open File
		int returnValue = fileChooser.showOpenDialog(null);

		// get the file
		if (returnValue == JFileChooser.APPROVE_OPTION) {
			return fileChooser.getSelectedFile();
		}
    	
		return null;
    }
    
    private void init() {
        this.add(loadButton);
		this.add(listButton);
		this.add(saveButton);
		this.add(openButton);
		
		loadButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {

				try 
				{
					File imageFile = selectFile();
					if (imageFile != null)
						frame.getImage(ImageIO.read(imageFile));
				}
				catch (IOException e1) 
				{
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
	
		saveButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e) {
			try 
			{
				File imageFile = selectFile();
				// saves as ".png"
				if (imageFile != null)
					ImageIO.write(frame.catalog.getImage(), "png", imageFile);
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
