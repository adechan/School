package main;

import java.awt.EventQueue;
import gui.*;

public class Main {

	/**
	 * Launch the application.
	 */
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable() {
		public void run() {
			try {
				DrawingFrame frame = new DrawingFrame();
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
