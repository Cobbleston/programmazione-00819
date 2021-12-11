#include <iostream>

using namespace std;

class Abitazione
{
protected:
    int numeroStanze;
    double metratura;

public:
    Abitazione(int numeroStanze, double metratura)
    {
        this->numeroStanze = numeroStanze;
        this->metratura = metratura;
    }
    double costo(double prezzoAlMetroQuadro)
    {
        return prezzoAlMetroQuadro * this->metratura;
    }
};

class Appartamento : public Abitazione
{
protected:
    int piano;

public:
    Appartamento(int numeroStanze, double metratura, int piano) : Abitazione(numeroStanze, metratura)
    {
        this->piano = piano;
    }
};

class Villetta : public Abitazione
{
public:
    Villetta(int numeroStanze, double metratura) : Abitazione(numeroStanze, metratura) {}
    double costo(double prezzoAlMetroQuadro)
    {
        return 1.1 * Abitazione::costo(prezzoAlMetroQuadro);
    }
};

int main()
{
    Abitazione a1 = Abitazione(4, 100);
    Villetta a2 = Villetta(10, 200);
    Appartamento a3 = Appartamento(2, 50, 7);
    
    cout << a1.costo(50) << ", " << a2.costo(50) << ", " << a3.costo(50) << endl;

    return 0;
}