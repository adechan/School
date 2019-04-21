import java.sql.SQLException;

public class Main {
	
	public static void main(String[] args)
	{		
		try {
            PersonController persons = new PersonController();
            MovieController movies = new MovieController();
            
            // Create people and put their names into the persons database
            persons.create("Francis Ford Coppola");
            persons.create("Marlon Brando");
            persons.create("Al Pacino");
            Database.commit();
							
            // Insert the movie, "The Godfather" with director "Francis Ford Coppola", into the movies database.
            movies.create("The Godfather", persons.findByName("Francis Ford Coppola"));	
            
            // Print the tables
            persons.print();
            movies.print();
            
            // Finish transactions
            Database.commit();
            
        } catch (SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
		
		Database.closeConnection();
	}
}
