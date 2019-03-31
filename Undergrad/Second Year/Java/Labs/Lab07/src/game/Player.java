package game;

import graphs.Edge;
import graphs.Graph;

public class Player implements Runnable {
	
    private String name;
    private Game game;
    private Graph graph;
    
    public int THINKING_TIME = 500;
    
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
        
        if (board.isEmpty())
        	return false;
        
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

	@Override
	public void run() 
	{
		try {
			this.play();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		synchronized(this.game) 
		{
			this.game.notifyAll();
		}
	}
	
	public String getName()
	{
		return this.name;
	}
}