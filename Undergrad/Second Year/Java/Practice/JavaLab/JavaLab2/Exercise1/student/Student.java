package student;

import project.Project;
import java.util.ArrayList;

/**
 * Class representing students.
 * @author Andreea Rindasu
 *
 */
public class Student {
	private String name;
	private int yearOfStudy;
	private ArrayList<Project> preferences; 
	
	// constructor
	public Student(String name, int yearOfStudy)
	{
		this.name = name;
		this.yearOfStudy = yearOfStudy;
		this.preferences = new ArrayList<Project>();
	}
	
	// get name
	public String getName() {
		return name;
	}
	
	// set name
	public void setName(String name) {
		this.name = name;
	}
	
	// get year of study
	public int getYearOfStudy() {
		return yearOfStudy;
	}
	
	// set year of study
	public void setYearOfStudy(int yearOfStudy) {
		this.yearOfStudy = yearOfStudy;
	}

	// function for setting the preferences for each student
	public void setPreferences(Project... projects) {
		for (Project project : projects)
		{
			if (!this.preferences.contains(project))
				this.preferences.add(project);
		}
	}
	
	// function that gets preferences for each student 
	public ArrayList<Project> getPreferences()
	{
		return this.preferences;
	}
	
	@Override
	public String toString() {
		return this.name.toString();
	}
	
	// OPTIONAL
	// two objects will be considered equal if and only if all their fields match
	// The problem should not allow adding the same student, or project twice.
	@Override
	public boolean equals(Object obj) {
		
		Student other = (Student)obj;
		if (other == null) 
			return false;
		
		return this.name.equals(other.name) && this.yearOfStudy == (other.yearOfStudy);
	}
}
