package essay;
import java.time.LocalDate;

import project.Project;

public class Essay extends Project {

	private Topic topic;

	// constructor
	public Essay(String name, LocalDate deadline, Topic topic)
	{
		this.name = name;
		this.deadline = deadline;
		this.topic = topic;
	}
	
	public Topic getTopic() {
		return topic;
	}
	
	public void setTopic(Topic topic) {
		this.topic = topic;
	}
	
	@Override
	public String toString() {
		return super.toString() + "(" + this.topic.toString() + ")";
	}
	
	
}
