#include <iostream>
#include <string.h>

#define L 100

using namespace std;

struct Squadra
{
    char nome[L];
    int scudettiVinti = 0;
};

class Calciatore
{
    protected:
    Squadra squadra;
    char nome[L];
    int golFatti;
    public:
    Calciatore(Squadra squadra, char nome[], int golFatti = 0)
    {
        this->squadra = squadra;
        strcpy(this->nome, nome);
        this->golFatti = golFatti;
    }
    void segna(int n = 1)
    {
        this->golFatti += n;
    }
    bool squadraScarsa()
    {
        return this->squadra.scudettiVinti == 0;
    }
};

class Portiere : public Calciatore
{
    protected:
    int golSubiti;
    public:
    Portiere(Squadra squadra, char nome[], int golFatti = 0, int golSubiti = 0) : Calciatore(squadra, nome, golFatti)
    {
        this->golSubiti = golSubiti;
    }
    void prende(int n = 1)
    {
        this->golSubiti += n;
    }
};

int main()
{
    Squadra bo;
    strcpy(bo.nome, "Bologna");
    bo.scudettiVinti = 0;
    Squadra mi;
    strcpy(mi.nome, "Milan");
    mi.scudettiVinti = 2;
    Calciatore g1 = Calciatore(bo, "Diamanti", 3);
    Portiere g2 = Portiere(bo, "Port", 0, 12);
    Calciatore g3 = Calciatore(mi, "Ciccio", 12);
    g1.segna();
    g1.segna(2);
    g2.segna();
    g2.prende(10);
    g3.segna();
    cout << g1.squadraScarsa() << endl;
    cout << g2.squadraScarsa() << endl;
    cout << g3.squadraScarsa() << endl;
    return 0;
}