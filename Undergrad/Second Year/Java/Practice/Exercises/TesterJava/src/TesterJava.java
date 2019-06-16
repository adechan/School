import java.awt.Rectangle;

public class TesterJava 
{

	public static void main(String[] args)
	{
		Rectangle box = new Rectangle(5, 10, 20, 30);
		// Move rectangle
		box.translate(15, 25);
		// print the info about the moved rectangle 
		System.out.println("x: ");
		System.out.println(box.getX());
		System.out.println("Expected: 20");
		System.out.println("y: ");
		System.out.println(box.getY());
		System.out.println("Expected: 35");
	}
	
}
