
public class Exercise {

	public static void main(String[] args)
	{
		String s1 = "Hej";
		String s2 = "Carl";
		s1 = "Hej" + " Carl";
		s1 = s1 + " Carl";
		s1 = s1 + " " + s2;
		s1 = s1 + " " + "username";
		System.out.println(s1);
	}
}
