#include <iostream>
#include <cstring>

#define N 3
#define L 100

using namespace std;

class Gelato
{
    protected:
    int numeroGusti = 0;
    char nomeGusto1[L];
    char nomeGusto2[L];
    char nomeGusto3[L];
    double costo = 0;
    Gelato() { }
    public:
    void aggiungiGelato(char nome[])
    {
        if (numeroGusti == 0)
        {
            strcpy(nomeGusto1, nome);
            numeroGusti++;
        }
        else if (numeroGusti == 1)
        {
            strcpy(nomeGusto2, nome);
            numeroGusti++;
        }
        else if (numeroGusti == 2)
        {
            strcpy(nomeGusto3, nome);
            numeroGusti++;
        }
        else
        {
            cout << "Hai già 3 gusti: " << nomeGusto1 << ", " << nomeGusto2 << " e " << nomeGusto3 << endl;
        }
    }
    double calcolaPrezzo()
    {
        return costo;
    }
};

class Cono : public Gelato
{
    public:
    Cono() : Gelato()
    {
        this->costo = 2.7;
    }
};

class Coppetta : public Gelato
{
    public:
    Coppetta() : Gelato()
    {
        this->costo = 2;
    }
};

class Cestina : public Gelato
{
    public:
    Cestina() : Gelato()
    {
        this->costo = 2.5;
    }
};

int main()
{
    Cono g2 = Cono();
    Coppetta g3 = Coppetta();
    Cestina g4 = Cestina();

    g2.aggiungiGelato("Stracciatella");
    g2.aggiungiGelato("Pistaccio");

    cout << g2.calcolaPrezzo() << endl;

    g3.aggiungiGelato("Amarena");
    g3.aggiungiGelato("Cioccolato");

    cout << g3.calcolaPrezzo() << endl;
    cout << g4.calcolaPrezzo() << endl;

    return 0;
}