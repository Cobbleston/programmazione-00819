#include <curses.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#define NUMERO_PIATTAFORME_PER_LIVELLO 4

using namespace std;


class Piattaforma
{
    public:
        int random_value = rand() % 3; // valore random tra 0, 1, 2
        int posizione_x_inizio = 4 + random_value; // valore iniziale
        int lunghezza; // lunghezza piattaforma
};

class Livello
{
    public:
        Piattaforma piattaforme[NUMERO_PIATTAFORME_PER_LIVELLO];
};

typedef struct node
{
    node *prev = NULL;
    Livello chunk;
    node *next = NULL;
} Node;

typedef Node *p_node;

int main()
{
    srand(time(0));
    int yi, xi;
    int y[3], x[3];
    int index;
    int maxlines, maxcols;

    p_node lista_livelli;
    lista_livelli = new Node;

    (lista_livelli->chunk).piattaforme[0].posizione_x_inizio = 0;
    (lista_livelli->chunk).piattaforme[0].lunghezza = 3;

    /* initialize curses */

    initscr();
    cbreak();
    noecho();

    clear();

    /* genero maxlines e maxcols */

    maxlines = LINES - 1;
    maxcols = COLS - 1;

    /* prove stampa sovrascrittura */

    for (int i = 0; i < maxlines; i++)
    {
        mvaddstr(i, 0, "*******************************");
    }

    getch();
    refresh();

    mvaddch(5, 5, 'k');

    getch();
    refresh();

    /* done */
    
    mvaddstr(maxlines, 0, "Press any key to quit");

    refresh();

    getch();
    endwin();

    exit(0);
}