import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

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
    
	private static void createConnection() {
		try
		{
			// idk what this does, maybe nothing
            //Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
            
            // Connect to java database via the URL.
			connection = DriverManager.getConnection(URL);
			
			// Turn off auto commit (which commits after each statement is executed)
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