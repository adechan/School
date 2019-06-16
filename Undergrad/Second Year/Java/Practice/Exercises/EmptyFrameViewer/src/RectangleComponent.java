import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import javax.swing.JComponent;

// a component that draws two rectangles
public class RectangleComponent extends JComponent
{
	public void paintComponent(Graphics g)
	{
		// recover Graphics2D
		Graphics2D g2 = (Graphics2D) g;
		// construct rectangle and draw it
		Rectangle box = new Rectangle(5, 10, 20, 30);
		g2.draw(box);
		
		// move rectangle 15 units to the right and
		// 25 units down
		box.translate(15, 25);
		// draw moved rectangle
		g2.draw(box);
		
	}
}
