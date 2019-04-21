import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;

public class PersonController 
{
	Connection connection = null;
	
	public PersonController()
	{
		connection = Database.getConnection();
	}
	
    public void create(String name) throws SQLException 
    {
    	// Create a statement to be executed (? is a placeholder/parameter that will be replaced in the future)
        try (PreparedStatement pstmt = connection.prepareStatement("insert into persons (name) values (?)")) 
        {
        	// Replace the first ? with the string "name"
            pstmt.setString(1, name);
            
            // Execute the statement
            pstmt.executeUpdate();
        }
    }
    
    public Integer findByName(String name) throws SQLException 
    {
    	// Execute the select statement and return the id if there were any results
        try (Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select id from persons where name like '" + name + "'")) 
        {
            return rs.next() ? rs.getInt(1) : null;
        }
    }
    
    public String findById(int id) throws SQLException 
    { 
    	// Execute the select statement and return the name if there were any results
        try (Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select name from countries where id like '" + id + "'")) 
        {
            return rs.next() ? rs.getString(1) : null;
        }
    }	
    
    public void print() throws SQLException
    {
    	// Create a statement to be executed through the connection to the db
		Statement statement = connection.createStatement();
		
		// Get the results from executing the statement
        ResultSet results = statement.executeQuery("select * from persons");
        
        // Get information about the results (like number of columns, rows, etc).
        ResultSetMetaData metaData = results.getMetaData();
        
        int numberCols = metaData.getColumnCount();
        
        // Print the format of the table
        for (int i = 1; i <= numberCols; i++)
            System.out.print(metaData.getColumnLabel(i)+"\t\t");  

        System.out.println("\n-------------------------------------------------");

        // Print each row of the table
        while(results.next())
        {
            int id = results.getInt(1);
            String name = results.getString(2);
            System.out.println(id + "\t\t" + name + "\t\t");
        }
        
        results.close();
        statement.close();
    }
}