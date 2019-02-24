package project;

import java.time.LocalDate;

public abstract class Project {

	protected String name;
	protected LocalDate deadline;
	
	@Override
	public String toString() {
		return this.name.toString();
	}
}
