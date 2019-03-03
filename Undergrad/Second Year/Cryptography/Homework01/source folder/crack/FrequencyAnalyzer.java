package crack;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class FrequencyAnalyzer {
	
	private static String[][] commonSubstrings = {
			{"E", "T", "A", "O", "I", "N", "S"},
			{"TH", "ER", "ON", "AN", "HE", "IN", "ED", "ND", "HA", "ET", "EN", "ES", "OF", "OR", "NT", "EA", "TO"},
			{"THE", "AND", "THA", "ENT", "ION", "TIO", "FOR", "NDE"}
	};
		
	String cryptotext;
	
	public FrequencyAnalyzer(String cryptotext)
	{
		this.cryptotext = cryptotext;
	}
	
	public String getCryptoText()
	{
		return this.cryptotext;
	}
	
	public String crack(int substringLength)
	{
		String crackedText = this.cryptotext;		
		
		for (int i = 0; i < Math.min(commonSubstrings.length, substringLength); i++)
		{
			ArrayList<SubstringCounter> frequencyTable = this.getFrequencyTable(i + 1);
			String[] currentCommon = commonSubstrings[i];
			
			for (int j = 0; j < Math.min(frequencyTable.size(), currentCommon.length); j++)
			{
				
				crackedText = crackedText.replaceAll(frequencyTable.get(j).substring, currentCommon[j]);
			}
		}
		
		return crackedText;
	}
	
	public ArrayList<String> getSubstrings(int substringLength)
	{
		ArrayList<String> substrings = new ArrayList<String>();

		for (int i = 0; i < this.cryptotext.length() - substringLength + 1; i++)
		{
			String substring = this.cryptotext.substring(i, i + substringLength);
			if (!substrings.contains(substring))
				substrings.add(substring);	
		}
		
		return substrings;
	}
	
	public ArrayList<SubstringCounter> getFrequencyTable(int substringLength)
	{
		ArrayList<SubstringCounter> frequencyTable = new ArrayList<>();
		ArrayList<String> substrings = this.getSubstrings(substringLength);
		
		for (String substring : substrings)
			frequencyTable.add(new SubstringCounter(substring, this.countSubstringOccurences(substring), this.cryptotext.length()));
		
		Collections.sort(frequencyTable, Comparator.comparing(SubstringCounter::getCount).reversed());
		
		return frequencyTable;
	}
	
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
