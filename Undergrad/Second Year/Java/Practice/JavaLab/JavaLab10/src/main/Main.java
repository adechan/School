package main;


import java.sql.SQLException;

import controllers.MovieController;
import controllers.PersonController;
import database.Database;

public class Main {
	
	public static void main(String[] args)
	{		
		try {
            PersonController persons = new PersonController(null);
            MovieController movies = new MovieController(null);
            
            // Create people and put their names into the persons database
            persons.create("Francis Ford Coppola");
            persons.create("Marlon Brando");
            persons.create("Al Pacino");
            // updates data base
            Database.commit();
							
            // Insert the movie, "The Godfather" with director "Francis Ford Coppola"
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
