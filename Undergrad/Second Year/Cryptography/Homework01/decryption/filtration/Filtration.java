package filtration;

public class Filtration {

		public static String GetFiltratedString(String textToEncrypt)
	{
			String encryptInitial = textToEncrypt.replaceAll("[^a-zA-Z]+", "");
			return encryptInitial.toUpperCase();
	}

	
}
