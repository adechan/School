package sum;

public class Sum {

	private static int numDigits(int number)
	{
		int digitCount = 0;
		while (number != 0)
		{
			digitCount ++;
			number = number / 10;
		}
		
		return digitCount;
	}
	
	private static int sumDigits(int number)
	{
		int sum = 0;
		while (numDigits(number) > 0)
		{
			sum += number % 10;
			number = number / 10;
		}
		return sum;
	}
	
	
	public static int compute(int result)
	{		
		int sum = 0;
		int digits = numDigits(result);
		while (digits > 1)
		{
			sum = sumDigits(result);
			digits = numDigits(sum);
			result = sumDigits(result);
			// System.out.println("The sum is: " + sum);
		}
		
		return result;
	}

}