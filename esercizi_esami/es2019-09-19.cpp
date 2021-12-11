#include <iostream>

using namespace std;

struct Corso
{
    int indice = -1;
    int cfu = 0;
};

struct Node
{
    Corso corso;
    Node *next = NULL;
};

typedef Node *pNode;

class MioCorsoDiStudi
{
protected:
    int numeroMatricola = 0;
    pNode listaCorsi;

public:
    MioCorsoDiStudi(int numMat, pNode l = NULL)
    {
        this->numeroMatricola = numMat;
        this->listaCorsi = l;
    }
    void aggiungereCorso(int cfu)
    {
        if (this->listaCorsi == NULL)
        {
            this->listaCorsi = new Node;
            this->listaCorsi->corso.cfu = cfu;
            this->listaCorsi->corso.indice = 1;
        }
        else
        {
            pNode iter = this->listaCorsi;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            int i = iter->corso.indice;
            iter->next = new Node;
            iter->next->corso.indice = i + 1;
            iter->next->corso.cfu = cfu;
        }
    }
    int numerodiore()
    {
        int sum = 0;
        pNode iter = this->listaCorsi;
        while (iter != NULL)
        {
            sum += iter->corso.cfu * 25;
            iter = iter->next;
        }
        return sum;
    }
};

class MioCorsoDiStudiPlus : public MioCorsoDiStudi
{
    protected:
    pNode listaEsercitazioni;
    public:
    MioCorsoDiStudiPlus(int numMat, pNode lisC = NULL, pNode lisE = NULL) : MioCorsoDiStudi(numMat, lisC)
    {
        this->listaEsercitazioni = lisE;
    }
    void aggiungereEsercitazione(int cfu)
    {
        if (this->listaEsercitazioni == NULL)
        {
            this->listaEsercitazioni = new Node;
            this->listaEsercitazioni->corso.cfu = cfu;
            this->listaEsercitazioni->corso.indice = 1;
        }
        else
        {
            pNode iter = this->listaEsercitazioni;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            int i = iter->corso.indice;
            iter->next = new Node;
            iter->next->corso.indice = i + 1;
            iter->next->corso.cfu = cfu;
        }
    }
    int numerodiore()
    {
        int sum = MioCorsoDiStudi::numerodiore();
        cout << "test: " << sum << endl;
        pNode iter = this->listaEsercitazioni;
        while (iter != NULL)
        {
            sum += iter->corso.cfu * 12;
            cout << iter->corso.indice << ", " << iter->corso.cfu << endl;
            iter = iter->next;
        }
        return sum;
    }
};

int main()
{
    MioCorsoDiStudi s1 = MioCorsoDiStudi(123);
    s1.aggiungereCorso(11);
    s1.aggiungereCorso(12);
    s1.aggiungereCorso(13);
    s1.aggiungereCorso(14);
    s1.aggiungereCorso(15);
    s1.aggiungereCorso(16);

    cout << s1.numerodiore() << endl;

    MioCorsoDiStudiPlus s2 = MioCorsoDiStudiPlus(234);
    s2.aggiungereCorso(11);
    s2.aggiungereCorso(12);
    s2.aggiungereCorso(13);
    s2.aggiungereCorso(14);
    s2.aggiungereCorso(15);
    s2.aggiungereCorso(16);
    s2.aggiungereEsercitazione(11);
    s2.aggiungereEsercitazione(12);
    s2.aggiungereEsercitazione(13);
    s2.aggiungereEsercitazione(14);
    s2.aggiungereEsercitazione(15);
    s2.aggiungereEsercitazione(16);

    cout << s2.numerodiore() << endl;

    return 0;
}