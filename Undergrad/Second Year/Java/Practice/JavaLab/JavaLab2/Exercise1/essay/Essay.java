package essay;
import java.time.LocalDate;

import project.Project;

/**
 * Class representing a type of project, essay.
 * @author Andreea Rindasu
 *
 */
public class Essay extends Project {

	private Topic topic;

	// constructor
	public Essay(String name, LocalDate deadline, Topic topic)
	{
		this.name = name;
		this.deadline = deadline;
		this.topic = topic;
	}
	
	// get topic
	public Topic getTopic() {
		return topic;
	}
	
	// set topic
	public void setTopic(Topic topic) {
		this.topic = topic;
	}
	
	@Override
	public String toString() {
		return super.toString() + "(" + this.topic.toString() + ")";
	}
	
	
}
