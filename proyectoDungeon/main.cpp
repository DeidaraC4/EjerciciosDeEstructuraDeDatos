#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <ctime> //para time()
#include <cstdlib> //rand y srand
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

struct Puntuacion{
    string nombre;
    int puntos;
};

void guardarPuntuacion(char nombre[6], int puntos){
    ofstream file("puntuacion.txt", ios::app); // abrir para añadir (no borrar lo anterior)
    if (!file.is_open()) {
        mvprintw(0, 0, "Error: no se pudo abrir puntuacion.txt para escritura");
        return;
    }
    file << nombre << " " << puntos << "\n";
    file.close();
}

void cargarPuntuacion(){
    ifstream file("puntuacion.txt");
    if (!file.is_open()) {
        mvprintw(0, 0, "Error: no se pudo abrir puntuacion.txt para lectura");
        return;
    }

    vector<Puntuacion> lista;
    string nombre;
    int puntos;

    while (file >> nombre >> puntos) {
        lista.push_back({nombre, puntos});
    }
    file.close();

    sort(lista.begin(), lista.end(), [](const Puntuacion& a, const Puntuacion& b) { //ordenar elementos ya
        return a.puntos > b.puntos;
    });

    for (size_t i = 0; i < lista.size() && i < 10; ++i) {
        mvprintw(6 + i * 2, 5, "%d. %-10s %5d", (int)(i + 1), lista[i].nombre.c_str(), lista[i].puntos); // manipular strings para que se vean mas esteticos
    }
}

vector<int> walk(int grid[3][21][21], int x, int y, int level){
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
        if (grid[level][newY][newX] == 5) {
            // Calcula la celda intermedia (la pared que se eliminará)
            int wallX = x + dir[0] / 2;
            int wallY = y + dir[1] / 2;

            // Seguridad adicional: evitar escribir fuera de rango
            if (wallX < 0 || wallY < 0 || wallX >= 21 || wallY >= 21)
                continue;

            grid[level][y][x] = 0;
            grid[level][wallY][wallX] = 0;
            grid[level][newY][newX] = 0;

            return {newX, newY};
        }
    }
    return {-1, -1};
}

vector<int> hunt(int grid[3][21][21], int level){
    for (int y = 0; y < 21; y += 2) {
        for (int x = 0; x < 21; x += 2) {
            if (grid[level][y][x] == 5) {
                vector<vector<int>> neighbors;

                if (y - 2 >= 0 && grid[level][y - 2][x] == 0)
                    neighbors.push_back({0, -1});
                if (x - 2 >= 0 && grid[level][y][x - 2] == 0)
                    neighbors.push_back({-1, 0});
                if (x + 2 < 21 && grid[level][y][x + 2] == 0)
                    neighbors.push_back({1, 0});
                if (y + 2 < 21 && grid[level][y + 2][x] == 0)
                    neighbors.push_back({0, 1});

                if (neighbors.empty())
                    continue;

                static mt19937 generador(random_device{}()); //generar  con un motor random un generador rand, algorimtmo mt19937
                vector<int> dir = neighbors[uniform_int_distribution<int>(0, neighbors.size() - 1)(generador)];
                //vector<int> dir = neighbors[rand() % neighbors.size()]; // se podria usar esto pero rand() no tiene mucha entropia estadisticamente hablando

                int wallX = x + dir[0]; //tambien se puede acceder a los elementos por corchetes
                int wallY = y + dir[1];

                grid[level][y][x] = 0;
                grid[level][wallY][wallX] = 0;

                return {x, y};
            }
        }
    }
    return {-1, -1};
}

void createMaze(int grid[3][21][21],int level){
    vector<int> xy = {2 * (rand() % 11), 2 * (rand() % 10)}; //de 0 a 20 de 2 en 2

    do{
        xy = walk(grid, xy.at(0), xy.at(1), level);
        if(xy.at(0) == -1 && xy.at(1) == -1){
            xy = hunt(grid, level);
        }
    }while(xy.at(0) != -1 || xy.at(1) != -1);
}

void insertionSort(int arr[]){
    for(int i = 1; i < 5; i++){
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
        int grid[3][21][21] = {0}; //grid por niveles, se generan primero las paredes antes de hacer el laberinto
        int gridS[21][21] = {0}; //grid de la sombra de guerra
        int gridP[21][21] = {0}; //grid de la capa del jugador
        int gridT[3][21][21] = {0}; //almacenar el valor de los tesoros
        int traps = 0;
        int treasures = 0;
        int key = 0;
        int escape = 0;
        int row;
        int col;
        int value;
        char symbol;
        //se deben definir los atributos iniciales en el constructor
        Grid(){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 21; j++) {
                    for (int k = 0; k < 21; k++) {
                        grid[i][j][k] = 5;
                    }
                }
            }
            for (int level = 0; level < 3; level++) {
                createMaze(grid, level);
                while(traps < 7 * (level + 1) || treasures < 11 * (level + 1) || key == 0 || escape == 0){
                    row = rand() % 21;
                    col = rand() % 21;
                    value = 100 + rand() % 9 * 100;
                    if(grid[level][row][col] == 0 && traps < 7 * (level + 1)){
                        grid[level][row][col] = 3;
                        traps++;
                    }else if(grid[level][row][col] == 0 && treasures < 11 * (level + 1)){
                        grid[level][row][col] = 2;
                        gridT[level][row][col] = value;
                        treasures++;
                    }else if(grid[level][row][col] == 0 && key == 0){
                        grid[level][row][col] = 4;
                        key++;
                    }else if(grid[level][row][col] == 0){
                        grid[level][row][col] = 6;
                        escape++;
                    }
                }
                traps = 0;
                treasures = 0;
                key = 0;
                escape = 0;
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
                    case 6:
                        symbol = 'S';
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
        int inventario[5] {0};
        int contInventario;
        int contEnergia; //si el contador llega a limite de 3 genera 2 pts de energia
        int llave = false;
        int puntuacion = 0;
        Player(){ //segmentation fault
            pos.x = 0;
            pos.y = 0;
            vidas = 40;
            energia = 5; // puede cambiar de acuerdo a la dinamica del juego
            contInventario = 0;
        }
};

class GUI{
    public:
        Position pos;
        int opt = 0; //mapeo de cursor a opcion elegida
        int gui = 1; //por defecto es el game.gui.menu de inicio
        bool menu = true; // el menu esta activo por defecto
        int lim = 0; //cantidad de opciones
        char input[80];

        GUI(){
            pos.x = 3;
            pos.y = 3;
        }
        void moveUp(){
            pos.y -= 2;
            opt -= 1;
            if(pos.y < 3){
                pos.y += 2;
                opt += 1;
            }
        }
        void moveDown(){
            pos.y += 2;
            opt += 1;
            if(pos.y > 1 + 2 * lim){
                pos.y -= 2;
                opt -= 1;
            }
        }
        void draw(WINDOW *win1 = newwin(0,0,0,0)){
            if(gui == 1){
                lim = 3;
                mvprintw(pos.y, pos.x, ">");
                mvprintw(3, 5, "Jugar");
                mvprintw(5, 5, "Continuar");
                mvprintw(7, 5, "Puntuaciones");
            }else if(gui == 2){
                mvprintw(3, 5, "Place   Name   Score");
                cargarPuntuacion();
                //mvprintw(5, 5, "1       Erick   500");
            }else if(gui == 3){
                mvprintw(5, 5, "Game Over!");
            }else if (gui == 4){
                lim = 2;
                mvprintw(pos.y, pos.x, ">");
                mvprintw(3, 5, "Reanudar");
                mvprintw(5, 5, "Guardar");
            }else if (gui == 5){
                lim = 2;
                mvprintw(pos.y, pos.x, ">");
                mvprintw(3, 5, "Usar");
                mvprintw(5, 5, "No usar");
            }else if(gui == 6){
                mvwprintw(win1, 5, 7, "WIN WIN!");
                mvwprintw(win1, 7, 3, "nombre: ");
                echo();
                curs_set(1);
                mvwgetnstr(win1, 7, 11, input, 5);
                noecho();
                curs_set(0);
            }
        }
};

class Game{
    public:
        Grid grid;
        Player player;
        GUI gui;
        int level = 2;
        void moveUp(){
            player.pos.y -= 1;
            player.energia -= 1;
            player.contEnergia +=1;
            if(player.contEnergia == 3){
                player.energia += 4;
                player.contEnergia = 0;
            }
            if(player.energia == 0){
                player.energia = 5;
                player.vidas -= 1;
                if(player.vidas == 0){
                    gui.menu = true;
                    gui.gui = 3; //entrar al menu de game over
                }
            }
            if(player.pos.y < 0){
                player.pos.y += 1;
            }
            isSomethingThere(level, {0, -1});
        }
        void moveDown(){
            player.pos.y += 1;
            player.energia -= 1;
            player.contEnergia +=1;
            if(player.contEnergia == 3){
                player.energia += 4;
                player.contEnergia = 0;
            }
            if(player.energia == 0){
                player.energia = 5;
                player.vidas -= 1;
                if(player.vidas == 0){
                    gui.menu = true;
                    gui.gui = 3; //entrar al menu de game over
                }
            }
            if(player.pos.y > 20){
                player.pos.y -= 1;
            }
            isSomethingThere(level, {0, 1});
        }
        void moveLeft(){
            player.pos.x -= 1;
            player.energia -= 1;
            player.contEnergia +=1;
            if(player.contEnergia == 3){
                player.energia += 4;
                player.contEnergia = 0;
            }
            if(player.energia == 0){
                player.energia = 5;
                player.vidas -= 1;
                if(player.vidas == 0){
                    gui.menu = true;
                    gui.gui = 3; //entrar al menu de game over
                }
            }
            if(player.pos.x < 0){
                player.pos.x += 1;
            }
            isSomethingThere(level, {-1, 0});
        }
        void moveRight(){
            player.pos.x += 1;
            player.energia -= 1;
            player.contEnergia +=1;
            if(player.contEnergia == 3){
                player.energia += 4;
                player.contEnergia = 0;
            }
            if(player.energia == 0){
                player.energia = 5;
                player.vidas -= 1;
                if(player.vidas == 0){
                    gui.menu = true;
                    gui.gui = 3; //entrar al menu de game over
                }
            }
            if(player.pos.x > 20){
                player.pos.x -= 1;
            }
            isSomethingThere(level, {1, 0});
        }
        void resetMap(){
            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++)
                {
                    grid.gridS[i][j] = 0;
                }
            }
            player.llave = false;
            player.pos.x = 0;
            player.pos.y = 0;
        }

        void replaceTreasure(){
            player.puntuacion -= player.inventario[0];
            player.puntuacion += grid.gridT[level][player.pos.y][player.pos.x];
            int temp = grid.gridT[level][player.pos.y][player.pos.x];
            grid.gridT[level][player.pos.y][player.pos.x] = player.inventario[0];
            player.inventario[0] = temp;
            insertionSort(player.inventario);
            gui.menu = false;
        }

        bool isSomethingThere(int level, vector<int> pos = {0, 0}){
            if(grid.grid[level][player.pos.y][player.pos.x] != 0){
                grid.gridS[player.pos.y][player.pos.x] = grid.grid[level][player.pos.y][player.pos.x];
                if(grid.gridS[player.pos.y][player.pos.x] == 3){
                    player.vidas -= 1;
                    if(player.vidas == 0){
                        gui.menu = true;
                        gui.gui = 3; //entrar al menu de game over
                    }
                }else if(grid.gridS[player.pos.y][player.pos.x] == 2){
                    if(player.contInventario < 5){
                        player.puntuacion += grid.gridT[level][player.pos.y][player.pos.x];
                        player.inventario[0] = grid.gridT[level][player.pos.y][player.pos.x];
                        insertionSort(player.inventario);
                        player.contInventario += 1;
                    }else{
                        return true; //en caso de que se presione enter y sea verdad abrir gui de cambiar por elemento seleccionado
                    }
                }else if(grid.gridS[player.pos.y][player.pos.x] == 4){
                    player.llave = true;
                }else if(grid.gridS[player.pos.y][player.pos.x] == 5){
                    player.contEnergia = 0;
                    player.pos.x -= pos.at(0);
                    player.pos.y -= pos.at(1);
                }else if(grid.gridS[player.pos.y][player.pos.x] == 6){
                    if(player.llave == true){
                        gui.menu = true;
                        gui.gui = 5; // menu para preguntar por el uso de la llave
                    }
                }
                grid.grid[level][player.pos.y][player.pos.x] = 0;
            }
            return false;
        }
        void draw(){
            //mvprintw(0, 30, "Valor del grid: %d", grid.grid[0][player.pos.y][player.pos.x]);
            mvprintw(0, 30, "Vidas: %d", player.vidas);
            mvprintw(1, 30, "Puntos de energia: %d", player.energia);
            mvprintw(2, 30, "Objeto 1: %d", player.inventario[4]);
            mvprintw(3, 30, "Objeto 2: %d", player.inventario[3]);
            mvprintw(4, 30, "Objeto 3: %d", player.inventario[2]);
            mvprintw(5, 30, "Objeto 4: %d", player.inventario[1]);
            mvprintw(6, 30, "Objeto 5: %d", player.inventario[0]);
            if(player.llave == true){
                mvprintw(7, 30, "Objeto especial: %s", "llave");
            }
            //mvprintw(1, 30, "Posicion x: %d", player.pos.x);
            //mvprintw(2, 30, "Problemas en 14 19: %d", grid.gridP[19][14]);
            
            grid.gridP[player.pos.y][player.pos.x] = 1;
            grid.drawS(); //dibujar sombra de guerra antes del jugador
            grid.drawP();
            grid.gridP[player.pos.y][player.pos.x] = 0;
        }
        void cargarPartida(){ //pone toda la informacion guardada por el archivo txt
            ifstream file("partidas.txt");
            if (!file.is_open()) {
                cerr << "Error: no se pudo abrir el archivo partidas.txt para lectura." << endl;
                return;
            }

            file >> level;
            file >> player.puntuacion;
            file >> player.pos.x >> player.pos.y;

            // === Cargar grid ===
            for (int l = 0; l < 3; ++l) {
                for (int y = 0; y < 21; ++y) {
                    for (int x = 0; x < 21; ++x) {
                        file >> grid.grid[l][y][x];
                    }
                }
            }

            // === Cargar gridS ===
            for (int y = 0; y < 21; ++y) {
                for (int x = 0; x < 21; ++x) {
                    file >> grid.gridS[y][x];
                }
            }

            // === Cargar gridT ===
            for (int l = 0; l < 3; ++l) {
                for (int y = 0; y < 21; ++y) {
                    for (int x = 0; x < 21; ++x) {
                        file >> grid.gridT[l][y][x];
                    }
                }
            }

            file.close();
            cout << "Partida cargada exitosamente desde partidas.txt" << endl;
        }
        void guardarPartida(){ //solo se puede guardar una partida
            int i = 0;
            ofstream file("partidas.txt");
            if (!file.is_open()) {
                std::cerr << "Error: no se pudo abrir el archivo " << "partidas.txt" << " para escribir." << std::endl;
                return;
            }
            
            file << level << "\n";
            file << player.puntuacion << "\n";
            file << player.pos.x << " " << player.pos.y << "\n";

            //grid
            for (const auto& level : grid.grid) {
                for(const auto& row : level){
                    for(int ele : row){
                        file << ele;
                        if (i < 20) file << " ";
                        i+=1;
                    }
                    i = 0;
                    file << "\n";
                }
            }

            //gridS
            for(const auto& row : grid.gridS){
                for(int ele : row){
                    file << ele;
                    if (i < 20) file << " ";
                    i+=1;
                }
                i = 0;
                file << "\n";
            }

            //gridT
            for(const auto& level : grid.gridT){
                for(const auto& row : level){
                    for(int ele : row){
                        file << ele;
                        if (i < 20) file << " ";
                        i+=1;
                    }
                    i = 0;
                    file << "\n";
                }
            }

            file.close();
            cout << "Partida guardada exitosamente en " << "partidas.txt" << endl;
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
    WINDOW *win = newwin(height, width, 0, 0);//crear subventana para juego
    WINDOW *win1 = newwin(11, 24, 0, 0);//crear subventana para GUI de inicio
    WINDOW *win2 = newwin(24, 32, 0, 0);//crear subventana para GUI de puntuacion

    int ch;
    bool running = true;

    //objetos de juego
    Game game; //segmentation fault

    while (running)
    {
        while(game.gui.menu){
            int ch = getch();
            if(game.gui.gui == 1){ //gui de inicio //podria optimizarse el desarrollo de las GUIs pero por falta de tiempo se tiene asi
                switch (ch)
                {
                    case 'q':
                    game.gui.menu = false;
                    running = false;
                    break;
                    case KEY_UP:
                        game.gui.moveUp();
                    break;
                    
                    case KEY_DOWN:
                        game.gui.moveDown();
                    break;
    
                    case '\n':
                        switch (game.gui.opt)
                        {
                        case 0:
                            game.gui.menu = false;
                            break;
                        case 1:
                            game.cargarPartida();
                            game.gui.menu = false;
                            break;
                        case 2:
                            game.gui.gui = 2; //entrar a la gui de puntuacion
                            break;
                        default:
                            break;
                        }
                    break;
    
                    default:
                    break;
                }
                box(win1, 0, 0); //segmentation fault
    
                game.gui.draw();
                
                wrefresh(win1);
                refresh();
                
                usleep(50000);
                wclear(win1);
                clear();
                win1 = newwin(11, 24, 0, 0);
            }else if(game.gui.gui == 2){ //gui de puntucaion
                if(ch == 'q'){
                    game.gui.gui = 1; //regresar al inicio
                }
                box(win2, 0, 0); //segmentation fault
    
                game.gui.draw();
                
                wrefresh(win2);
                refresh();
                
                usleep(50000);
                wclear(win2);
                clear();
                win2 = newwin(24, 32, 0, 0);
            }else if(game.gui.gui == 3){
                if(ch == 'q'){
                    game.gui.menu = false; //cerrar programa
                    running = false;
                }
                box(win1, 0, 0); //segmentation fault
    
                game.gui.draw();
                
                wrefresh(win1);
                refresh();
                
                usleep(50000);
                wclear(win1);
                clear();
                win1 = newwin(11, 24, 0, 0);
            }else if(game.gui.gui == 4){
                switch (ch)
                {
                    case KEY_UP:
                        game.gui.moveUp();
                    break;
                    
                    case KEY_DOWN:
                        game.gui.moveDown();
                    break;
    
                    case '\n':
                        switch (game.gui.opt)
                        {
                        case 0:
                            game.gui.menu = false;
                            break;
                        case 1:
                            game.guardarPartida();
                            break;
                        default:
                            break;
                        }
                    break;
    
                    default:
                    break;
                }
                box(win1, 0, 0); //segmentation fault
    
                game.gui.draw();
                
                wrefresh(win1);
                refresh();
                
                usleep(50000);
                wclear(win1);
                clear();
                win1 = newwin(11, 24, 0, 0);
            }else if(game.gui.gui == 5){
                switch (ch)
                {
                    case KEY_UP:
                        game.gui.moveUp();
                    break;
                    
                    case KEY_DOWN:
                        game.gui.moveDown();
                    break;
    
                    case '\n':
                        switch (game.gui.opt)
                        {
                        case 0:
                            if(game.level == 2){
                                game.gui.gui = 6;
                                break;
                            }
                            game.gui.menu = false;
                            game.level += 1;
                            game.resetMap();
                            break;
                        case 1:
                            game.gui.menu = false;
                            break;
                        default:
                            break;
                        }
                    break;
    
                    default:
                    break;
                }
                box(win1, 0, 0); //segmentation fault
    
                game.gui.draw();
                
                wrefresh(win1);
                refresh();
                
                usleep(50000);
                wclear(win1);
                clear();
                win1 = newwin(11, 24, 0, 0);
            }else if(game.gui.gui == 6){
                // if(ch == 'q'){
                //     game.gui.menu = false; //cerrar programa
                //     running = false;
                // }
                
                box(win1, 0, 0); //segmentation fault
                wrefresh(win1);
                refresh();
                
                game.gui.draw(win1);
                guardarPuntuacion(game.gui.input, game.player.puntuacion); // se puede implementar en game facilmente
                
                //usleep(50000);
                werase(win1);
            }
        }


        int ch = getch();
        switch (ch)
        {
            case 'q':
            running = false;
            break;

            case 'm':
                game.gui.menu = true;
                game.gui.gui = 4;
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

            case '\n':
                if(game.isSomethingThere(game.level)){
                    game.replaceTreasure();
                }
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