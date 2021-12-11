/*
ESERCIZIO [19/12/2020]
Un impianto sciistico di risalita è caratterizzato da un nome e da un costo di utilizzo (espresso in punti). Definire mediante array il tipo di dato “comprensorio sciistico” che è un insieme finito di impianti di risalita.
In seguito, definire la classe skipass con i campi opportuni in modo da ammettere due tipi di skipass:
(a) quello “Giornaliero”, che può essere utilizzato nell’arco di una sola giornata e non ha limite sul numero di ingressi;
(b) quello “Ricaricabile”, che all’acquisto ha un determinato numero di punti, che verranno scalati ad ogni accesso agli impianti e che dipende dal singolo impianto.
La classe skipass ha i seguenti metodi:
(a) un metodo “accesso” che prende in input il nome di un impianto e una data e consente di accedere all’impianto (decrementando i punti o controllando che lo skipass è valido); [una data è un intero di 8 cifre, le prime 4 sono l’anno, le altre 2 sono i mesi, le ultime due indicano il giorno]
(b) un metodo “ricarica” che prende in input un intero (che indica i punti oppure un giorno) e un booleano (“vero” significa che si vuole ricaricare con un altro giorno, “falso” significa che si vogliono ricaricare punti).
*/

#include <iostream>
#include <string.h>

#define N 5
#define L 100

using namespace std;

struct Impianto
{
    char nome[L] = "";
    int costo = -1;
};

struct PassGiornaliero
{
    int data_attivazione = 0;
};

struct PassRicaricabile
{
    int punti = 0;
};

class SkiPass
{
    protected:
    PassGiornaliero pg;
    PassRicaricabile pr;
    Impianto comprensorio[N];
    public:
    SkiPass(char c, int d, Impianto comp[])
    {
        if (c == 'r')
        {
            pr.punti = 20;
        }
        else if (c == 'g')
        {
            pg.data_attivazione = d;
        }
        for (int i = 0; i < N; i++)
        {
            this->comprensorio[i] = comp[i];
        }
    }
    void accesso(char nome[], int data)
    {
        int i = 0;
        bool finito = false;
        while (i < N)
        {
            if (!finito && !strcmp(nome, comprensorio[i].nome))
            {
                if (!finito && pg.data_attivazione == data)
                {
                    cout << "accesso con pass giornaliero validato" << endl;
                    finito = true;
                }
                else if (!finito && pr.punti >= comprensorio[i].costo)
                {
                    pr.punti -= comprensorio[i].costo;
                    cout << "accesso con pass ricaricabile validato" << endl;
                    finito = true;
                }
                else
                {
                    cout << "accesso non valido" << endl;
                    finito = true;
                }
            }
            i++;
        }
    }
    void ricarica(int num, bool tipo)
    {
        if (tipo)
        {
            pg.data_attivazione = num;
        }
        else
        {
            pr.punti += num;
        }
    }
};

int main()
{
    Impianto i1 = {"Impianto 1", 11};
    Impianto i2 = {"Impianto 2", 12};
    Impianto i3 = {"Impianto 3", 13};
    Impianto i4 = {"Impianto 4", 14};
    Impianto i5 = {"Impianto 5", 15};
    Impianto comprensorio_sciistico[N] = {i1, i2, i3, i4, i5};

    SkiPass sp1 = SkiPass('g', 20210915, comprensorio_sciistico);
    SkiPass sp2 = SkiPass('r', 20210915, comprensorio_sciistico);

    sp1.accesso("Impianto 1", 20210915);
    sp1.accesso("Impianto 2", 20210915);
    sp1.accesso("Impianto 3", 20210916);
    sp1.ricarica(20210916, true);
    sp1.accesso("Impianto 3", 20210916);

    sp2.accesso("Impianto 1", 20210915);
    sp2.accesso("Impianto 1", 20210915);
    sp2.ricarica(20, false);
    sp2.accesso("Impianto 1", 20210915);
    sp2.accesso("Impianto 1", 20210915);
    sp2.accesso("Impianto 1", 20210915);
}