
public class BeerSong {

	public static void main(String[] args)
	{
		int beerNumber = 99;
		int initialBeerNumber = beerNumber;
		String word = "bottles";
		while (beerNumber > 0)
		{
			if (beerNumber == 1)
			{
				word = "bottle";
			}
			
			System.out.print(beerNumber + " " + word + " of beer on the wall. ");
			System.out.println(beerNumber + " " + word + " of beer.");
			System.out.print("Take one down.");
			System.out.print(" Pass it around.");
			beerNumber = beerNumber - 1;
			
			if (beerNumber != 0)
			{
				System.out.println(beerNumber + " " + word + " of beer on the wall. ");
			}
			else
			{
				System.out.println(" No more bottles of beer on the wall.");
				System.out.print("Go to the store and buy some more. ");
				System.out.print(initialBeerNumber + " " + word + " of beer on the wall. ");
			}
		}
	}
}	
