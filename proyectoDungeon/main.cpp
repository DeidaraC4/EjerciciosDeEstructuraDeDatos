#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <ctime> //para time()
#include <cstdlib> //rand y srand
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<int> walk(int grid[2][21][21], int x, int y){
    static mt19937 generador(random_device{}()); //static llamar solo una vez

    vector<vector<int>> pos = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
    shuffle(pos.begin(), pos.end(), generador);

    for(vector<int> dir : pos){
        int newX = x + dir[0];
        int newY = y + dir[1];

        // Verifica si la celda destino está dentro del rango
        if (newX < 0 || newY < 0 || newX >= 21 || newY >= 21)
            continue;

        // Verifica si la celda destino aún no está visitada
        if (grid[0][newY][newX] == 5) {
            // Calcula la celda intermedia (la pared que se eliminará)
            int wallX = x + dir[0] / 2;
            int wallY = y + dir[1] / 2;

            // Seguridad adicional: evitar escribir fuera de rango
            if (wallX < 0 || wallY < 0 || wallX >= 21 || wallY >= 21)
                continue;

            grid[0][y][x] = 0;
            grid[0][wallY][wallX] = 0;
            grid[0][newY][newX] = 0;

            return {newX, newY};
        }
    }
    return {-1, -1};
}

vector<int> hunt(int grid[2][21][21]){
    for (int y = 0; y < 21; y += 2) {
        for (int x = 0; x < 21; x += 2) {
            if (grid[0][y][x] == 5) {
                vector<vector<int>> neighbors;

                if (y - 2 >= 0 && grid[0][y - 2][x] == 0)
                    neighbors.push_back({0, -1});
                if (x - 2 >= 0 && grid[0][y][x - 2] == 0)
                    neighbors.push_back({-1, 0});
                if (x + 2 < 21 && grid[0][y][x + 2] == 0)
                    neighbors.push_back({1, 0});
                if (y + 2 < 21 && grid[0][y + 2][x] == 0)
                    neighbors.push_back({0, 1});

                if (neighbors.empty())
                    continue;

                static mt19937 generador(random_device{}()); //generar  con un motor random un generador rand, algorimtmo mt19937
                vector<int> dir = neighbors[uniform_int_distribution<int>(0, neighbors.size() - 1)(generador)];
                //vector<int> dir = neighbors[rand() % neighbors.size()]; // se podria usar esto pero rand() no tiene mucha entropia estadisticamente hablando

                int wallX = x + dir[0]; //tambien se puede acceder a los elementos por corchetes
                int wallY = y + dir[1];

                grid[0][y][x] = 0;
                grid[0][wallY][wallX] = 0;

                return {x, y};
            }
        }
    }
    return {-1, -1};
}

void createMaze(int grid[2][21][21]){
    vector<int> xy = {2 * (rand() % 11), 2 * (rand() % 10)}; //de 0 a 20 de 2 en 2

    do{
        xy = walk(grid, xy.at(0), xy.at(1));
        if(xy.at(0) == -1 && xy.at(1) == -1){
            xy = hunt(grid);
        }
    }while(xy.at(0) != -1 || xy.at(1) != -1);
}

void insertionSort(int arr[]){
    for(int i = 1; i < 4; i++){
        int reserva = arr[i];

        int j = i - 1;
        while(j >= 0 && reserva < arr[j]){
            arr[j + 1] = arr[j];

            j -= 1;
        }
        arr[j + 1] = reserva;
    }
}

class Position{
    public:
        int x;
        int y;
};

class Grid{
    public:
        int grid[2][21][21] = {0}; //grid por niveles, se generan primero las paredes antes de hacer el laberinto
        int gridS[21][21] = {0}; //grid de la sombra de guerra
        int gridP[21][21] = {0}; //grid de la capa del jugador
        int gridT[21][21] = {0}; //almacenar el valor de los tesoros
        int traps = 0;
        int treasures = 0;
        int key = 0;
        int row;
        int col;
        int value;
        char symbol;
        //se deben definir los atributos iniciales en el constructor
        Grid(){
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 21; j++) {
                    for (int k = 0; k < 21; k++) {
                        grid[i][j][k] = 5;
                    }
                }
            }
            createMaze(grid);
            while(traps < 7 || treasures < 11 || key == 0){
                row = rand() % 20;
                col = rand() % 20;
                value = 100 + rand() % 9 * 100;
                if(grid[0][row][col] == 0 && traps < 7){
                    grid[0][row][col] = 3;
                    traps++;
                }else if(grid[0][row][col] == 0 && treasures < 11){
                    grid[0][row][col] = 2;
                    gridT[row][col] = value;
                    treasures++;
                }else if(grid[0][row][col] == 0){
                    grid[0][row][col] = 4;
                    key++;
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
                    case 4:
                        symbol = 'K';
                        break;
                    case 5:
                        symbol = '#';
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
        int vidas;
        int energia;
        int inventario[4] {0};
        int contInventario;
        int llave = false;
        Player(){ //segmentation fault
            pos.x = 0;
            pos.y = 0;
            vidas = 3;
            energia = 5; // puede cambiar de acuerdo a la dinamica del juego
            contInventario = 0;
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
            isSomethingThere(0, {0, -1});
        }
        void moveDown(){
            player.pos.y += 1;
            if(player.pos.y > 20){
                player.pos.y -= 1;
            }
            isSomethingThere(0, {0, 1});
        }
        void moveLeft(){
            player.pos.x -= 1;
            if(player.pos.x < 0){
                player.pos.x += 1;
            }
            isSomethingThere(0, {-1, 0});
        }
        void moveRight(){
            player.pos.x += 1;
            if(player.pos.x > 20){
                player.pos.x -= 1;
            }
            isSomethingThere(0, {1, 0});
        }
        void isSomethingThere(int level, vector<int> pos){
            if(grid.grid[level][player.pos.y][player.pos.x] != 0){
                grid.gridS[player.pos.y][player.pos.x] = grid.grid[level][player.pos.y][player.pos.x];
                if(grid.gridS[player.pos.y][player.pos.x] == 3){
                    player.vidas -= 1;
                }else if(grid.gridS[player.pos.y][player.pos.x] == 2){
                    if(player.contInventario < 5){
                        player.inventario[0] = grid.gridT[player.pos.y][player.pos.x];
                        insertionSort(player.inventario);
                        player.contInventario += 1;
                    }
                }else if(grid.gridS[player.pos.y][player.pos.x] == 4){
                    player.llave = true;
                }else if(grid.gridS[player.pos.y][player.pos.x] == 5){
                    player.pos.x -= pos.at(0);
                    player.pos.y -= pos.at(1);
                }
            }
        }
        void draw(){
            mvprintw(0, 30, "Valor del grid: %d", grid.grid[0][player.pos.y][player.pos.x]);
            //mvprintw(0, 30, "Vidas: %d", player.vidas);
            mvprintw(1, 30, "Puntos de energia: %d", player.energia);
            mvprintw(2, 30, "Objeto 1: %d", player.inventario[3]);
            mvprintw(3, 30, "Objeto 2: %d", player.inventario[2]);
            mvprintw(4, 30, "Objeto 3: %d", player.inventario[1]);
            mvprintw(5, 30, "Objeto 4: %d", player.inventario[0]);
            mvprintw(6, 30, "Objeto especial: ");
            if(player.llave == true){
                mvprintw(6, 30, "Objeto especial: %s", "llave");
            }
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
    Game game; //segmentation fault

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

        box(win, 0, 0); //segmentation fault

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