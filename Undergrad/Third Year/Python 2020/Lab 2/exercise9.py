# Write a function that receives as paramer a matrix
# which represents the heights of the spectators in
# a stadium and will return a list of tuples (line, column)
# each one representing a seat of a spectator which can't
# see the game. A spectator can't see the game if there is
# at least one taller spectator standing in front of him.
# All the seats are occupied. All the seats are at the same
# level. Row and column indexing starts from 0, beginning
# with the closest row from the field.

# returns: row, seat of spectator

def getPeopleWhoCantSee(stadium):
    rows = len(stadium)
    columns = len(stadium[0])

    cantSee = []
    for i in range(1, rows):
        for j in range(0, columns):
           for k in range(0, i):
               if stadium[k][j] >= stadium[i][j]:
                   # print("i = ", i, "j = ", j, "k = ", k)
                   cantSee.append((i, j))
                   break

    return cantSee


list = [[1, 2, 3, 2, 1, 1], [2, 4, 4, 3, 7, 2], [5, 5, 2, 5, 6, 4], [6, 6, 7, 6, 7, 5]]
print(getPeopleWhoCantSee(list))