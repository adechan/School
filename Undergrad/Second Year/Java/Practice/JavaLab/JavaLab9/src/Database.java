import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * A class describing a context through which the
 * communication with a database takes place.
 * SQL statements are executed and results are returned
 * within the context of a connection.
 * An application may create multiple connections (to the
 * same database or to different databases).
 * @author Andreea Rindasu
 *
 */
public class Database {
	
	// The URL is of the form jdbc:databaseDriver:pathToDB
	// Since Movies is in the working directory of the program, we need only write Movies 
    private static final String URL = "jdbc:derby:Movies";
    private static final String USER = "dba";
    private static final String PASSWORD = "sql";
    
    private static Connection connection = null;
    
    private Database() { }
    
    public static Connection getConnection() {
        if (connection == null) {
            createConnection();
        }
        
        return connection;
    }
    
    // create connection
	private static void createConnection() {
		try
		{
            //Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
            
            // Connect to java database via the URL in our working folder
			connection = DriverManager.getConnection(URL);
			
			// Turn off auto commit (which commits after each statement is executed)
			// transaction control
			connection.setAutoCommit(false);
		}
		
		catch(SQLException e) 
		{
			 System.err.println("SQLException: " + e);
		}
//		} catch (ClassNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
	}

	// close connection
	public static void closeConnection() {
		try 
		{
			connection.close();	
			connection = null;
		}
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
	// update the data base
	public static void commit() throws SQLException
	{
		connection.commit();
	}
		
	public static void rollback()
	{
		try {
			connection.rollback();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	} 
}