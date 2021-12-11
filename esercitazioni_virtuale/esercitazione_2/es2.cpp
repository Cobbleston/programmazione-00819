#include <iostream>
#include <string.h>

#define L 100

using namespace std;

struct Corso
{
    char nome[L];
    char nome_docente[L];
    char nome_laurea[L];
    int cfu;
};

struct Node
{
    Corso corso;
    Node *next = NULL;
};

typedef Node *pNode;

int crediti_totali(pNode iter, char docente[])
{
    int sum = 0;
    while (iter != NULL)
    {
        if (!strcmp(docente, iter->corso.nome_docente))
        {
            sum += iter->corso.cfu;
        }
        iter = iter->next;
    }
    return sum;
}

int main()
{
    pNode lista_corsi = new Node;
    strcpy(lista_corsi->corso.nome, "Programmazione");
    strcpy(lista_corsi->corso.nome_docente, "Cosimo");
    strcpy(lista_corsi->corso.nome_laurea, "Informatica");
    lista_corsi->corso.cfu = 12;
    
    lista_corsi->next = new Node;
    strcpy(lista_corsi->next->corso.nome, "Architettura");
    strcpy(lista_corsi->next->corso.nome_docente, "Cosimo");
    strcpy(lista_corsi->next->corso.nome_laurea, "Informatica");
    lista_corsi->next->corso.cfu = 6;

    cout << crediti_totali(lista_corsi, "Cosimo") << endl;

    return 0;
}