package problem;
import project.Project;
import student.Student;

import java.util.ArrayList;

public class Problem {

	private ArrayList<Student> students;
	private ArrayList<Project> projects;
	
	private ArrayList<Student> solvedStudents;
	private ArrayList<Project> solution;
	
	// constructor
	public Problem(Project... projects)
	{
		this.students = new ArrayList<Student>();
		this.projects = new ArrayList<Project>();
		
		this.solvedStudents = new ArrayList<Student>();
		this.solution = new ArrayList<Project>();
				
		this.setProjects(projects);
	}
 
	// solve the problem of allocating students to projects
	public void solveProblem()
	{	
		/*
		 * for each project we check the number of
		 * preferences for each student 
		 *  
		 * it prioritizes the students with fewer preferences
		 */
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
				// allocate a project to the minStudent 
				// and then add him to the solvedStudents
				this.solvedStudents.add(minStudent);
				
				// remove him from the array so we can allocate
				// to the other students a project 
				this.students.remove(minStudent);
				
				// we add the project to solution 
				// so we don't allocate it to someone else
				this.solution.add(project);
			}
		}
	}

	
	// every student we need to allocate a project to
	public void setStudents(Student... students)
	{
		for (Student student : students)
			this.students.add(student);
	}
	
	// all possible projects
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
