import pygame, sys
from grid import Grid
from ships import *

pygame.init()

screen = pygame.display.set_mode((495, 990))
pygame.display.set_caption("Batalla Naval")

clock = pygame.time.Clock()

oceanGrid = pygame.image.load("oceanGrid.png")
oceanGrid = pygame.transform.scale(oceanGrid, (495, 495))

targetGrid = pygame.image.load("targetGrid.png")
targetGrid = pygame.transform.scale(targetGrid, (495, 495)) #Cada celda mide 45px

gameGrid = Grid(screen)

ship = shipTwo(screen)

running = True
while running:
    for event in pygame.event.get():
        if event.type == quit:
            pygame.quit()
            sys.exit()
            running = False
    screen.blit(oceanGrid, (0, 495))
    screen.blit(targetGrid, (0, 0))
    gameGrid.drawGridH()
    #gameGrid.drawGridV()
    #ship.rotationState = 1
    ship.draw()
    
    pygame.display.update()
    clock.tick(60)