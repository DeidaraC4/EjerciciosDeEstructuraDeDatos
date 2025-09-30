from grid import Grid
from ships import *
import random

class Game:
    def __init__(self, screen):
        self.screen = screen
        self.grid = Grid(screen)
        self.ships = [shipOne(screen), shipTwo(screen), shipThree(screen), shipFour(screen), shipFive(screen)]
        self.currentShip = self.getRandomShip()
        self.nextShip = self.getRandomShip()

    def getRandomShip(self):
        if len(self.ships) == 0:
            self.ships = [shipOne(self.screen), shipTwo(self.screen), shipThree(self.screen), shipFour(self.screen), shipFive(self.screen)]
        ship = random.choice(self.ships)
        self.ships.remove(ship)
        return ship
    
    def moveLeft(self):
        self.currentShip.move(0, -1)
        if self.isShipInside() == False:
            self.currentShip.move(0, 1)
    
    def moveRight(self):
        self.currentShip.move(0, 1)
        if self.isShipInside() == False:
            self.currentShip.move(0, -1)

    def moveUp(self):
        self.currentShip.move(-1, 0)
        if self.isShipInside() == False:
            self.currentShip.move(1, 0)
    
    def moveDown(self):
        self.currentShip.move(1, 0)
        if self.isShipInside() == False:
            self.currentShip.move(-1, 0)

    def lockShip(self):
        tiles = self.currentShip.getCellsPosition()
        #lo siguiente se puede modularizar en una funcion para saber si un barco colisiona con otro
        for position in tiles:
            if self.grid.grid[position.row][position.col] != 0:
                print("no se puede poner ahi un barco")
                return

        for position in tiles:
            self.grid.grid[position.row][position.col] = self.currentShip.id
            if self.currentShip.rotationState == 0: #agregado para dibujar sprites verticales tambien
                self.grid.gridHSprites[position.row][position.col] = self.currentShip.id
            else:
                self.grid.gridVSprites[position.row][position.col] = self.currentShip.id

        self.currentShip = self.nextShip
        self.nextShip = self.getRandomShip()

    
    def isShipInside(self):
        tiles = self.currentShip.getCellsPosition()
        for tile in tiles:
            if self.grid.isInside(tile.row, tile.col) == False:
                return False
        return True
    
    def rotate(self):
        self.currentShip.rotate()
        if self.isShipInside() == False:
            self.currentShip.undo_rotation()

    def draw(self):
        self.grid.drawGridH()
        self.grid.drawGridV()
        self.currentShip.draw()
