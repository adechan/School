/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package app;

import entity.Movie;
import entity.Person;
import java.util.Scanner;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

import controllers.MovieController;
import controllers.PersonController;

/**
 *
 * @author Andreea Rindasu
 */
public class MovieManager {
    
    private MovieController movieController;
    private PersonController personController;
    
    static final EntityManagerFactory emf = Persistence.createEntityManagerFactory("MoviesPU");

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Input command:");
            String command = scanner.nextLine();
            if (command.equals("exit")) break;
            String[] params = command.trim().split("\\s+");
            switch (params[0]) {
                case "create-person":
                    createPerson(params[1]); //the person name
                    break;
                case "create-movie":
                    createMovie(params[1], params[2]); //the album name and the director
                    break;
                case "list-movies":
                    listMovies(params[1]); //the director name
                    break;				
            }
        }
    }
    private void createPerson(String personName) {
        this.personController.create(new Person(personName));
    }
    
    private void createMovie(String movieName, String directorName) {
    	this.movieController.create(new Movie(directorName));
    }
    
    private void listMovies(String directorName) {
    }
    
    public static void main(String args[]) {
        new MovieManager().run();
    }
}
