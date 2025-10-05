from grid import Grid
from ships import *
from bullet import Bullet
import random

class Game:
    def __init__(self, screen):
        self.screen = screen
        self.grid = Grid(screen)
        self.ships = [shipOne(screen), shipTwo(screen), shipThree(screen), shipFour(screen), shipFive(screen)]
        self.currentShip = self.getRandomShip()
        self.nextShip = self.getRandomShip()
        self.turno = 0
        self.countShips = 0 #contar los barcos que se ponen en el grid, cuando alcancen 5 se cambiara el turno
        self.attackStatus = 0
        self.bullet = Bullet(screen)
        self.asserts = [0, 0]

    def getRandomShip(self):
        if len(self.ships) == 0:
            self.ships = [shipOne(self.screen), shipTwo(self.screen), shipThree(self.screen), shipFour(self.screen), shipFive(self.screen)]
        ship = random.choice(self.ships)
        self.ships.remove(ship)
        return ship
    
    def moveLeft(self):
        if self.attackStatus == 0:
            self.currentShip.move(0, -1)
            if self.isShipInside() == False:
                self.currentShip.move(0, 1)
        else:
            self.bullet.move(0, -1)
            if self.isTargetInside() == False:
                self.bullet.move(0, 1)
    
    def moveRight(self):
        if self.attackStatus == 0:
            self.currentShip.move(0, 1)
            if self.isShipInside() == False:
                self.bullet.move(0, -1)
        else:
            self.bullet.move(0, 1)
            if self.isTargetInside() == False:
                self.bullet.move(0, -1)

    def moveUp(self):
        if self.attackStatus == 0:
            self.currentShip.move(-1, 0)
            if self.isShipInside() == False:
                self.currentShip.move(1, 0)
        else:
            self.bullet.move(-1, 0)
            if self.isTargetInside() == False:
                self.bullet.move(1, 0)
    
    def moveDown(self):
        if self.attackStatus == 0:
            self.currentShip.move(1, 0)
            if self.isShipInside() == False:
                self.currentShip.move(-1, 0)
        else:
            self.bullet.move(1, 0)
            if self.isTargetInside() == False:
                self.bullet.move(-1, 0)

    def lockShip(self):
        if self.attackStatus == 0:
            tiles = self.currentShip.getCellsPosition()
            #lo siguiente se puede modularizar en una funcion para saber si un barco colisiona con otro
            for position in tiles:
                if self.grid.grid[self.turno][position.row][position.col] != 0:
                    print("no se puede poner ahi un barco")
                    return

            for position in tiles:
                self.grid.grid[self.turno][position.row][position.col] = self.currentShip.id
                if self.currentShip.rotationState == 0: #agregado para dibujar sprites verticales tambien
                    self.grid.gridHSprites[self.turno][position.row][position.col] = self.currentShip.id
                else:
                    self.grid.gridVSprites[self.turno][position.row][position.col] = self.currentShip.id

            self.currentShip = self.nextShip
            self.nextShip = self.getRandomShip()
            self.countShips += 1

            if self.countShips == 5:
                if self.turno == 1:
                    self.attackStatus = 1 #se activa la modalidad de ataque donde ya no se pueden colocar barcos y ahora toca seleccionar la casilla del misil
                    self.turno = 0
                    self.countShips = 0
                else:
                    self.turno = 1
                    self.countShips = 0
        elif self.attackStatus == 1:
            #tiles = self.currentShip.getCellsPosition()
            #lo siguiente se puede modularizar en una funcion para saber si un barco colisiona con otro
            if self.grid.gridRadar[self.turno][self.bullet.rowOffset][self.bullet.colOffset] != 0:
                print("ya se lanzo un misil ahi")
                return
            
            if self.turno == 1: #operacion que debe realizar con el turno actual para lastimar al oponente
                offset = - 1
            else:
                offset = 1

            if self.grid.grid[self.turno + offset][self.bullet.rowOffset][self.bullet.colOffset] != 0:
                self.grid.gridRadar[self.turno][self.bullet.rowOffset][self.bullet.colOffset] = 2
                self.grid.grid[self.turno + offset][self.bullet.rowOffset][self.bullet.colOffset] = 7
                self.asserts[self.turno] += 1

            else:
                self.grid.gridRadar[self.turno][self.bullet.rowOffset][self.bullet.colOffset] = 1
                self.grid.grid[self.turno + offset][self.bullet.rowOffset][self.bullet.colOffset] = 6
            
            self.attackStatus = 2

    def isShipInside(self):
        tiles = self.currentShip.getCellsPosition()
        for tile in tiles:
            if self.grid.isInside(tile.row, tile.col) == False:
                return False
        return True
    
    def isTargetInside(self):
        if self.grid.isInside(self.bullet.rowOffset, self.bullet.colOffset) == False:
            return False
        return True
    
    def rotate(self):
        if self.attackStatus == 0:
            self.currentShip.rotate()
            if self.isShipInside() == False:
                self.currentShip.undo_rotation()

    def draw(self):
        self.grid.drawGridH(self.turno)
        self.grid.drawGridV(self.turno)
        if self.attackStatus == 0:
            self.currentShip.draw()
        else:
            self.grid.drawRadar(self.turno)
            self.bullet.draw()
            self.grid.drawSFX(self.turno)

    def clean(self): #esta funcion se puede llevar a grid pues es donde deberia hacerse la operacion de limpieza
        self.grid.grid = [[[0 for j in range(self.grid.cols)] for i in range(self.grid.rows)] for k in range(2)]
        self.grid.gridHSprites = [[[0 for j in range(self.grid.cols)] for i in range(self.grid.rows)] for k in range(2)]
        self.grid.gridVSprites = [[[0 for j in range(self.grid.cols)] for i in range(self.grid.rows)] for k in range(2)]
        self.grid.gridRadar = [[[0 for j in range(self.grid.cols)] for i in range(self.grid.rows)] for k in range(2)]
        self.attackStatus = 0
        self.asserts[0] = 0
        self.asserts[1] = 0
        self.turno = 0
