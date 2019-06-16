package main;

import java.awt.EventQueue;
import guicode.*;

public class Main {

	public static void main(String[] args)
	{
		/**
		 * Launch the application.
		 */
			EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CatalogFrame frame = new CatalogFrame();
					frame.setVisible(true);
				} 
				catch (Exception e) 
				{
					e.printStackTrace();
				}
			}
		});
	}
}
