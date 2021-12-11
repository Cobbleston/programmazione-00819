/*
ESERCIZIO [21/7/2020]
Ogni studente della laurea triennale ha un piano di studi, rappresentato da un insieme fisso di corsi (ogni studente deve fare gli stessi esami). I corsi universitari sono caratterizzati da un codice identificativo (un intero), i crediti formativi (CFU, anche essi interi), e il voto che lo studente ha preso (rappresentato da un intero maggiore o uguale a 18, che viene posto a 0 se lo studente non ha ancora sostenuto l’esame o non l’ha superato).
Definire le strutture dati necessarie e la classe PianoStudiTriennale con un costruttore e i seguenti metodi:
1. un metodo esame sostenuto, il quale prende in input il codice del corso e il voto che lo studente ha ottenuto e cambia la votazione finale;
2. un metodo calcola media ponderata, che calcola la media ponderata degli esami sostenuti ed eliminando dal conteggio il voto peggiore.
3. un metodo idoneo laurea che controlla se lo studente può laurearsi (verificando che abbia sostenuto tutti gli esami).
Definire poi una sottoclasse PianoStudiMaster che aggiunge anche il tirocinio al piano di studi dello studente. Il valore del tirocinio è true se il tirocinio è già stato svolto, false altrimenti. Definire il costruttore e i seguenti metodi:
1. il metodo calcola media ponderata (sovrascritto) che calcola la media ponderata degli esami sostenuti senza eliminare il voto peggiore.
2. il metodo idoneo laurea (sovrascritto) che considera anche il tirocinio.
*/

#include <iostream>
#define N 3

using namespace std;

struct Corso
{
    int cod = -1;
    int cfu = -1;
    int voto = 0;
};

class PianoStudiTriennale
{
protected:
    Corso elenco_corsi[N];

public:
    PianoStudiTriennale(Corso e[])
    {
        for (int i = 0; i < N; i++)
        {
            this->elenco_corsi[i] = e[i];
        }
    }
    void esame_sostenuto(int c, int v)
    {
        for (int i = 0; i < N; i++)
        {
            if (this->elenco_corsi[i].cod == c)
            {
                this->elenco_corsi[i].voto = v;
            }
        }
    }
    double calcola_media_ponderata()
    {
        int sum = 0, min = 0, esami_sostenuti = 0;
        for (int i = 0; i < N; i++)
        {
            if (this->elenco_corsi[i].voto != 0)
            {
                esami_sostenuti++;
                sum += this->elenco_corsi[i].voto;
                if (min > this->elenco_corsi[i].voto)
                {
                    min = this->elenco_corsi[i].voto;
                }
            }
        }
        sum -= min;
        return (double)sum / esami_sostenuti;
    }
    bool idoneo_laurea()
    {
        bool finito = false;
        int i = 0;
        while (i < N && !finito)
        {
            if (this->elenco_corsi[i].voto == 0)
            {
                finito = true;
            }
            i++;
        }
        return !finito;
    }
};

class PianoStudiMaster : public PianoStudiTriennale
{
protected:
    bool fatto_tirocinio;

public:
    PianoStudiMaster(Corso e[], bool tir) : PianoStudiTriennale(e)
    {
        this->fatto_tirocinio = tir;
    }
    double calcola_media_ponderata()
    {
        int sum = 0, esami_sostenuti = 0;
        for (int i = 0; i < N; i++)
        {
            if (this->elenco_corsi[i].voto != 0)
            {
                esami_sostenuti++;
                sum += this->elenco_corsi[i].voto;
            }
        }
        return (double)sum / esami_sostenuti;
    }

    bool idoneo_laurea()
    {
        bool finito = false;
        int i = 0;
        while (i < N && !finito)
        {
            if (this->elenco_corsi[i].voto == 0)
            {
                finito = true;
            }
            i++;
        }
        return !finito && this->fatto_tirocinio;
    }
};

int main()
{
    Corso c1 = {123, 6};
    Corso c2 = {456, 12};
    Corso c3 = {789, 9};
    Corso arr[N] = {c1, c2, c3};
    PianoStudiTriennale p1 = PianoStudiTriennale(arr);
    PianoStudiMaster p2 = PianoStudiMaster(arr, true);
    PianoStudiMaster p3 = PianoStudiMaster(arr, false);
    
    p1.esame_sostenuto(123, 18);
    p1.esame_sostenuto(456, 22);

    cout << p1.calcola_media_ponderata() << endl;
    cout << p1.idoneo_laurea() << endl;

    p1.esame_sostenuto(789, 21);

    cout << p1.calcola_media_ponderata() << endl;
    cout << p1.idoneo_laurea() << endl;

    cout << "\n\n";

    p2.esame_sostenuto(123, 28);
    p2.esame_sostenuto(456, 22);

    cout << p2.calcola_media_ponderata() << endl;
    cout << p2.idoneo_laurea() << endl;

    p2.esame_sostenuto(789, 21);

    cout << p2.calcola_media_ponderata() << endl;
    cout << p2.idoneo_laurea() << endl;

    cout << "\n\n";

    p3.esame_sostenuto(123, 28);
    p3.esame_sostenuto(456, 22);

    cout << p3.calcola_media_ponderata() << endl;
    cout << p3.idoneo_laurea() << endl;

    p3.esame_sostenuto(789, 21);

    cout << p3.calcola_media_ponderata() << endl;
    cout << p3.idoneo_laurea() << endl;
}