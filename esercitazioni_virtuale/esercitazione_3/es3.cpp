#include <iostream>
#include <string.h>

#define L 100

using namespace std;

class Libro
{
protected:
    char nome[L];
    double prezzo;
    int numero_copie;

public:
    //Libro(char n[L] = "nome di default", double p = 9.99, int nc = 0)
    Libro(char n[L], double p, int nc)
    {
        strcpy(this->nome, n);
        this->prezzo = p;
        this->numero_copie = nc;
    }
    void vendi_copie(int n)
    {
        this->numero_copie += n;
    }
    double ricavo()
    {
        return this->prezzo * this->numero_copie;
    }
};

class LibroNuovo : public Libro
{
protected:
    int codice;

public:
    LibroNuovo(char n[L], double p, int nc, int c) : Libro(n, p, nc)
    {
        this->codice = c;
    }
    void stampa_codice()
    {
        cout << this->codice;
    }
};

int main()
{
    Libro l1 = Libro("il nome della rosa", 8.99, 1000);
    LibroNuovo l2 = LibroNuovo("PERCHÈ CAZZO CIONI È TORNATO A GIOCARE A COC", 13.99, 100, 666);
    Libro l3 = Libro("pinco pallo", 18.99, 200);
    cout << l1.ricavo() << "\n" << l2.ricavo() << "\n" << l3.ricavo() << "\n";
    l2.stampa_codice();
    cout << endl;
    return 0;
}