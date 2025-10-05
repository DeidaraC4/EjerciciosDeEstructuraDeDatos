from position import Position
import pygame

class Bullet:
    def __init__(self, screen: pygame.surface.Surface):
        self.rowOffset = 0
        self.colOffset = 0
        self.cellSize = 45
        self.sprite = pygame.transform.scale(pygame.image.load("fall.png").convert_alpha(), (45, 45))
        self.screen = screen

    def move(self, row, col):
        self.rowOffset += row
        self.colOffset += col

    def draw(self):
            rect = pygame.Rect(self.colOffset * self.cellSize + 47, self.rowOffset * self.cellSize + 47, self.cellSize - 2, self.cellSize - 2)
            self.screen.blit(self.sprite, rect)