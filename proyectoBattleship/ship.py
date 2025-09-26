from sprites import Sprites
import pygame

class Ship:
    def __init__(self, screen: pygame.surface.Surface, id):
        self.id = id
        self.rotationState = 0
        self.cells = {}
        self.cellSize = 45
        self.sprites = Sprites.getSprites()
        self.screen = screen
    
    def draw(self):
        tiles = self.cells[self.rotationState]
        i = 0
        for tile in tiles:
            rect = pygame.Rect(tile.col * self.cellSize + 47, tile.row * self.cellSize + 542, self.cellSize - 2, self.cellSize - 2)
            self.screen.blit(self.sprites[self.rotationState][self.id][i], rect)
            i += 1