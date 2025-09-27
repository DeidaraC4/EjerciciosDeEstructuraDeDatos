import pygame, sys
from game import Game

pygame.init()

#revision parte 1 26/09/2025
screen = pygame.display.set_mode((495, 990))
pygame.display.set_caption("Batalla Naval")

clock = pygame.time.Clock()

oceanGrid = pygame.image.load("oceanGrid.png")
oceanGrid = pygame.transform.scale(oceanGrid, (495, 495))

targetGrid = pygame.image.load("targetGrid.png")
targetGrid = pygame.transform.scale(targetGrid, (495, 495)) #Cada celda mide 45px

game = Game(screen)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                game.moveLeft()
            if event.key == pygame.K_RIGHT:
                game.moveRight()
            if event.key == pygame.K_UP:
                game.moveUp()
            if event.key == pygame.K_DOWN:
                game.moveDown()
            if event.key == pygame.K_r:
                game.rotate()
            if event.key == pygame.K_RETURN:
                game.lockShip()
    screen.blit(oceanGrid, (0, 495))
    screen.blit(targetGrid, (0, 0))
    game.draw()
    
    pygame.display.update()
    clock.tick(60)