package locations;

import locationproperties.Payable;
import locationproperties.Visitable;

public class Museum extends Node implements Visitable, Payable{

	public Museum(String name) {
		super(name);
	}
	protected String openingHours;
	protected int entryFee;
	
	public String getOpeningHours() {
		return openingHours;
	}
	public int getEntryFee() {
		return entryFee;
	}
	
	@Override
	public String toString()
	{
		return "Museum: " + super.toString(); 
	}
}
