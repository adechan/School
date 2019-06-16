
public class Duck extends Bird {

	private String colourFeather;
	private int times;
	
	public void setColour(String colour)
	{
		colourFeather = colour;
	}
	
	public String getColour()
	{
		return colourFeather;
	}
	
	private int countSoundMaking()
	{
		times++;
		return times;
	}
	
	public void soundMaking()
	{
		if (countSoundMaking() > 3)
		{
			System.out.println("I quack'ed too much! I'm tired now..");
		}
		else 
		{
			System.out.println("Quack! Quack!");
		}
	}
}
