package locations;

import locationproperties.Payable;
import locationproperties.Visitable;

public class Museum extends Node implements Visitable, Payable{

	public Museum(String name) {
		super(name);
	}
	protected int openingHours;
	protected int entryFee;
	
	public int getOpeningHours() {
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
