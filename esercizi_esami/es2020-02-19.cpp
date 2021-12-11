/*
ESERCIZIO [19/2/2020]
Un multinsieme è una collezione di oggetti con la loro molteplicità. Un semplice multinsieme è la borsa. Nella borsa ci sono 10 mele, 3 pere, 1 kiwi. Quindi è il multinsieme:
borsa = {10 · mela, 3 · pera, 1 · kiwi}
Su un multinsieme è possibile eseguire le operazioni di add, che aggiunge un elemento al multinsieme, e remove, che elimina un elemento dal multinsieme. Ad esempio: addmelaborsa = {11·mela,3·pera,1·kiwi}
removekiwiborsa = {10·mela,3·pera}
(a) Definire la classe multinsieme il cui tipo degli elementi che contiene è int (ad esempio {11 · 0, 328 · −1234} contiene 11 volte 0 e contiene 328 volte −1234) con i metodi add e remove (Il metodo remove, quando l’elemento non c’è, non rimuove nulla).
(b) Definire la sotto-classe multinsiemeplus con l’ulteriore metodo addplus che prende in input un elemento e la sua molteplicità e aggiorna il proprio multinsieme aggiungendo quell’elemento con la relativa molteplicità. Il metodo addplus deve utilizzare il metodo add della superclasse.
*/

#include <iostream>

using namespace std;

struct Node
{
    int elemento;
    int quantità = 0;
    Node *next = NULL;
};

typedef Node *pNode;

class Multinsieme
{
protected:
    pNode contenuto;

public:
    Multinsieme(pNode l = NULL)
    {
        this->contenuto = l;
    }
    void add(int e)
    {
        bool finito = false;
        if (this->contenuto == NULL)
        {
            this->contenuto = new Node;
            this->contenuto->elemento = e;
            this->contenuto->quantità++;
            finito = true;
        }
        else if (this->contenuto->elemento == e)
        {
            this->contenuto->quantità++;
            finito = true;
        }
        pNode iter = this->contenuto;
        while (iter->next != NULL && !finito)
        {
            if (iter->next->elemento == e)
            {
                iter->next->quantità++;
                finito = true;
            }
            else
            {
                iter = iter->next;
            }
        }
        if (!finito && iter->elemento == e)
        {
            iter->quantità++;
        }
        else if (!finito)
        {
            iter->next = new Node;
            iter->next->quantità++;
            iter->next->elemento = e;
        }
    }
    void remove(int e)
    {
        bool finito = false;
        if (this->contenuto->elemento == e)
        {
            if (this->contenuto->quantità > 1)
            {
                this->contenuto->quantità--;
                finito = true;
            }
            else
            {
                this->contenuto = this->contenuto->next;
                finito = true;
            }
        }
        pNode iter = this->contenuto;
        while (!finito && iter->next != NULL)
        {
            if (iter->next->elemento == e)
            {
                if (iter->next->quantità > 1)
                {
                    iter->next->quantità--;
                    finito = true;
                }
                else
                {
                    iter->next = iter->next->next;
                    finito = true;
                }
            }
            iter = iter->next;
        }
        if (!finito && iter->elemento == e)
        {
            if (iter->quantità > 1)
            {
                iter->quantità--;
            }
            else
            {
                iter = NULL;
            }
        }
    }
    void stampa()
    {
        cout << "\n{";
        pNode iter = this->contenuto;
        while (iter != NULL)
        {
            cout << iter->quantità << " * " << iter->elemento << ", ";
            iter = iter->next;
        }
        cout << "}\n";
    }
};

class MultinsiemePlus : public Multinsieme
{
public:
    using Multinsieme::Multinsieme;
    void addplus(int q, int e)
    {
        for (int i = 0; i < q; i++)
        {
            this->add(e);
        }
    }
    void removeplus(int q, int e)
    {
        for (int i = 0; i < q; i++)
        {
            this->remove(e);
        }
    }
};

int main()
{
    MultinsiemePlus m = MultinsiemePlus();

    m.addplus(12, 1);
    m.addplus(13, 2);
    m.addplus(14, 3);

    m.stampa();

    m.removeplus(2, 1);
    m.removeplus(3, 2);
    m.removeplus(4, 3);

    m.stampa();
    return 0;
}