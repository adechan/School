from maze import Maze, Agent

def main():
	maze = Maze()
	agent = Agent(maze)

	while (agent.location() != maze.end()):
		maze.print_maze()
		loc = agent.location()
		next_move = agent.next_move()
		print('agent moves from: {} -> {}'.format(loc, next_move))
		agent.move(next_move)

	maze.print_maze()

if __name__ == "__main__":
	main()