class Maze:
	def __init__(self):
		self.initialize_maze()
		
	def initialize_maze(self):
		self.current_maze = [
			[ '.', 'X', '.', '.', '.', 'X' ], 
			[ '.', '.', '.', 'X', '.', '.' ],
			[ '.', 'X', '.', '.', 'X', '.' ],
			[ '.', '.', '.', 'X', 'X', '.' ],
			[ '.', 'X', '.', '.', '.', '.' ],
			[ '.', '.', '.', '.', 'X', '.' ]
			]

	def initial_state(self):
		self.initial_maze = [
			[ '.', 'X', '.', '.', '.', 'X' ], 
			[ '.', '.', '.', 'X', '.', '.' ],
			[ '.', 'X', '.', '.', 'X', '.' ],
			[ '.', '.', '.', 'X', 'X', '.' ],
			[ '.', 'X', '.', '.', '.', '.' ],
			[ '.', '.', '.', '.', 'X', '.' ]
			]

	def is_cell_blocked(self, location):
		# Make sure location is in bounds
		if location[0] < 0 or location[1] >= len(self.current_maze[0]) or location[0] >= len(self.current_maze) or location[1] < 0:
			return True

		mark = self.current_maze[location[0]][location[1]]
		if mark != '.':
			return True
		else:
			return False

	def print_maze(self):
		for i in range(0, 6):
			print(' '.join(self.current_maze[i]))

	def mark(self, location, mark = '0'):
		self.current_maze[location[0]][location[1]] = mark

	# maze[5][5]
	def end(self):
		length = len(self.current_maze)
		return (length - 1, length - 1)

import random
class Agent:
	def __init__(self, maze):
		self.maze = maze
		self.__location = (0, 0)
		self.__path = [(0, 0)]
		self.maze.mark(self.location())

	def location(self):
		return self.__location

	# Get next possible move
	def next_move(self):
		directions = ['up', 'left', 'right', 'down']
		random.shuffle(directions)
		for direction in directions:
			if self.check_move(direction):
				return direction
		return 'back'
		
	def __set_location(self, loc):
		self.__location = loc
		self.__path.append(loc)
		self.maze.mark(self.location())

	# Convert direction to location in the maze
	def __location_from_direction(self, direction):
		if direction == 'up':
			return (self.__location[0] - 1, self.__location[1])

		elif direction == 'down':
			return (self.__location[0] + 1, self.__location[1])

		elif direction == 'left':
			return (self.__location[0], self.__location[1] - 1)

		elif direction == 'right':
			return (self.__location[0], self.__location[1] + 1)

		elif direction == 'back':
			self.__path.pop()
			loc = self.__path.pop()
			return loc

	# Check if the given move is valid
	def check_move(self, direction):
		loc = self.__location_from_direction(direction)
		return not self.maze.is_cell_blocked(loc)

	# Move in the direction
	def move(self, direction):
		loc = self.__location_from_direction(direction)
		self.__set_location(loc)