#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "Jugador.h"
#include "Bombas.h"
#include "Espina.h"
#include "V_DosPuntos.h"
#include "Normal.h"
#include "Escenario.h"
#include "Invisible.h"
#include "Tren.h"
#include <string>
#include<stdlib.h>

using namespace std;

void movimiento();
int menu();
void salir();
void registro(int);
int tipobomba();
void Cargando();
void EscenarioInvisible();
int kbhit(void);

Jugador* jugador;

int main(void){
    int z;
    int escenario;
    while (z != 3)
    {
        erase();
        z = menu();
        switch (z){
            case 1:{
                curs_set(0);
                move(5, 21);
                printw("Escenario Invisible");
                refresh();
                usleep(1000000);
                escenario = 1;
                registro(escenario);
                int tipo = tipobomba();
                Cargando();
                EscenarioInvisible();
                movimiento();
                curs_set(1);
                break;
            }

            case 2:{
                curs_set(0);
                move(5, 21);
                printw("Escenario del Tren");
                refresh();
                usleep(1000000);
                escenario = 2;
                registro(escenario);
                int tipo = tipobomba();
                Cargando();
                curs_set(1);    
                break;
            }
            
            case 3:{
                salir();
            }
        }
    }
}

int menu(){
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_WHITE);
        attron(COLOR_PAIR(1));
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Elija un escenario (Enter):\n");
        move(2, 1);
        printw("1) Escenario Invisible \n");
        move(3, 1);
        printw("2) Escenario del Tren \n");
        move(4, 1);
        printw("3) Salir \n");
        move(5, 0);
        printw("Escenario elegido: ");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
        }
        else
        {
            if (tecla == 65 && cy > 2)
            {
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy < 4)
            {
                cy = cy + 1;
                move(cy, cx);
            }
        }
        refresh();
    }
    echo();
    return 0;
}

void salir(){
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, (x / 2 - 6));
        printw("Saliendo");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
    exit(0);
}

int kbhit(void){
    struct timeval timeout;
    fd_set readfds;
    int how;


    FD_ZERO(&readfds);
    FD_SET(0, &readfds);


    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);

    if ((how > 0) && FD_ISSET(0, &readfds))
        return 1;
    else
        return 0;
}

void registro(int escenario){
    erase();
    refresh();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 12));
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("Jugador");
    attroff(COLOR_PAIR(1));

    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    move(y - 1, 0);
    printw("Presione Enter Para Continuar");
    attroff(COLOR_PAIR(4));

    char nombre[100];
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    move(1, 0);
    attron(COLOR_PAIR(2));
    printw("Ingrese su nombre:");
    attroff(COLOR_PAIR(2));
    move(1, 20);
    echo();
    scanw("%s", nombre);
    string name = nombre;
    int estado = 1;
    int tipo = 1;
    jugador = new Jugador(name,estado,tipo);
}

int tipobomba(){
    erase();
    refresh();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 10));
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("Tipo de bomba");
    attroff(COLOR_PAIR(1));
    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    move(y - 1, 0);
    printw("Presione enter para seguir");
    attroff(COLOR_PAIR(4));
    curs_set(1);
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    move(1, 0);
    printw("Escoja un tipo de bomba (Enter):\n");
    move(2, 1);
    printw("1) Bomba normal \n");
    move(3, 1);
    printw("2) Bomba espinal \n");
    move(4, 1);
    printw("3) Bomba :'V \n");
    attroff(COLOR_PAIR(2));
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
        }
        else
        {
            if (tecla == 65 && cy > 2)
            {
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy < 4)
            {
                cy = cy + 1;
                move(cy, cx);
            }
        }
        refresh();
    }
    curs_set(0);
    echo();
}

void Cargando(){
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    move(y / 2, (x / 2 - 7));
    printw("Cargando Juego");
    refresh();
    usleep(1000000 / 2);
    printw(".");
    refresh();
    usleep(1000000 / 2);
    printw(".");
    refresh();
    usleep(1000000 / 2);
    printw(".");
    refresh();
    usleep(1000000 / 2);
    attroff(COLOR_PAIR(1));
}


void EscenarioInvisible(){
    Item*** Matriz;
    Matriz = new Item**[13];
    for(int i = 0; i < 13; i++){
        Matriz[i] = new Item*[11];
    }
    string nombre = "Escenario Invisible";
}

void movimiento(){
    erase();
    char ser = (char) 49;
    int x, y;
    int cx = 1;
    int cy = 1;
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2 - 18);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("Presione ENTER para iniciar el juego.");
    refresh();
    attroff(COLOR_PAIR(1));
    int tecla;
    tecla = getch();
    while (tecla != 10)
    {
        tecla = getch();
    }
    int direccion = 3;
    cx = x / 2;
    cy = y / 2;
    erase();
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    keypad(stdscr,TRUE);
    refresh();
    while (true)
    {
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla==KEY_UP)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla==KEY_LEFT)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla==KEY_RIGHT)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla==KEY_DOWN)
            {
                direccion = 4;
            }
        }
        if ((cx > 0 && cy > 0) && (cx < x && cy < y))
        {
            move(cy, cx);
            //printw("%c", ser);
            printw("%c", ser);
            refresh();
            usleep(1000000 / 5);
            if (direccion == 1)
            {
                cy = cy - 1;
                move(cy + 1, cx);
                printw(" ");
                refresh();
            }
            if (direccion == 2)
            {
                cx = cx - 1;
                move(cy, cx + 1);
                printw(" ");
                refresh();
            }
            if (direccion == 3)
            {
                cx = cx + 1;
                move(cy, cx - 1);
                printw(" ");
                refresh();
            }
            if (direccion == 4)
            {
                cy = cy + 1;
                move(cy - 1, cx);
                printw(" ");
                refresh();
            }
        }
        else
        {
            break;
        }
    }
    attroff(COLOR_PAIR(2));
    keypad(stdscr,FALSE);
    move(y / 2, (x / 2 - 4));
    printw("¡Perdiste!");
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}

