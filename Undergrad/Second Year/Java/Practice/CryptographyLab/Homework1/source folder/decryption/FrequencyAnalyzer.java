package decryption;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/**
 * This class checks the letter frequency and decodes the cryptotext.
 * @author Andreea Rindasu
 *
 */
public class FrequencyAnalyzer {
	
	private static String[][] commonSubstrings = {
			{"E", "T", "A", "O", "I", "N", "S"},
			{"TH", "ER", "ON", "AN", "HE", "IN", "ED", "ND", "HA", "ET", "EN", "ES", "OF", "OR", "NT", "EA", "TO"},
			{"THE", "AND", "THA", "ENT", "ION", "TIO", "FOR", "NDE"}
	};
	
	/* private static String[] commonWords = {
			"ATTRACT",
			"OSSEOUS",
			"BECAUSE",
			"WHICH",
			"IMPORTANT",
			"WOMAN",
			"DIFFERENT",
			"LITTLE",
			"LOOK",
			"COMPANY",
			"GOVERNMENT",
			"PROBLEM",
	};*/
	
	/*private static String[] commonSeparators = {
			"THESE",
			"THERE",
			"THEN",
			"THEY",
			"THEM",
			"THE",
	};*/
		
	private String cryptotext = "";
	private String decodedText = "";
	
	// first Character is the encrypted letter
	// second Character is decrypted letter
	// map takes a key and outputs a value
	private Map<Character, Character> decoderKey;
	
	public FrequencyAnalyzer(String cryptotext)
	{
		this.cryptotext = cryptotext;
		this.decodedText = this.cryptotext;
		this.decoderKey = new HashMap<>();
	}
	
	public String getCryptoText()
	{
		return this.cryptotext;
	}
	
	/**
	 * This method adds to the map (encrypted letter, decrypted letter) so we can use it in decryption.
	 * @param key: the encrypted letter
	 * @param to: the decrypted letter
	 */
	private void addKey(String key, String to)
	{
		// For each letter in key, add the corresponding letter from "to" as
		// a way to decode key[i] -> to[i]
		for (int i = 0; i < Math.min(key.length(), to.length()); i++)
			this.addKey(key.charAt(i), to.charAt(i));
	}
	
	// OVERLOADING
	/**
	 * In case we know what the encrypted string and the decrypted string is, this method adds to the map
	 * the remaining different letters pairs (it doesn't add duplicates)
	 * @param key: the encrypted letter
	 * @param to: the decrypted letter
	 */
	private void addKey(char key, char to)
	{
		if (this.decoderKey.get(key) != null) return;
		
		// decoderKey maps an encrypted letter to its decrypted output letter.
		this.decoderKey.put(key, to);
		System.out.println("Added to decoder: " + key + "->" + to);
		
		// We want to decode "H" to "W" for example. string = HWERE
		// If we simply replaced all W's with H's, then we would have 
		// HHERE as the decoded text instead of WHERE.
		
		// Thus we have to swap all the H's and W's. 
		// This means we need a temporary value that  is not already in the text. 
		this.decodedText = this.decodedText.replaceAll(String.valueOf(to), "1");
		this.decodedText = this.decodedText.replaceAll(String.valueOf(key), String.valueOf(to));
		this.decodedText = this.decodedText.replaceAll("1", String.valueOf(key));
	}
	
	/**
	 * This method decodes the solo letters.
	 * It makes a map with the encrypted letter and decrypted letter.
	 */
	private void decodeMonograms()
	{
		// Get the frequency table of all monograms in the cryptotext
		ArrayList<SubstringCounter> frequencyTable = this.getFrequencyTable(1);
		String[] currentCommon = commonSubstrings[0];

		// Decode first 5 most frequent letters as "E", "T", "A", "O", "I" respectively.
		for (int i = 0; i < 4; i++)
			this.addKey(frequencyTable.get(i).getSubstring().charAt(0), currentCommon[i].charAt(0));
	}
	
	/**
	 * This method decodes the double letters.
	 * It makes a map with the encrypted letter and decrypted letter.
	 */
	private void decodeDigrams()
	{
		// Get the frequency table of all digrams in the cryptotext
		ArrayList<SubstringCounter> frequencyTable = this.getFrequencyTable(2);
		String[] currentCommon = commonSubstrings[1];

		// Add the most common digram in the frequency table and consider it to be the most
		// common digram "TH". 
		// Use this as a way to decode the key.
		this.addKey(frequencyTable.get(0).getSubstring(), currentCommon[0]);
	}
	
	/**
	 * This method decodes the triple letters.
	 * It makes a map with the encrypted letter and decrypted letter.
	 */
	private void decodeTrigrams()
	{
		ArrayList<SubstringCounter> frequencyTable = this.getFrequencyTable(3);
		String[] currentCommon = commonSubstrings[2];

		this.addKey(frequencyTable.get(0).getSubstring(), currentCommon[0]);
	}
	
	/*private void guessCommonWords()
	{
		for (String word : commonWords)
		{
			// Look for the current word in the current version of the decrypted text
			int i = this.decodedText.indexOf(word);
			if (i != -1)
			{
				// If we find a common word in the decrypted text, then we got lucky
				// Compare original cryptotext and current decrypted text to find letters
				// are new. E.g.: W
				String cryptoword = this.cryptotext.substring(i, i + word.length());
				String decryptedWord = this.decodedText.substring(i, i + word.length());
				System.out.println("Found common word: " + cryptoword + "->" + decryptedWord);
				this.addKey(cryptoword, word);	
			}
		}
	}*/
	
	/*private void guessSeparators()
	{
		for (String separator : FrequencyAnalyzer.commonSeparators)
		{
			int i = this.decodedText.indexOf(separator);
			while (i != -1)
			{
				i += separator.length();
				for (String word : commonWords)
				{
					String decryptedWord = this.decodedText.substring(i, i + word.length());
					if (word.equals(decryptedWord))
					{
						String cryptoword = this.cryptotext.substring(i, i + word.length());
						System.out.println("Found common word: " + cryptoword + "->" + decryptedWord);
						this.addKey(cryptoword, word);	
					}
				}

				i = this.decodedText.indexOf(separator, i);
			}
		}
	}*/
	
	public String crack()
	{
		// Use frequency analysis to decode the most common english letters
		this.decodeMonograms();
		
		// Then the most common english digrams "TH", "HE", etc
		this.decodeDigrams();
		
		// Then trigrams, in particular "THE"
		this.decodeTrigrams();
		
		// Look for separator words such as "THE"
		// then search for words occuring after "THE" as a 
		// way to further decrypt the key.
		// this.guessSeparators();
		
		// From here we could randomly permute the unsolved part of the key
		// and see if we can find common words such as "hello" and so on.
		// We could potentially do this until the key is "solved"
		return this.decodedText;
	}
	
	/**
	 * @param substringLength
	 * @return an arrayList of substrings
	 */
	public ArrayList<String> getSubstrings(int substringLength)
	{
		ArrayList<String> substrings = new ArrayList<String>();

		// For each index of the cryptotext, create a substring of the given length starting at i
		// This results in all possible substrings of cryptotext.
		for (int i = 0; i < this.cryptotext.length() - substringLength + 1; i++)
		{
			String substring = this.cryptotext.substring(i, i + substringLength);
			if (!substrings.contains(substring))
				substrings.add(substring);	
		}
		
		return substrings;
	}
	
	/**
	 * This method gets all the substrings of the given legnth, and then calculate how many times
	 * each substring occurs in the cryptotext.
	 * @param substringLength
	 * @return an arrayList of frequency table
	 */
	public ArrayList<SubstringCounter> getFrequencyTable(int substringLength)
	{
		ArrayList<SubstringCounter> frequencyTable = new ArrayList<>();
		ArrayList<String> substrings = this.getSubstrings(substringLength);
		
		for (String substring : substrings)
			frequencyTable.add(new SubstringCounter(substring, this.countSubstringOccurences(substring), this.cryptotext.length()));
		
		// Sort the resulting table so that the most frequent substring is first, and so on.
		Collections.sort(frequencyTable, Comparator.comparing(SubstringCounter::getCount).reversed());
		
		return frequencyTable;
	}
	
	// Count the number of times a given substring occurs in cryptotext.
	private int countSubstringOccurences(String substring)
	{
		int count = -1;
		int next = -1;
				
		while (true)
		{
			count++;
			next = this.cryptotext.indexOf(substring, next + 1);
			if (next == -1)
				break;
		}
		
		return count;
	}
}
