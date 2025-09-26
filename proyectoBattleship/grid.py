from sprites import Sprites, pygame

class Grid:
    def __init__(self, screen: pygame.surface.Surface):
        self.rows = 10
        self.cols = 10
        self.cellSize = 45
        self.grid = [[0 for j in range(self.cols)] for i in range(self.rows)]
        self.sprite = Sprites.getSprites()
        self.screen = screen
        print(self.sprite)
    
    def printGrid(self):
        for row in range(self.rows):
            for col in range(self.cols):
                print(self.grid[row][col], end=" ")
            print()
    
    def drawGridH(self):
        i = 0
        lastCellValue = 0
        cellValue = 0
        for row in range(self.rows):
            for col in range(self.cols):
                cellValue = self.grid[row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
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
    
    def drawGridV(self): #IMPORTANTE: tiene que ignorar los barcos horizontales
        i = 0
        lastCellValue = 0
        cellValue = 0
        for col in range(self.cols):
            for row in range(self.rows):
                cellValue = self.grid[row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
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
                    
            

                