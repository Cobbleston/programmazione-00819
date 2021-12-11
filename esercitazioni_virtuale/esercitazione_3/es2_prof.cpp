#include <iostream>
#include <string.h>

using namespace std;

struct listaSquadre
{
    char nome[40];
    int punti;
    listaSquadre *next;
};

typedef listaSquadre *ptr_listaSquadre;

struct listaPartite
{
    ptr_listaSquadre s1;
    ptr_listaSquadre s2;
    int goal1;
    int goal2;
    listaPartite *next;
};

typedef listaPartite *ptr_listaPartite;

int partiteParita(ptr_listaPartite p)
{
    int num = 0;
    while (p != NULL)
    {
        if (p->goal1 == p->goal2)
        {
            num++;
        }
        p = p->next;
    }
    return num;
}

ptr_listaSquadre piuDieciPunti(ptr_listaSquadre p)
{
    ptr_listaSquadre tmp = NULL;
    ptr_listaSquadre lista = tmp;
    while (p != NULL)
    {
        if (p->punti >= 10)
        {
            if (tmp == NULL)
            {
                tmp = new listaSquadre;
                tmp->punti = p->punti;
                strcpy(tmp->nome, p->nome);
                tmp->next = NULL;
                lista = tmp;
            }
            else
            {
                tmp->next = new listaSquadre;
                tmp = tmp->next;
                tmp->punti = p->punti;
                strcpy(tmp->nome, p->nome);
                tmp->next = NULL;
            }
        }
        p = p->next;
    }
    return lista;
}

// Funzioni ausiliarie per test
ptr_listaSquadre aggiungiSquadra(ptr_listaSquadre p, char nome[], int punti)
{
    ptr_listaSquadre tmp = p;
    if (p == NULL)
    {
        p = new listaSquadre;
        strcpy(p->nome, nome);
        p->punti = punti;
        p->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new listaSquadre;
        tmp = tmp->next;
        strcpy(tmp->nome, nome);
        tmp->punti = punti;
        tmp->next = NULL;
    }
    return p;
}

ptr_listaPartite aggiungiPartita(ptr_listaPartite p, char nome1[40], int punti1, char nome2[40], int punti2)
{
    ptr_listaPartite tmp = p;
    if (p == NULL)
    {
        p = new listaPartite;
        p->s1 = new listaSquadre;
        p->s2 = new listaSquadre;

        strcpy(p->s1->nome, nome1);
        strcpy(p->s2->nome, nome2);
        p->goal1 = punti1;
        p->goal2 = punti2;
        if (punti1 > punti2)
        {
            p->s1->punti = 3;
            p->s2->punti = 0;
        }
        else if (punti1 < punti2)
        {
            p->s2->punti = 3;
            p->s1->punti = 0;
        }
        else
        {
            p->s1->punti = 1;
            p->s2->punti = 1;
        }
        p->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new listaPartite;
        tmp = tmp->next;
        tmp->s1 = new listaSquadre;
        tmp->s2 = new listaSquadre;
        strcpy(tmp->s1->nome, nome1);
        strcpy(tmp->s2->nome, nome2);
        tmp->goal1 = punti1;
        tmp->goal2 = punti2;
        if (punti1 > punti2)
        {
            tmp->s1->punti = 3;
            tmp->s2->punti = 0;
        }
        else if (punti1 < punti2)
        {
            tmp->s2->punti = 3;
            tmp->s1->punti = 0;
        }
        else
        {
            tmp->s1->punti = 1;
            tmp->s2->punti = 1;
        }
        tmp->next = NULL;
    }
    return p;
}

void stampaListaSquadre(ptr_listaSquadre p)
{
    while (p != NULL)
    {
        cout << p->nome << " " << p->punti << endl;
        p = p->next;
    }
    cout << endl;
}

void stampaListaPartite(ptr_listaPartite p)
{
    while (p != NULL)
    {
        cout << p->s1->nome << " - " << p->s2->nome << " " << p->goal1 << " : " << p->goal2 << endl;
        p = p->next;
    }
    cout << endl;
}

int main()
{
    ptr_listaSquadre list_squadre;

    aggiungiSquadra(list_squadre, "benevento", 5);
    aggiungiSquadra(list_squadre, "bologna", 7);

    ptr_listaPartite list_partite = new listaPartite;
    
    aggiungiPartita(list_partite, "benevento", 2, "bologna", 3);

    stampaListaSquadre(list_squadre);
    stampaListaPartite(list_partite);
    return 0;
}