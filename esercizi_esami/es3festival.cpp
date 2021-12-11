#include <iostream>
#include <cstring>

#define L 10

using namespace std;

struct Ospite
{
    char nome[L];
    double costo;
    double minutiPerformance;
};

struct Node
{
    Ospite ospite;
    Node *next = NULL;
};

typedef Node *pNode;

class OspitiFestival
{
    protected:
    int numeroOspiti = 0;
    pNode listaOspiti = NULL;
    public:
    OspitiFestival() { }
    void inserisci(Ospite ospite)
    {
        if (this->numeroOspiti == 0)
        {
            this->listaOspiti = new Node;
            strcpy(this->listaOspiti->ospite.nome, ospite.nome);
            this->listaOspiti->ospite.costo = ospite.costo;
            this->listaOspiti->ospite.minutiPerformance = ospite.minutiPerformance;
            this->numeroOspiti++;
        }
        else
        {
            pNode iter = this->listaOspiti;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = new Node;
            strcpy(iter->next->ospite.nome, ospite.nome);
            iter->next->ospite.costo = ospite.costo;
            iter->next->ospite.minutiPerformance = ospite.minutiPerformance;
            this->numeroOspiti++;
        }
    }
    string ospitePiuCostoso()
    {
        int tmp = 0, max = 0;
        pNode iter = this->listaOspiti;
        while (iter != NULL)
        {
            tmp = iter->ospite.costo;
            if (tmp > max)
            {
                max = tmp;
            }
            iter = iter->next;
        }
        iter = this->listaOspiti;
        while (iter != NULL)
        {
            if (iter->ospite.costo == max)
            {
                return iter->ospite.nome;
            }
            iter = iter->next;
        }
        return "Nessun ospite previsto";
    }
};

class OspitiFestivalPlus : public OspitiFestival
{
    protected:
    double costoTotaleOspiti = 0;
    public:
    OspitiFestivalPlus() { }
    void inserisci(Ospite ospite)
    {
        if (this->numeroOspiti == 0)
        {
            this->listaOspiti = new Node;
            strcpy(this->listaOspiti->ospite.nome, ospite.nome);
            this->listaOspiti->ospite.costo = ospite.costo;
            this->listaOspiti->ospite.minutiPerformance = ospite.minutiPerformance;
            this->costoTotaleOspiti += ospite.costo;
            this->numeroOspiti++;
        }
        else
        {
            pNode iter = this->listaOspiti;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = new Node;
            strcpy(iter->next->ospite.nome, ospite.nome);
            iter->next->ospite.costo = ospite.costo;
            iter->next->ospite.minutiPerformance = ospite.minutiPerformance;
            this->costoTotaleOspiti += ospite.costo;
            this->numeroOspiti++;
        }
    }
    double costoMedioOspiti()
    {
        if (this->numeroOspiti != 0) this->costoTotaleOspiti / this->numeroOspiti;
        else return 0;
    }
};

int main()
{
    Ospite o1 = {"Luca", 100, 12};
    Ospite o2 = {"Cioni", 200, 20};
    Ospite o3 = {"Simone", 10, 2};
    Ospite o4 = {"Giulia", 20, 5};

    OspitiFestivalPlus f = OspitiFestivalPlus();
    //f.inserisci(o1);
    //f.inserisci(o2);
    //f.inserisci(o3);
    //f.inserisci(o4);
    cout << f.ospitePiuCostoso() << endl;
    cout << f.costoMedioOspiti() << endl;

    return 0;
}