package application;
import java.time.LocalDate;

import project.Project;

public class Application extends Project {


	private Language language;
	
	// constructor
	public Application(String name, LocalDate deadline, Language language)
	{
		this.name = name;
		this.deadline = deadline;
		this.language = language;
	}
	
	public Language getLanguage() {
		return language;
	}
	
	public void setLanguage(Language language) {
		this.language = language;
	}
	
	@Override
	public String toString() {
		return super.toString() + "(" + this.language.toString() + ")";
	}
}
