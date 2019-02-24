package student;

import project.Project;
import java.util.ArrayList;

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
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public int getYearOfStudy() {
		return yearOfStudy;
	}
	public void setYearOfStudy(int yearOfStudy) {
		this.yearOfStudy = yearOfStudy;
	}

	public void setPreferences(Project... projects) {
		for (Project project : projects)
			this.preferences.add(project);
	}
	
	public ArrayList<Project> getPreferences()
	{
		return this.preferences;
	}
	
	@Override
	public String toString() {
		return this.name.toString();
	}
}
