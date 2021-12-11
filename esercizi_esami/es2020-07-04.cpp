/*
ESERCIZIO [4/7/2019]
Definire una classe Stabilimento con un campo che contiene il numero di ombrelloni, un altro il numero di sdraio, un altro la lista di ospiti. Ogni ospite ha un nome (una stringa di 10 caratteri), un campo numero ombrelloni affittato e un campo numero sdraio affittato. Definire
1. il costruttore che inizializza ombrelloni e sdraio di uno stabilimento;
2. un metodo insert che inserisce un nuovo ospite (se possibile);
3. un metodo remove che prende il nome dell’ospite e lo rimuove dalla lista (la sua vacanza è finita).
4. Definire una sottoclasse Stabilimento Plus che ha due ulteriori campi con il costo degli ombrelloni e quello delle sdraio. Definire
(a) il costruttore;
(b) un metodo che ritorna il guadagno che si ha dagli ospiti attualmente presenti nello stabilimento.
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Ospite
{
    char nome[10];
    int numero_ombrelloni_affittato;
    int numero_sdraio_affittato;
};

struct Node
{
    Ospite ospite;
    Node *next = NULL;
};

typedef Node *pNode;

class Stabilimento
{
    protected:
    int numero_ombrelloni = 0;
    int numero_sdraio = 0;
    pNode lista_ospiti;
    public:
    Stabilimento(int no, int ns, pNode lista = NULL)
    {
        this->numero_ombrelloni = no;
        this->numero_sdraio = ns;
        this->lista_ospiti = lista;
    }
    void insert(Ospite o)
    {
        bool finito = false;
        if (lista_ospiti == NULL)
        {
            if (this->numero_ombrelloni >= o.numero_ombrelloni_affittato && this->numero_sdraio >= o.numero_sdraio_affittato)
            {
                lista_ospiti = new Node;
                strcpy(lista_ospiti->ospite.nome, o.nome);
                lista_ospiti->ospite.numero_ombrelloni_affittato = o.numero_ombrelloni_affittato;
                lista_ospiti->ospite.numero_sdraio_affittato = o.numero_sdraio_affittato;
                finito = true;
            }
        }
        pNode iter = lista_ospiti;
        int sum_sdraio = lista_ospiti->ospite.numero_sdraio_affittato, sum_ombrelloni = lista_ospiti->ospite.numero_ombrelloni_affittato;
        while (!finito && iter->next != NULL)
        {
            sum_ombrelloni += iter->next->ospite.numero_ombrelloni_affittato;
            sum_sdraio += iter->next->ospite.numero_sdraio_affittato;
            iter = iter->next;
        }
        if (!finito && this->numero_ombrelloni >= o.numero_ombrelloni_affittato + sum_ombrelloni && this->numero_sdraio >= o.numero_sdraio_affittato + sum_sdraio)
        {
            iter->next = new Node;
            strcpy(iter->next->ospite.nome, o.nome);
            iter->next->ospite.numero_ombrelloni_affittato = o.numero_ombrelloni_affittato;
            iter->next->ospite.numero_sdraio_affittato = o.numero_sdraio_affittato;
        }
    }
    void remove(char nome[])
    {
        bool finito = false;
        if (lista_ospiti != NULL)
        {
            if (!strcmp(lista_ospiti->ospite.nome, nome))
            {
                lista_ospiti = lista_ospiti->next;
                finito = true;
            }
        }
        else
        {
            finito = true;
        }
        pNode iter = lista_ospiti;
        while (!finito && iter->next != NULL)
        {
            if (!strcmp(iter->next->ospite.nome, nome))
            {
                iter->next = iter->next->next;
                finito = true;
            }
            iter = iter->next;
        }
    }
};

class StabilimentoPlus : public Stabilimento
{
    protected:
    double costo_ombrellone;
    double costo_sdraio;
    public:
    StabilimentoPlus(int no, int ns, double co, double cs, pNode lista = NULL) : Stabilimento(no, ns, lista)
    {
        this->costo_ombrellone = co;
        this->costo_sdraio = cs;
    }
    double guadagno()
    {
        double sum = 0;
        pNode iter = this->lista_ospiti;
        while (iter != NULL)
        {
            sum += iter->ospite.numero_ombrelloni_affittato * this->costo_ombrellone + iter->ospite.numero_sdraio_affittato * this->costo_sdraio;
            iter = iter->next;
        }
        return sum;
    }
};




int main()
{
    Ospite osp1 = {"cioni", 10, 10};
    Ospite osp2 = {"canova", 2, 4};
    Ospite osp3 = {"luca", 5, 8};

    Stabilimento s1 = Stabilimento(100, 100);
    StabilimentoPlus s2 = StabilimentoPlus(100, 100, 14.99, 4.99);

    s1.insert(osp1);
    s1.insert(osp2);
    s1.insert(osp3);

    s1.remove(osp1.nome);
    //s1.remove(osp2.nome);
    //s1.remove(osp3.nome);


    s2.insert(osp1);
    s2.insert(osp2);
    s2.insert(osp3);

    //s2.remove(osp1.nome);
    //s2.remove(osp2.nome);
    s2.remove(osp3.nome);

    cout << s2.guadagno() << endl;

    return 0;
}