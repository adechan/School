package game;

import java.util.ArrayList;
import java.util.List;

public class Game 
{
    private Board board;
    
    private List<Player> players = new ArrayList<>();
    
    private Player winner = null;
    
    private int currentTurn = -1;
    
    private Thread playerThread = null;
    
    public Game()
    {
    }
    
    public void addPlayer(Player player) 
    {
        players.add(player);
        player.setGame(this);
    }
    
    public void setBoard(Board board)
    {
    	this.board = board;
    }
    
    public Board getBoard()
    {
    	return this.board;
    }
    
    public void setWinner(Player player)
    {
    	this.winner = player;
    }
    
    public synchronized void start()
    {
    	if (this.players.size() < 2) 
    		return;
    	
    	System.out.println("Game start");
    	while (this.winner == null || this.board.edgeCount() == 0)
    	{
    		System.out.println("Edges left: " + this.board.edgeCount());
    		Player currentPlayer = this.nextTurnPlayer();
    		System.out.println("Next turn: " + currentPlayer.getName());
    		
    		Thread thread = new Thread(currentPlayer);
    		
    		thread.start();
    		
    		try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
    	}
    	
    	if (this.winner != null)
    		System.out.println(this.winner.getName() + " won!");
    	else
    		System.out.println("Nobody won.");
    }
    
    private Player nextTurnPlayer()
    {
    	this.currentTurn++;
    	return this.players.get(this.currentTurn % this.players.size());
    }
    
    //Create getters and setters
    //Create the method that will start the game: start one thread for each player
}