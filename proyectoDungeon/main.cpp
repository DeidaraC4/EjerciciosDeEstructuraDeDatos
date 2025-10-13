#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <ctime> //para time()
#include <cstdlib> //rand y srand

using namespace std;

class Position{
    public:
        int x;
        int y;
};

class Grid{
    public:
        int grid[2][21][21] = {0}; //grid por niveles
        int gridS[21][21] = {0}; //grid de la sombra de guerra
        int gridP[21][21] = {0}; //grid de la capa del jugador
        int traps = 0;
        int treasures = 0;
        int row;
        int col;
        char symbol;
        //se deben definir los atributos iniciales en el constructor
        Grid(){
            while(traps < 7 || treasures < 11){
                row = rand() % 20;
                col = rand() % 20;
                if(grid[0][row][col] == 0 && traps < 7){
                    grid[0][row][col] = 3;
                    traps++;
                }else if(grid[0][row][col] == 0){
                    grid[0][row][col] = 2;
                    treasures++;
                }
            }
        //    int grid[2][19][19] = {0};
        }

        void drawS(){
            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++)
                {
                    switch (gridS[i][j])
                    {
                    case 0:
                        symbol = '.';
                        break;
                    case 2:
                        symbol = 'T';
                        break;
                    case 3:
                        symbol = 'X';
                        break;
                    }
                    mvaddch(1 + i, 1 + j, symbol);
                }
            }
        }

        void drawP(){
            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++)
                {
                    if(gridP[i][j] == 1)
                    {
                        mvaddch(1 + i, 1 + j, 'P');
                    }
                }
            }
        }
};

class Player{
    public:
        Position pos;

        Player(){
            pos.x = 0;
            pos.y = 0;
        }
};

class Game{
    public:
        Grid grid;
        Player player;
        void moveUp(){
            player.pos.y -= 1;
            if(player.pos.y < 0){
                player.pos.y += 1;
            }
            isSomethingThere(0);
        }
        void moveDown(){
            player.pos.y += 1;
            if(player.pos.y > 20){
                player.pos.y -= 1;
            }
            isSomethingThere(0);
        }
        void moveLeft(){
            player.pos.x -= 1;
            if(player.pos.x < 0){
                player.pos.x += 1;
            }
            isSomethingThere(0);
        }
        void moveRight(){
            player.pos.x += 1;
            if(player.pos.x > 20){
                player.pos.x -= 1;
            }
            isSomethingThere(0);
        }
        void isSomethingThere(int level){
            if(grid.grid[level][player.pos.y][player.pos.x] != 0){
                grid.gridS[player.pos.y][player.pos.x] = grid.grid[level][player.pos.y][player.pos.x];
            }
        }
        void draw(){
            mvprintw(0, 30, "Valor del grid: %d", grid.grid[0][player.pos.y][player.pos.x]);
            //mvprintw(1, 30, "Posicion x: %d", player.pos.x);
            //mvprintw(2, 30, "Problemas en 14 19: %d", grid.gridP[19][14]);
            
            grid.gridP[player.pos.y][player.pos.x] = 1;
            grid.drawS(); //dibujar sombra de guerra antes del jugador
            grid.drawP();
            grid.gridP[player.pos.y][player.pos.x] = 0;
        }
};

int main(){
    //configuracion base
    srand(time(NULL));
    initscr();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    //configuracion del juego
    int height = 23;
    int width = 23;
    WINDOW *win = newwin(height, width, 0, 0);//crear subventana
    int ch;
    bool running = true;

    //objetos de juego
    Game game;

    while (running)
    {
        int ch = getch();
        switch (ch)
        {
            case 'q':
            running = false;
            break;
            case KEY_UP:
                game.moveUp();
            break;
            
            case KEY_DOWN:
                game.moveDown();
            break;
            
            case KEY_LEFT:
                game.moveLeft();
            break;
            
            case KEY_RIGHT:
                game.moveRight();
            break;
            
            default:
            break;
        }

        box(win, 0, 0);

        game.draw();
        
        wrefresh(win);
        refresh();
        
        usleep(50000);
        wclear(win);
        clear();
        win = newwin(height, width, 0, 0);
    }

    endwin();
    return 0;
}