import pygame
import os

class Sprites:
    def getSprites():
        lista = [[["z" for i in range(5)] for j in range(6)] for k in range(2)]
        barcosH = [["z" for i in range(5)] for j in range(5)]
        barcosV = [["z" for i in range(5)] for j in range(5)]
        barcosVCarpeta = []
        barcosHCarpeta = []

            
        for carpeta in os.listdir("RightShips"):
            barcosHCarpeta.append(carpeta)
        barcosHCarpeta.sort()

        j = 0
        for i in range(5):
            for archivo in os.listdir(os.path.join("RightShips", barcosHCarpeta[i])):
                barcosH[i][j] = archivo
                j +=1
            barcosH[i].sort()
            j = 0
            
        for carpeta in os.listdir("BottomShips"):
            barcosVCarpeta.append(carpeta)
        barcosVCarpeta.sort()

        j = 0
        for i in range(5):
            for archivo in os.listdir(os.path.join("BottomShips", barcosVCarpeta[i])):
                barcosV[i][j] = archivo
                j +=1
            barcosV[i].sort()
            j = 0
            
        i = 1
        j = 0

        for carpeta in barcosHCarpeta:
            ruta = os.path.join("RightShips", carpeta)
            #print(carpeta)
            for archivo in barcosH[barcosHCarpeta.index(carpeta)]:
                #print(archivo)
                if barcosVCarpeta.index(carpeta) == 4:
                    #print("ultimoH--------------------")
                    pass
                ruta2 = os.path.join(ruta, archivo)
                try:
                    lista[0][i][j] = pygame.image.load(ruta2).convert_alpha()
                    lista[0][i][j] = pygame.transform.scale(lista[0][i][j], (45, 45))
                    ruta2 = ""
                    j += 1
                except:
                    break
            j = 0
            i += 1
            
        i = 1
        j = 0

        for carpeta in barcosVCarpeta:
            ruta = os.path.join("BottomShips", carpeta)
            #print(carpeta)
            for archivo in barcosV[barcosVCarpeta.index(carpeta)]:
                #print(archivo)
                if barcosVCarpeta.index(carpeta) == 4:
                    #print("ultimoV--------------------")
                    pass
                ruta2 = os.path.join(ruta, archivo)
                try:
                    lista[1][i][j] = pygame.image.load(ruta2).convert_alpha()
                    lista[1][i][j] = pygame.transform.scale(lista[1][i][j], (45, 45))
                    ruta2 = ""
                    j += 1
                except:
                    break
            j = 0
            i += 1
        return lista