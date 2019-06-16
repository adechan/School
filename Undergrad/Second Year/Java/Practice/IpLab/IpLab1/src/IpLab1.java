
public class IpLab1 {

	public static void main(String[] args)
	{
		Animal rata = new Duck();
		rata.isPluricelular();
		rata.soundMaking();
		
		Duck duck1 = new Duck();
		duck1.setColour("Red");
		System.out.println("I am a " + duck1.getColour() + " duck");
		
		
		Animal duck2 = new Duck(); 
		duck2.soundMaking();
		duck2.soundMaking();
		duck2.soundMaking();
		duck2.soundMaking();
		duck1.soundMaking();
		
		Bird papagal = new Parrot();
		papagal.isPluricelular();
		papagal.soundMaking();
		((Parrot) papagal).fly();
		((Parrot) papagal).fly(5);
		
	}
}
