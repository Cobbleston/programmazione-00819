#include <iostream>
#include <string.h>

#define L 100

using namespace std;

struct studente
{
    char nome[L];
    char cognome[L];
    int numero_matricola;
};

struct lista_di_studenti
{
    studente val;
    lista_di_studenti *next = NULL;
};

typedef lista_di_studenti *p_lista_di_studenti;

void stampa(p_lista_di_studenti l)
{
    while (l != NULL)
    {
        cout << '[' << l->val.nome << ", " << l->val.cognome << ", " << l->val.numero_matricola << "] ";
        l = l->next;
    }
    cout << endl;
}

p_lista_di_studenti foo(p_lista_di_studenti p)
{
    p_lista_di_studenti iter = p;

    // tolgo i nodi iniziali che non rispettano la condizione
    while (iter != NULL && !(iter->val.numero_matricola % 2 == 0 && iter->val.numero_matricola % 4 != 0))
    {
        p = p->next;
        iter = iter->next;
    }
    // tolgo i nodi intermedi e l'ultimo
    while (iter != NULL && iter->next != NULL)
    {
        if (!(iter->next->val.numero_matricola % 2 == 0 && iter->next->val.numero_matricola % 4 != 0))
        {
            iter->next = iter->next->next;
        }
        else
        {
            iter = iter->next;
        }
    }

    return p;
}

int main()
{
    cout << "lista già preparata\n";

    p_lista_di_studenti lis = new lista_di_studenti;
    
    strncpy(lis->val.nome, "Simone", L);
    strncpy(lis->val.cognome, "Canova", L);
    lis->val.numero_matricola = 12;

    lis->next = new lista_di_studenti;

    strncpy(lis->next->val.nome, "Luca", L);
    strncpy(lis->next->val.cognome, "Canova", L);
            lis->next->val.numero_matricola = 14;

    lis->next->next = new lista_di_studenti;

    strncpy(lis->next->next->val.nome, "Giorgio", L);
    strncpy(lis->next->next->val.cognome, "Canova", L);
            lis->next->next->val.numero_matricola = 12;

    lis->next->next->next = new lista_di_studenti;

    strncpy(lis->next->next->next->val.nome, "Anna", L);
    strncpy(lis->next->next->next->val.cognome, "Canova", L);
            lis->next->next->next->val.numero_matricola = 18;

    lis->next->next->next->next = new lista_di_studenti;

    strncpy(lis->next->next->next->next->val.nome, "Matteo", L);
    strncpy(lis->next->next->next->next->val.cognome, "Canova", L);
            lis->next->next->next->next->val.numero_matricola = 12;

    stampa(lis);

    lis = foo(lis);

    stampa(lis);

    return 0;
}