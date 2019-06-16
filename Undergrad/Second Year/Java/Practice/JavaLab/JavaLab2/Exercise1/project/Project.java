package project;

import java.time.LocalDate;

/**
 * Abstract class representing different type of projects.
 * @author Andreea Rindasu
 *
 */
public abstract class Project {

	protected String name;
	protected LocalDate deadline;
	
	@Override
	public String toString() {
		return this.name.toString();
	}
	
	// OPTIONAL
	// two objects will be considered equal if and only if all their fields match
	// The problem should not allow adding the same student, or project twice.
	@Override
	public boolean equals(Object obj) {
		
		Project other = (Project)obj;
		if (other == null)
			return false;
		
		return this.name.equals(other.name) && this.deadline.equals(other.deadline);
	}
}
