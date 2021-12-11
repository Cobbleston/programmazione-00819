#include <iostream>

using namespace std;

class Orologio
{
protected:
    int ore;
    int minuti;
    int secondi;

public:
    Orologio(int ore = 0, int minuti = 0, int secondi = 0)
    {
        if (ore >= 0 && ore <= 23 && minuti >= 0 && minuti <= 59 && secondi >= 0 && secondi <= 59)
        {
            this->ore = ore;
            this->minuti = minuti;
            this->secondi = secondi;
        }
    }
    void impostare(int ore, int minuti, int secondi)
    {
        if (ore >= 0 && ore <= 23 && minuti >= 0 && minuti <= 59 && secondi >= 0 && secondi <= 59)
        {
            this->ore = ore;
            this->minuti = minuti;
            this->secondi = secondi;
        }
        else
        {
            cout << "Orario non valido" << endl;
        }
    }
    void tick()
    {
        if (this->secondi < 59)
        {
            this->secondi++;
        }
        else if (this->minuti < 59)
        {
            this->minuti++;
            this->secondi = 0;
        }
        else if (this->ore < 23)
        {
            this->ore++;
            this->minuti = 0;
        }
        else
        {
            this->impostare(0, 0, 0);
        }
    }
    int seconds()
    {
        return this->ore * 3600 + this->minuti * 60 + this->secondi;
    }
};

class OrologioConDoppioFormato : public Orologio
{
public:
    OrologioConDoppioFormato(int ore = 0, int minuti = 0, int secondi = 0) : Orologio(ore, minuti, secondi) {}
    void stampa24h()
    {
        cout << this->ore << ':' << this->minuti << ':' << this->secondi << endl;
    }
    void stampa12h()
    {
        if (this->ore < 13)
        {
            cout << this->ore << ':' << this->minuti << ':' << this->secondi << " AM" << endl;
        }
        else
        {
            cout << this->ore - 12 << ':' << this->minuti << ':' << this->secondi << " PM" << endl;
        }
    }
};

int main()
{
    OrologioConDoppioFormato clock = OrologioConDoppioFormato(0, 12, 45);
    clock.tick();
    cout << clock.seconds() << endl;
    clock.impostare(33, 14, 59);
    clock.impostare(13, 14, 59);
    clock.stampa24h();
    clock.stampa12h();
    clock.impostare(4, 14, 59);
    clock.stampa12h();
    clock.tick();
    clock.stampa12h();
    return 0;
}