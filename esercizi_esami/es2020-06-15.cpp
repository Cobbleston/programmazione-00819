/*
ESERCIZIO [15/6/2020]
Un punto di ritiro spedizioni può ricevere un qualunque numero di pacchi. Ogni pacco è contraddistinto da un numero di ordine e una dimensione (entrambi sono rappresentatati da un intero, la dimensione indica il volume).
(a) Definire la classe PuntoRitiro con i campi opportuni e con i metodi aggiungi che aggiunge un pacco al punto di ritiro (controllando che non ci siano due pacchi con lo stesso numero d’ordine) e rimuovi che rimuove un pacco in base al numero d’ordine.
(b) Definire la sottoclasse Locker che è un punto di ritiro con un numero fissato di box. Ogni box può contenere un solo pacco e i box di un Locker possono contenere pacchi fino a una certa dimensione massima.
i. Definire il costruttore Locker che determina il numero dei box e le dimensione massima dei pacchi che possono contenere.
ii. Riscrivere i metodi aggiungi e rimuovi. Il metodo aggiungi stampa errore se il Locker è pieno oppure quando la dimensione del pacco è troppo grande.
*/
#include <iostream>

using namespace std;

struct Pacco
{
    int numero_ordine = 0;
    int volume = 0;
};

struct Node
{
    Pacco pacco;
    Node *next = NULL;
};

typedef Node *pNode;

class PuntoRitiro
{
protected:
    pNode lista_pacchi;

public:
    PuntoRitiro()
    {
        this->lista_pacchi = NULL;
    }
    void aggiungi_pacco(Pacco p)
    {
        if (this->lista_pacchi == NULL)
        {
            this->lista_pacchi = new Node;
            this->lista_pacchi->pacco = p;
        }
        else
        {
            pNode iter = this->lista_pacchi;
            bool finito = false;
            while (iter != NULL && !finito)
            {
                if (iter->pacco.numero_ordine == p.numero_ordine)
                {
                    finito = true;
                }
                if (iter->next == NULL && !finito)
                {
                    iter->next = new Node;
                    iter->next->pacco = p;
                    finito = true;
                }
                iter = iter->next;
            }
        }
    }
    void rimuovi_pacco(int c)
    {
        bool finito = false;
        if (this->lista_pacchi == NULL)
        {
            finito = true;
        }
        else if (this->lista_pacchi->pacco.numero_ordine == c)
        {
            this->lista_pacchi = this->lista_pacchi->next;
        }
        pNode iter = this->lista_pacchi;
        while (iter->next != NULL && !finito)
        {
            if (iter->next->pacco.numero_ordine == c)
            {
                iter->next = iter->next->next;
                finito = true;
            }
            else
            {
                iter = iter->next;
            }
        }
        if (!finito && iter->pacco.numero_ordine == c)
        {
            iter = NULL;
        }
    }
    void stampa()
    {
        pNode iter = this->lista_pacchi;
        while (iter != NULL)
        {
            cout << iter->pacco.numero_ordine << '\t' << iter->pacco.volume << endl;
            iter = iter->next;
        }
        cout << "\n\n";
    }
};

class Locker : public PuntoRitiro
{
protected:
    int pacchi_contenuti = 0;
    int capacita_massima = 0;
    int volume_massimo = 0;

public:
    Locker(int cap, int vol) : PuntoRitiro()
    {
        this->capacita_massima = cap;
        this->volume_massimo = vol;
    }
    void aggiungi_pacco(Pacco p)
    {
        if (this->lista_pacchi == NULL)
        {
            if (this->pacchi_contenuti + 1 <= this->capacita_massima && p.volume <= this->volume_massimo)
            {
                this->lista_pacchi = new Node;
                this->lista_pacchi->pacco = p;
                this->pacchi_contenuti++;
            }
            else
            {
                cout << "Troppi pacchi o volume troppo grosso" << endl;
            }
        }
        else
        {
            pNode iter = this->lista_pacchi;
            bool finito = false;
            while (iter != NULL && !finito)
            {
                if (iter->pacco.numero_ordine == p.numero_ordine)
                {
                    finito = true;
                }
                if (iter->next == NULL && !finito)
                {
                    if (!finito && this->pacchi_contenuti + 1 <= this->capacita_massima && p.volume <= this->volume_massimo)
                    {
                        iter->next = new Node;
                        iter->next->pacco = p;
                        this->pacchi_contenuti++;
                        finito = true;
                    }
                    else
                    {
                        cout << "Troppi pacchi o volume troppo grosso: " << p.volume << ", " << this->capacita_massima << " vs " << this->pacchi_contenuti+1 << endl;
                        finito = true;
                    }
                }
                iter = iter->next;
            }
        }
    }
    void rimuovi_pacco(int c)
    {
        bool finito = false;
        pNode iter = this->lista_pacchi;
        if (this->lista_pacchi->pacco.numero_ordine == c)
        {
            this->lista_pacchi = this->lista_pacchi->next;
            finito = true;
        }
        while (iter->next != NULL && !finito)
        {
            if (iter->next->pacco.numero_ordine == c)
            {
                iter->next = iter->next->next;
                finito = true;
                this->pacchi_contenuti--;
            }
            else
            {
                iter = iter->next;
            }
        }
        if (!finito && iter->pacco.numero_ordine == c)
        {
            iter = NULL;
            this->pacchi_contenuti--;
        }
    }
};

int main()
{
    PuntoRitiro casa = PuntoRitiro();

    casa.aggiungi_pacco({4, 5});
    casa.aggiungi_pacco({4, 5});
    casa.aggiungi_pacco({5, 5});
    casa.aggiungi_pacco({1, 5});
    casa.aggiungi_pacco({2, 5});
    casa.aggiungi_pacco({3, 5});
    casa.aggiungi_pacco({1, 5});
    casa.aggiungi_pacco({3, 5});
    casa.aggiungi_pacco({8, 5});
    casa.aggiungi_pacco({2, 5});

    casa.rimuovi_pacco(4);
    casa.rimuovi_pacco(1);
    casa.rimuovi_pacco(8);

    Locker elias_pieno = Locker(10, 20);

    elias_pieno.aggiungi_pacco({5, 5});
    elias_pieno.aggiungi_pacco({5, 5});
    elias_pieno.aggiungi_pacco({6, 5});
    elias_pieno.aggiungi_pacco({7, 25});
    elias_pieno.aggiungi_pacco({8, 5});
    elias_pieno.aggiungi_pacco({9, 5});
    elias_pieno.aggiungi_pacco({10, 5});

    elias_pieno.rimuovi_pacco(5);
    elias_pieno.rimuovi_pacco(8);
    elias_pieno.rimuovi_pacco(10);

    casa.stampa();
    elias_pieno.stampa();

    return 0;
}