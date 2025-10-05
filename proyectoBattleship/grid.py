from sprites import Sprites, pygame

class Grid:
    def __init__(self, screen: pygame.surface.Surface):
        self.rows = 10
        self.cols = 10
        self.cellSize = 45
        self.grid = [[[0 for j in range(self.cols)] for i in range(self.rows)] for k in range(2)]
        self.gridVSprites = [[[0 for j in range(self.cols)] for i in range(self.rows)] for k in range(2)]
        self.gridHSprites = [[[0 for j in range(self.cols)] for i in range(self.rows)] for k in range(2)]
        self.gridRadar = [[[0 for j in range(self.cols)] for i in range(self.rows)] for k in range(2)]
        self.sprite = Sprites.getSprites()
        self.spriteAssert = pygame.transform.scale(pygame.image.load("assert.png").convert_alpha(), (45, 45))
        self.spriteFall = pygame.transform.scale(pygame.image.load("fall.png").convert_alpha(), (45, 45))
        self.spriteExplotion = pygame.transform.scale(pygame.image.load("explotion.png").convert_alpha(), (45, 45))
        self.spriteDodge = pygame.transform.scale(pygame.image.load("dodge.png").convert_alpha(), (45, 45))
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
    
    def drawGridH(self, turno):
        i = 0
        lastCellValue = 0
        cellValue = 0
        for row in range(self.rows):
            for col in range(self.cols):
                cellValue = self.gridHSprites[turno][row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
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
    
    def drawGridV(self, turno): #Funcion de recorrido vertical de matriz para dibujado vertical
        i = 0
        lastCellValue = 0
        cellValue = 0
        for col in range(self.cols):
            for row in range(self.rows):
                cellValue = self.gridVSprites[turno][row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
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
                        self.screen.blit(self.sprite[1][cellValue][i], cellSpace)
                        i += 1
                    except:
                        pass
                else:
                    i = 0 # usar j como contador de los sprites verticales
                    
    def drawRadar(self, turno):
        i = 0
        cellValue = 0
        for col in range(self.cols):
            for row in range(self.rows):
                cellValue = self.gridRadar[turno][row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
                cellSpace = pygame.Rect(col * self.cellSize + 47, row * self.cellSize + 47, self.cellSize + 2, self.cellSize + 2)
                
                if cellValue != 0:
                    if cellValue == 1: #Entra en esta condicion para dibujar el barco horizontal completo
                        self.screen.blit(self.spriteFall, cellSpace)
                    else:
                        self.screen.blit(self.spriteAssert, cellSpace)

    def drawSFX(self, turn):
        i = 0
        cellValue = 0
        for col in range(self.cols):
            for row in range(self.rows):
                cellValue = self.grid[turn][row][col] #para hacer una recorrido horizontal poner en un if para indicar tipo de recorrido de acuerdo al barco actual
                cellSpace = pygame.Rect(col * self.cellSize + 47, row * self.cellSize + 542, self.cellSize + 2, self.cellSize + 2)
                
                if cellValue != 0:
                    if cellValue == 6: #Entra en esta condicion para dibujar el barco horizontal completo
                        self.screen.blit(self.spriteDodge, cellSpace)
                    elif cellValue == 7:
                        self.screen.blit(self.spriteExplotion, cellSpace)
