
public class ElectricGuitarTestDrive {

	public static void main(String[] args)
	{
		ElectricGuitar guitar = new ElectricGuitar();
		
		guitar.setBrand("Angelic");
		
		guitar.setNumOfPickups(5);
		
		guitar.setRockStarUsesit(true);
		
		System.out.println(guitar.getBrand());
		System.out.println(guitar.getNumOfPickups());
		System.out.println(guitar.getRockStarUsesit());
		
	}
}
