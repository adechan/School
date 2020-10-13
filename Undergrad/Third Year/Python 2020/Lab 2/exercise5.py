# Write a function that receives as parameter a matrix
# and will return the matrix obtained by replacing all
# the elements under the main diagonal with 0 (zero).

def replaceUnderDiagonal(matrix):
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(0, rows):
        for j in range(0, columns):
            if i > j:
                matrix[i][j] = 0

    return matrix


print(replaceUnderDiagonal([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
