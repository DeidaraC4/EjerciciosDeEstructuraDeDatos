class Grid:
    def __init__(self):
        self.rows = 10
        self.cols = 10
        self.cellSize = 45
        self.grid = [[0 for j in range(self.cols)] for i in range(self.rows)]
    
    def printGrid(self):
        for row in range(self.rows):
            for col in range(self.cols):
                print(self.grid[row][col], end=" ")
            print()