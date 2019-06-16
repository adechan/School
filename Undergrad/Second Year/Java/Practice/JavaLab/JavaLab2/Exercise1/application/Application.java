package application;
import java.time.LocalDate;
import project.Project;

/**
 * Class representing a type of project, application.
 * @author Andreea Rindasu
 *
 */
public class Application extends Project {


	private Language language;
	
	// constructor
	public Application(String name, LocalDate deadline, Language language)
	{
		this.name = name;
		this.deadline = deadline;
		this.language = language;
	}
	
	// get language
	public Language getLanguage() {
		return language;
	}
	
	// set language
	public void setLanguage(Language language) {
		this.language = language;
	}
	
	@Override
	public String toString() {
		return super.toString() + "(" + this.language.toString() + ")";
	}
}
