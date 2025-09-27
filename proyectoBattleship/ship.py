from sprites import Sprites
from position import Position
import pygame

class Ship:
    def __init__(self, screen: pygame.surface.Surface, id):
        self.id = id
        self.rotationState = 0
        self.rowOffset = 0
        self.colOffset = 0
        self.cells = {}
        self.cellSize = 45
        self.sprites = Sprites.getSprites()
        self.screen = screen

    def move(self, row, col):
        self.rowOffset += row
        self.colOffset += col
    
    def getCellsPosition(self):
        tiles = self.cells[self.rotationState]
        movedCells = []
        for position in tiles:
            position = Position(position.row + self.rowOffset, position.col + self.colOffset)
            movedCells.append(position)
        return movedCells
    
    def rotate(self):
        self.rotationState += 1
        if self.rotationState == len(self.cells):
            self.rotationState = 0
    
    def undo_rotation(self):
        if self.rotationState == 0:
            self.rotationState = len(self.cells) - 1
            return
        self.rotationState -= 1

    def draw(self):
        tiles = self.getCellsPosition()
        i = 0
        for tile in tiles:
            rect = pygame.Rect(tile.col * self.cellSize + 47, tile.row * self.cellSize + 542, self.cellSize - 2, self.cellSize - 2)
            self.screen.blit(self.sprites[self.rotationState][self.id][i], rect)
            i += 1