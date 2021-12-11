#include <iostream>
#include <string.h>

#define L 100

using namespace std;

struct Squadra
{
    int punti_ottenuti = 0;
    char nome[L];
};

struct Partita
{
    Squadra *p_primaSquadra;
    Squadra *p_secondaSquadra;
    int gol_prima = 0;
    int gol_seconda = 0;
};

struct NodeSquadre
{
    Squadra squadra;
    NodeSquadre *next = NULL;
};

struct NodePartite
{
    Partita partita;
    NodePartite *next = NULL;
};

typedef NodeSquadre *pNodeSquadre;
typedef NodePartite *pNodePartite;

int partite_pareggio(pNodePartite l_partite)
{
    int res = 0;
    pNodePartite iter = l_partite;
    while (iter != NULL)
    {
        if (iter->partita.gol_prima == iter->partita.gol_seconda)
        {
            res++;
        }
        iter = iter->next;
    }
    return res;
}

pNodeSquadre squadre_forti(pNodeSquadre l_squadre)
{
    pNodeSquadre backup = NULL;
    pNodeSquadre head = NULL;
    pNodeSquadre iter = l_squadre;
    while (iter != NULL)
    {
        if (iter->squadra.punti_ottenuti >= 10)
        {
            if (head == NULL)
            {
                head = new NodeSquadre;
                head->squadra.punti_ottenuti = iter->squadra.punti_ottenuti;
                strcpy(head->squadra.nome, iter->squadra.nome);
                backup = head;
            }
            else
            {
                head = head->next;
                head = new NodeSquadre;
                head->squadra.punti_ottenuti = iter->squadra.punti_ottenuti;
                strcpy(head->squadra.nome, iter->squadra.nome);
            }
        }
        iter = iter->next;
    }
    return backup;
}

int main()
{
    return 0;
}