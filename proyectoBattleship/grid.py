from sprites import Sprites, pygame

class Grid:
    def __init__(self, screen: pygame.surface.Surface):
        self.rows = 10
        self.cols = 10
        self.cellSize = 45
        self.grid = [[0 for j in range(self.cols)] for i in range(self.rows)]
        self.gridVSprites = [[0 for j in range(self.cols)] for i in range(self.rows)]
        self.gridHSprites = [[0 for j in range(self.cols)] for i in range(self.rows)]
        self.sprite = Sprites.getSprites()
        self.screen = screen
        print(self.sprite)
    
    def printGrid(self):
        for row in range(self.rows):
            for col in range(self.cols):
                print(self.grid[row][col], end=" ")
            print()

    def isInside(self, row, col):
        if row >= 0 and row < self.rows and col >=0 and col < self.cols:
            return True
        return False
    
    def drawGridH(self):
        i = 0
        lastCellValue = 0
        cellValue = 0
        for row in range(self.rows):
            for col in range(self.cols):
                cellValue = self.gridHSprites[row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
                #print(self.gridHSprites)
                cellSpace = pygame.Rect(col * self.cellSize + 47, row * self.cellSize + 542, self.cellSize + 2, self.cellSize + 2)

                if i < 6 and cellValue != 0 and cellValue == lastCellValue: #Entra en esta condicion para dibujar el barco horizontal completo
                    try:
                        self.screen.blit(self.sprite[0][cellValue][i], cellSpace)
                        i += 1
                    except:
                        pass
                elif cellValue != 0: #Entra en esta condicion si se termino de dibujar el barco, para reiniciar el dibujado del siguiente
                    lastCellValue = cellValue
                    i = 0
                    try:
                        self.screen.blit(self.sprite[0][cellValue][i], cellSpace,)
                        i += 1
                    except:
                        pass
                else:
                    i = 0 # usar j como contador de los sprites verticales
    
    def drawGridV(self): #Funcion de recorrido vertical de matriz para dibujado vertical
        i = 0
        lastCellValue = 0
        cellValue = 0
        for col in range(self.cols):
            for row in range(self.rows):
                cellValue = self.gridVSprites[row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
                cellSpace = pygame.Rect(col * self.cellSize + 47, row * self.cellSize + 542, self.cellSize + 2, self.cellSize + 2)

                if i < 6 and cellValue != 0 and cellValue == lastCellValue: #Entra en esta condicion para dibujar el barco horizontal completo
                    try:
                        self.screen.blit(self.sprite[1][cellValue][i], cellSpace)
                        i += 1
                    except:
                        pass
                elif cellValue != 0: #Entra en esta condicion si se termino de dibujar el barco, para reiniciar el dibujado del siguiente
                    lastCellValue = cellValue
                    i = 0
                    try:
                        self.screen.blit(self.sprite[1][cellValue][i], cellSpace,)
                        i += 1
                    except:
                        pass
                else:
                    i = 0 # usar j como contador de los sprites verticales
                    
            

                