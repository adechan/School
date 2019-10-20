package locations;

import locationproperties.Classifiable;
import locationproperties.Payable;
import locationproperties.Visitable;

public class Restaurant extends Node implements Payable, Visitable, Classifiable{

	public Restaurant(String name) {
		super(name);
	}
	protected int openingHours;
	protected int entryFee;
	protected int rank;
	
	public int getOpeningHours() {
		return openingHours;
	}
	public int getEntryFee() {
		return entryFee;
	}
	public int getRank() {
		return rank;
	}
	
	@Override
	public String toString()
	{
		return "Restaurant: " + super.toString(); 
	}
}