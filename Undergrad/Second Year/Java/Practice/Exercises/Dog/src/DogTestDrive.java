
public class DogTestDrive {

	public static void main(String[] args)
	{
		Dog dog1 = new Dog();
		dog1.bark();
		dog1.name = "Bart";
		
		// now make a Dog array
		
		Dog[] myDogs = new Dog[3];
		myDogs[0] = new Dog();
		myDogs[1] = new Dog();
		myDogs[2] = new Dog();
		
		// now access the Dogs using the array 
		// references
		
		myDogs[0].name = "Fred";
		myDogs[1].name = "Marge";
		myDogs[2] = dog1;
		
		System.out.print("last dog's name is ");
		System.out.println(myDogs[2].name);
		
		// now loop through the array
		// and tell all dogs to bark
		
		int x = 0;
		
		while (x < myDogs.length)
		{
			myDogs[x].bark();
			x = x + 1;
		}
	}
}
