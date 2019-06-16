package gui;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

/**
 * the main frame of the application (JFrame)
 * @author Andreea Rindasu
 *
 */
public class CatalogFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private JPanel contentPane;
	
    GraphForm form;
    CatalogList list;
    ControlPanel control;     

	public CatalogFrame() {
        super("Visual Graph Manager");
        this.init();
	}
	
	private void init()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 942, 502);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		list = new CatalogList();
		contentPane.add(list, BorderLayout.CENTER);
		
		form = new GraphForm(this);
		contentPane.add(form , BorderLayout.NORTH);
		
		control = new ControlPanel(this);
		contentPane.add(control, BorderLayout.SOUTH);
	}

}