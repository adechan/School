package crack;

public class SubstringCounter {

	String substring;
	int count;
	int stringLength; 
	
	public SubstringCounter()
	{
		this.substring = "";
		this.count = 0;
	}
	
	public SubstringCounter(String substring, int count, int stringLength)
	{
		this.substring = substring;
		this.count = count;
		this.stringLength = stringLength;
	}
	
	public int getCount()
	{
		return this.count;
	}
	
	public int getStringLength()
	{
		return this.stringLength;
	}
	
	public String getSubstring()
	{
		return this.substring;
	}
	
	@Override
	public boolean equals(Object obj)
	{
		SubstringCounter other = (SubstringCounter)obj;
		if (other == null) 
			return false;
		
		return this.substring.equals(other.substring) && this.count == other.count;
	}
	
	@Override
	public String toString()
	{
		return this.substring + ": " + 100 * (float)this.count / (this.stringLength / this.substring.length());
	}
}
