package locationproperties;

public class Duration {

	protected int durationHours;
	protected int openingHours;
	protected int closingHours;
	
	public Duration(int openingHours, int closingHours)
	{
		this.openingHours = openingHours;
		this.closingHours = closingHours;
	}
}
