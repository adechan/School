package locations;

import locationproperties.Visitable;

public class Church extends Node implements Visitable {

	public Church(String name) {
		super(name);
	}

	protected String openingHours;
	
	public String getOpeningHours()
	{
		return openingHours;
	}
	
	@Override
	public String toString()
	{
		return "Church: " + super.toString(); 
	}
}
