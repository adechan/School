package locations;

import locationproperties.Payable;

public class Hotel extends Node implements Payable{

	public Hotel(String name) {
		super(name);
	}

	protected int entryFee;

	public int getEntryFee()
	{
		return entryFee;
	}
	
	@Override
	public String toString()
	{
		return "Hotel: " + super.toString(); 
	}
}
