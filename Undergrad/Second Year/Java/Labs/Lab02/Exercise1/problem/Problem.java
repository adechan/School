package problem;
import project.Project;
import student.Student;

import java.util.ArrayList;

public class Problem {

	private ArrayList<Student> students;
	private ArrayList<Project> projects;
	
	private ArrayList<Student> solvedStudents;
	private ArrayList<Project> solution;
	
	public Problem(Project... projects)
	{
		this.students = new ArrayList<Student>();
		this.projects = new ArrayList<Project>();
		
		this.solvedStudents = new ArrayList<Student>();
		this.solution = new ArrayList<Project>();
				
		this.setProjects(projects);
	}
 
	public void solveProblem()
	{	
		for (Project project: projects)
		{
			Student minStudent = null;
			for (Student student : students)
			{
				if (student.getPreferences().contains(project))
				{
					if (minStudent == null || 
						student.getPreferences().size() > minStudent.getPreferences().size())
					{
						minStudent = student;
					}
				}
			}
			
			if (minStudent != null)
			{
				this.solvedStudents.add(minStudent);
				this.students.remove(minStudent);
				this.solution.add(project);
			}
		}
	}

	
	public void setStudents(Student... students)
	{
		for (Student student : students)
			this.students.add(student);
	}
	
	public void setProjects(Project... projects)
	{
		for (Project project : projects)
			this.projects.add(project);
	}
	
	@Override
	public String toString() {
		String result = "";
		for (int i = 0; i < this.solution.size(); i++)
		{
			result += solvedStudents.get(i).toString() + ": " + 
					solution.get(i).toString() + '\n';
		}
		return result;	
	}
}
