package encryption;
import java.util.ArrayList;
import java.util.Random;

public class Encryption {

	ArrayList<Character> key;
	
	public static String encryptText(String text, ArrayList<Character> key)
	{
		
		return text;
	}
	
	public static void shuffleArray(ArrayList<Character> array)
	{
		Random random = new Random();
		for (int i = array.size(); i > 0; i--)
		{
			int index = random.nextInt(i + 1);
			char a = array.get(index);
			array.set(index, array.get(i));
			array.set(i, a);
		}
	}
}
