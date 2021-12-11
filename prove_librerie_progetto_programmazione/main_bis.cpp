#include <curses.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#define NUMERO_PIATTAFORME_PER_LIVELLO 4

using namespace std;

typedef struct piattaforma
{
    int posizione_inizio;
    int lunghezza;
} Piattaforma;

typedef struct livello
{
    Piattaforma piattaforme[NUMERO_PIATTAFORME_PER_LIVELLO];
} Livello;

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

    (lista_livelli->chunk).piattaforme[0].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[0].lunghezza = 4;

    (lista_livelli->chunk).piattaforme[1].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[1].lunghezza = 4;

    (lista_livelli->chunk).piattaforme[2].posizione_inizio = 3
int main()
{
    srand(time(0));
    int yi, xi;
    int y[3], x[3];
    int index;
    int maxlines, maxcols;

    p_node lista_livelli;
    lista_livelli = new Node;

    (lista_livelli->chunk).piattaforme[0].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[0].lunghezza = 4;

    (lista_livelli->chunk).piattaforme[1].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[1].lunghezza = 4;

    (lista_livelli->chunk).piattaforme[2].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[2].lunghezza = 4;

    (lista_livelli->chunk).piattaforme[3].posizione_inizio = 3;
    (lista_livelli->chunk).piattaforme[3].lunghezza = 4;

    /* initialize curses */

    initscr();
    cbreak();
    noecho();

    clear();

    /* genero maxlines e maxcols */

    maxlines = LINES - 1;
    maxcols = COLS - 1;

    /* provo a ricreare il primo livello con solo 4 piattaforme */
    int i, j;
    for (i = 0; i < NUMERO_PIATTAFORME_PER_LIVELLO; i++)
    {
        int n_lunghezza = (lista_livelli->chunk).piattaforme[i].lunghezza;
        int n_pos_inizio = (lista_livelli->chunk).piattaforme[i].posizione_inizio;
        
        for (j = 0; j < n_lunghezza; j++)
        {
            mvaddch(2*(1+i), n_pos_inizio+j, '=');
        }
    }

    refresh();


    ///* provo a ricreare il primo livello con solo 4 piattaforme */
    //for (i = 0; i < 4; i++)
    //{
    //    for (j = 0; j < 5; j++)
    //    {
    //        mvaddch(2*(1+i), 2+j, '=');
    //    }
    //}
    //refresh();



    /* done */

    mvaddstr(maxlines, 0, "Press any key to quit");

    refresh();

    getch();
    endwin();

    exit(0);
}





/*

--------------------------------
|                              |
|      ===========             |
|>                             |
|      =======                 |
|                              |
|            ============      |
|@                             |
--------------------------------


--------------------------------
|                              |
|                              |
|>                             |
|                              |
|                              |
|                              |
|@                             |
--------------------------------
*/