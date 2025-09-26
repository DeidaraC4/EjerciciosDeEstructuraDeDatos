from ship import Ship
from position import Position
import pygame

class shipOne(Ship):
    def __init__(self, screen):
        super().__init__(screen, id = 1)
        self.cells = {
            0: [Position(0, 0), Position(0, 1)],
            1: [Position(0, 0), Position(1, 0)]
        }
        
class shipTwo(Ship):
    def __init__(self, screen):
        super().__init__(screen, id = 2)
        self.cells = {
            0: [Position(0, 0), Position(0, 1), Position(0, 2)],
            1: [Position(0, 0), Position(1, 0), Position(2, 0)]
        }

class shipThree(Ship):
    def __init__(self, screen):
        super().__init__(screen, id = 3)
        self.cells = {
            0: [Position(0, 0), Position(0, 1), Position(0, 2)],
            1: [Position(0, 0), Position(1, 0), Position(2, 0)]
        }

class shipFour(Ship):
    def __init__(self, screen):
        super().__init__(screen, id = 4)
        self.cells = {
            0: [Position(0, 0), Position(0, 1), Position(0, 2), Position(0, 3)],
            1: [Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)]
        }

class shipFive(Ship):
    def __init__(self, screen):
        super().__init__(screen, id = 5)
        self.cells = {
            0: [Position(0, 0), Position(0, 1), Position(0, 2), Position(0, 3), Position(0, 4)],
            1: [Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0), Position(4, 0)]
        }