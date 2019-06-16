
public class GoodDogTestDrive {

	public static void main(String[] args)
	{
		GoodDog one = new GoodDog();
		one.setSize(70);
		
		GoodDog two = new GoodDog();
		two.setSize(8);
		
		GoodDog three = new GoodDog();
		three.setSize(15);
		
		System.out.println("Dog one: " + one.getSize());
		System.out.println("Dog two: " + two.getSize());
		System.out.println("Dog three: " + three.getSize());

		one.bark();
		two.bark();
		three.bark();
	}
}
