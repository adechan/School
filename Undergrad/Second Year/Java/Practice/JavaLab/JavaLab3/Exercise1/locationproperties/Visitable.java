package locationproperties;

public interface Visitable {

	public int getOpeningHours();
	
	default void visitableHours()
	{
		double openingHours = 09.30;
		double closingHours = 20.00;
	}
	
	public static Duration getVisitingDuration(int openingHours, int closingHours)
	{
		Duration durationVisiting = new Duration(openingHours, closingHours);
		durationVisiting.durationHours = durationVisiting.closingHours - durationVisiting.openingHours;

		return durationVisiting;
		
	}
}
