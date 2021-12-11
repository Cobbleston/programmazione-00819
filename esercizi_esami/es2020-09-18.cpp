/*
ESERCIZIO [18/9/2020]
Si consideri un sistema per la gestione delle opere d’arte esposte presso un Museo. Un Museo è caratterizzato da un nome e dalla lista di opere d’arte che ospita. Una opera d’arte è caratterizzata da un codice univoco, un nome, un autore, l’anno in cui è stata realizzata e il numero della stanza in cui è esposta. Per semplicità si assuma che il Museo oggetto di questo esame ha tre stanze e ciascuna stanza può accogliere un numero variabile di opere.
Implementare la classe Museo, che prevede i seguenti metodi:
• aggiungi opera, il quale aggiunge una opera d’arte alla lista di quel Museo. Il metodo deve controllare che l’opera non sia già presente.
Si consideri il caso di un Museo a pagamento. Ciascuna stanza del Museo potrà essere visitata pagando un biglietto. Il prezzo del biglietto dipende dalle opere che vi sono esposte.
• Modificare il metodo aggiungi opera in modo tale da aggiornare il prezzo del biglietto per la stanza in cui è esposta quella opera.
• Implementare il metodo stampa prezzo stanze, che visualizza il prezzo del biglietto per ciascuna stanza nel museo.
*/

#include <iostream>
#include <string.h>

#define L 100

using namespace std;

struct ListaOpere
{
    int codice_univoco = -1;
    char nome[L];
    char autore[L];
    int anno = -1;
    int stanza = -1;
    double prezzo = 0;
    ListaOpere *next;
};

typedef ListaOpere *pListaOpere;

class Museo
{
protected:
    char nome_museo[L];
    pListaOpere lista_opere;

public:
    Museo(char n[], pListaOpere l = new ListaOpere)
    {
        strcpy(this->nome_museo, n);
        this->lista_opere = l;
    }
    void aggiungi_opera(int cod, char n_opera[], char n_autore[], int anno_realizzazione, int nr_stanza)
    {
        bool finito = false;
        if (this->lista_opere->codice_univoco == -1)
        {
            this->lista_opere->codice_univoco = cod;
            strcpy(this->lista_opere->nome, n_opera);
            strcpy(this->lista_opere->autore, n_autore);
            this->lista_opere->anno = anno_realizzazione;
            this->lista_opere->stanza = nr_stanza;
            this->lista_opere->next = NULL;
            finito = true;
        }
        pListaOpere iter = this->lista_opere;
        while (iter != NULL && !finito)
        {
            if (iter->codice_univoco == cod && iter->nome == n_opera && iter->autore == n_autore && iter->anno == anno_realizzazione && iter->stanza == nr_stanza)
            {
                finito = true;
            }
            else if (iter->next == NULL)
            {
                iter->next = new ListaOpere;
                iter->next->codice_univoco = cod;
                strcpy(iter->next->nome, n_opera);
                strcpy(iter->next->autore, n_autore);
                iter->next->anno = anno_realizzazione;
                iter->next->stanza = nr_stanza;
                iter->next->next = NULL;
                finito = true;
            }
            iter = iter->next;
        }
    }
    void stampa_stanze()
    {
        double sum = 0;
        for (int i = 1; i < 4; i++)
        {
            sum = 0;
            cout << "Stanza numero " << i << ":" << endl;
            pListaOpere iter = this->lista_opere;
            while (iter != NULL)
            {
                if (iter->stanza == i)
                {
                    sum += iter->prezzo;
                    cout << '\t' << iter->codice_univoco << '\t' << iter->nome << '\t' << iter->autore << '\t' << iter->anno << '\t' << iter->prezzo << endl;
                }
                iter = iter->next;
            }
            cout << "Prezzo totale stanza numero " << i << ": " << sum << "\n\n";
        }
    }
};

class MuseoAPagamento : public Museo
{
public:
    MuseoAPagamento(char n[], pListaOpere l = new ListaOpere) : Museo(n, l) {}
    
    void aggiungi_opera(int cod, char n_opera[], char n_autore[], int anno_realizzazione, int nr_stanza, double prezzo)
    {
        bool finito = false;
        if (this->lista_opere->codice_univoco == -1)
        {
            this->lista_opere->codice_univoco = cod;
            strcpy(this->lista_opere->nome, n_opera);
            strcpy(this->lista_opere->autore, n_autore);
            this->lista_opere->anno = anno_realizzazione;
            this->lista_opere->stanza = nr_stanza;
            this->lista_opere->prezzo = prezzo;
            this->lista_opere->next = NULL;
            finito = true;
        }
        pListaOpere iter = this->lista_opere;
        while (iter != NULL && !finito)
        {
            if (iter->codice_univoco == cod && iter->nome == n_opera && iter->autore == n_autore && iter->anno == anno_realizzazione && iter->stanza == nr_stanza && iter->prezzo == prezzo)
            {
                finito = true;
            }
            else if (iter->next == NULL)
            {
                iter->next = new ListaOpere;
                iter->next->codice_univoco = cod;
                strcpy(iter->next->nome, n_opera);
                strcpy(iter->next->autore, n_autore);
                iter->next->anno = anno_realizzazione;
                iter->next->stanza = nr_stanza;
                iter->next->prezzo = prezzo;
                iter->next->next = NULL;
                finito = true;
            }
            iter = iter->next;
        }
    }
};

int main()
{
    Museo museoBello = Museo("Museo Bello");
    museoBello.aggiungi_opera(123455, "Coso1", "Cioni", 2020, 1);
    museoBello.aggiungi_opera(123456, "Coso2", "Cioni", 2020, 1);
    museoBello.aggiungi_opera(123457, "Coso3", "Cioni", 2020, 2);
    museoBello.aggiungi_opera(123458, "Coso4", "Cioni", 2020, 1);
    museoBello.aggiungi_opera(123459, "Coso5", "Cioni", 2020, 3);
    museoBello.stampa_stanze();

    MuseoAPagamento museoBrutto = MuseoAPagamento("Museo Brutto");
    museoBrutto.aggiungi_opera(123455, "Coso1", "Cioni", 2020, 1, 10.20);
    museoBrutto.aggiungi_opera(123456, "Coso2", "Cioni", 2020, 1, 10.40);
    museoBrutto.aggiungi_opera(123457, "Coso3", "Cioni", 2020, 2, 10.60);
    museoBrutto.aggiungi_opera(123458, "Coso4", "Cioni", 2020, 1, 10.08);
    museoBrutto.aggiungi_opera(123459, "Coso5", "Cioni", 2020, 3, 10.01);
    museoBrutto.stampa_stanze();

    return 0;
}