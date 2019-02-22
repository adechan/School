package calcul;

public class Calcul {
	
	public static int calcul()
	{
		int n = (int) (Math.random() * 1000000);
		int result = n * 3;
		
		// parseInt(String s, int radix)
		// radix = 10 ~> decimal integer
		
		// 10101 (2) = 21 (10)
		result += Integer.parseInt("10101", 2);
		// FF (16) = 255 (10)
		result += Integer.parseInt("FF", 16);
		result *= 6;
		return result;
	}
	
}
