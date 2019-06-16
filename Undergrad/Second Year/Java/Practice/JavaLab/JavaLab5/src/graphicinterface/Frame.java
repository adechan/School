package graphicinterface;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JList;
import java.awt.FlowLayout;
import javax.swing.JTextField;
import javax.swing.JRadioButton;
import javax.swing.JButton;
import application.CatalogList;

public class Frame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private JPanel contentPane;
	private JTextField name;
	private JTextField pathDefinitionFile;
	private JTextField pathImageFile;
	private JTextField numberVertices;
	private JTextField numberNodes;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Frame frame = new Frame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Frame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 610, 502);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JPanel formPanel = new JPanel();
		contentPane.add(formPanel, BorderLayout.NORTH);
		
		name = new JTextField();
		name.setText("name");
		formPanel.add(name);
		name.setColumns(10);
		
		JRadioButton typeDirected = new JRadioButton("Directed");
		formPanel.add(typeDirected);
		
		JRadioButton typeSimple = new JRadioButton("Simple");
		formPanel.add(typeSimple);
		
		pathDefinitionFile = new JTextField();
		pathDefinitionFile.setText("path definition file");
		formPanel.add(pathDefinitionFile);
		pathDefinitionFile.setColumns(10);
		
		pathImageFile = new JTextField();
		pathImageFile.setText("path image file");
		formPanel.add(pathImageFile);
		pathImageFile.setColumns(10);
		
		numberVertices = new JTextField();
		numberVertices.setText(" number vertices");
		formPanel.add(numberVertices);
		numberVertices.setColumns(10);
		
		numberNodes = new JTextField();
		numberNodes.setText(" number nodes");
		formPanel.add(numberNodes);
		numberNodes.setColumns(10);
		
		JButton buttonAddGraph = new JButton("button add graph");
		formPanel.add(buttonAddGraph);
		
		JPanel controlPanel = new JPanel();
		FlowLayout flowLayout = (FlowLayout) controlPanel.getLayout();
		contentPane.add(controlPanel, BorderLayout.SOUTH);
		
		JButton saveButton = new JButton("save");
		controlPanel.add(saveButton);
		
		JButton loadButton = new JButton("load");
		controlPanel.add(loadButton);
		
		JButton openButton = new JButton("open");
		controlPanel.add(openButton);
		
		JButton listButton = new JButton("list");
		controlPanel.add(listButton);
		
		CatalogList catalogList = new CatalogList();
		contentPane.add(catalogList, BorderLayout.CENTER);
	}

}
