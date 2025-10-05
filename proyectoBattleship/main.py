import pygame, sys
from game import Game

pygame.init()

#revision parte 1 26/09/2025
screen = pygame.display.set_mode((900, 990))
pygame.display.set_caption("Batalla Naval")

clock = pygame.time.Clock()

oceanGrid = pygame.image.load("oceanGrid.png")
oceanGrid = pygame.transform.scale(oceanGrid, (495, 495))

targetGrid = pygame.image.load("targetGrid.png")
targetGrid = pygame.transform.scale(targetGrid, (495, 495)) #Cada celda mide 45px

Button = pygame.transform.scale(pygame.image.load("nextB.png").convert_alpha(), (300, 100))

titleFont = pygame.font.Font(None, 40)
title = titleFont.render("Turno:", True, (255, 255, 255))
player = ["Jugador 1", "Jugador 2"]

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
        if event.type == pygame.MOUSEBUTTONUP and event.button == 1 and game.attackStatus != 0:
            if buttonRect.collidepoint(getMousePos):
                if not game.asserts[0] == 17 and not game.asserts[1] == 17:
                    if game.turno == 1:
                        game.turno = 0
                        game.attackStatus = 1
                    else:
                        game.turno = 1
                        game.attackStatus = 1
                else:
                    game.clean()

    screen.fill((0, 0, 0))
    screen.blit(oceanGrid, (0, 495))
    screen.blit(targetGrid, (0, 0))
    screen.blit(title, (640, 200))
    currentPlayer = titleFont.render(player[game.turno], True, (255, 255, 255))
    screen.blit(currentPlayer, (620, 260))
    print(game.asserts)

    if game.attackStatus != 0:
        buttonRect = pygame.Rect(540, 700, 300, 100)

        getMousePos = pygame.mouse.get_pos()
        click = pygame.mouse.get_pressed()
        screen.blit(Button, buttonRect)
    if game.asserts[0] == 17 or game.asserts[1] == 17:
        screen.blit(titleFont.render("Ganador!", True, (255, 255, 255)), (640, 310))

    game.draw()
    
    pygame.display.update()
    clock.tick(60)
    