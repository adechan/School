package test;
import test.dog;

public class main {

	public static void main(String[] args)
	{
		dog wolfy = new dog("Wolfy");
		wolfy.come();
		
		wolfy.bark();
		System.out.println("Wolfy barks like this : " + wolfy.DEFAULT_BARK);
		
		//dog.bark();
		System.out.println("Dog barks like this : " + dog.DEFAULT_BARK);
		
	}

}
