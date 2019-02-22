package display;
import arraystrings.ArrayStrings;

public class Display {

	public static void display(int result)
	{
		String[] languages = ArrayStrings.getLanguages();
		System.out.println("Willy-nilly, this semester I will learn " + languages[result]);	
	}

}
