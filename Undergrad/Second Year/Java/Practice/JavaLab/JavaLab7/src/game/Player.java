package game;

import graphs.Edge;
import graphs.Graph;

/**
 * A class describing a Player.
 * Each player will have a name and their own instance of a 
 * graph object. This class will implement the Runnable interface. 
 * In the run method the player will repeatedly extract one edge from 
 * the board. 
 * @author Andreea Rindasu
 *
 */
public class Player implements Runnable {
	
    private String name;
    private Game game;
    private Graph graph;
    
    public int THINKING_TIME = 400;
    
    public Player(String name)
    {
    	this.name = name;
    	this.game = null;
    	this.graph = null;
    }
    
    public void setGame(Game game)
    {
    	this.game = game;
    	this.graph = new Graph(game.getBoard().nodeCount());
    }

    private boolean play() throws InterruptedException 
    {
		System.out.println("Playing...");

        Board board = this.game.getBoard();
        
        if (board.edgeCount() <= 0)
        	return false;
        
        // Causes the currently executing thread to temporarily cease execution
        System.out.println(this.name + ": thinking...");
        Thread.sleep(THINKING_TIME);
        
        System.out.println(this.name + ": grabbing an edge");
        
        Edge newEdge = board.extract();
        
        if (newEdge != null)
        	this.graph.addEdge(newEdge);
        
        if (this.graph.isSpanningTree()) 
        	this.game.setWinner(this);
        
        return true;
	}
    // implement the run() method, that will repeatedly extract edges
    // implement the toString() method

    // code executed by thread
	@Override
	public void run() 
	{
		try {
			this.play();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		// specify whose lock we are using
		// it notifys all the threads that are waiting on that object
		synchronized(this.game) 
		{
			// wakes up all threads that are waiting on the object's monitor
			// after thread is done working, it tells game that he can wake up now
			// and he can go to next player 
			this.game.notifyAll();
		}
	}
	
	public String getName()
	{
		return this.name;
	}
}