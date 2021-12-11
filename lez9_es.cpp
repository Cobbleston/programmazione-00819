#include <iostream>
#include <cstring>

#define L 100

using namespace std;

/*

struct exam
{
    int voto;
    char nome[L];
};

struct student // s = {nome, cognome, eta, numeromatr, exam, numeroesami}
{
    char nome[L];
    char cognome[L];
    int eta;
    char numero_matricola[L];
    exam esami[L];
    int numero_esami = 0;
};

struct giorno_dell_anno
{
    int giorno;
    int mese;
    int anno;
};

student inserimento_studente()
{
    student s;
    cout << "Nome: ";
    cin >> s.nome;
    cout << "Cognome: ";
    cin >> s.cognome;
    cout << "Età: ";
    cin >> s.eta;
    cout << "Numero matricola: ";
    cin >> s.numero_matricola;
    return s;
}

exam inserimento_esame()
{
    exam e;
    cout << "Nome dell'esame: ";
    cin >> e.nome;
    cout << "Voto dell'esame: ";
    cin >> e.voto;
    return e;
}

void stampa_studenti(student l_s[], int num_s)
{
    for (int j = 0; j < num_s; j++)
    {
        cout << "Studente nr. " << j << ":\t" << l_s[j].nome << "\t" << l_s[j].cognome << "\t" << l_s[j].numero_matricola << "\t" << l_s[j].eta << endl;
    }
}

double calcola_media(student s)
{
    if (s.numero_esami == 0) { return 0; }
    int somma_voti = 0;
    for (int i = 0; i < s.numero_esami; i++)
    {
        somma_voti += s.esami[i].voto;
    }
    return 1.0 * somma_voti/s.numero_esami;
}

double calcolo_eta_media(student l_s[], int num_studenti)
{
    int somma_eta = 0;
    if (num_studenti == 0) { return 0; }
    for (int i = 0; i < num_studenti && i < L; i++)
    {
        somma_eta += l_s[i].eta;
    }
    return 1.0 * somma_eta/num_studenti;
}

int main()
{
    char scelta = 'y';
    struct student lista_studenti[L];
    int numero_studenti = 0;
    int numero_esami_per_studente[L];
    
    // Inserisco gli studenti
    cout << "Vuoi inserire uno studente? [y/n] ";
    cin >> scelta;
    int i = 0;
    while (scelta == 'y' && i < L)
    {
        lista_studenti[i] = inserimento_studente();
        numero_studenti++;
        cout << "Vuoi inserire uno studente? [y/n] ";
        cin >> scelta;
        i++;
    }

    // Stampo la lista degli studenti
    cout << "\nLista studenti:\n" << endl;
    stampa_studenti(lista_studenti, numero_studenti);

    // Inserimento degli esami
    int studente_scelto = 0;
    cout << "Vuoi inserire gli esami per uno studente? [y/n] ";
    cin >> scelta;
    while (scelta == 'y')
    {
        cout << "Per quale studente? Inserisci il numero: ";
        cin >> studente_scelto;
        i = lista_studenti[studente_scelto].numero_esami;
        char scelta_bis = 'y';
        while (i < L && scelta_bis == 'y')
        {
            lista_studenti[studente_scelto].esami[i] = inserimento_esame();
            lista_studenti[studente_scelto].numero_esami++;
            cout << "Vuoi continuare? [y/n] ";
            cin >> scelta_bis;
            i++;
        }
        cout << "Vuoi inserire gli esami per uno studente? [y/n] ";
        cin >> scelta;
    }

    // Calcolo la media dei voti di uno studente
    cout << "Vuoi calcolare la media di uno studente? [y/n] ";
    cin >> scelta;
    while (scelta == 'y')
    {
        cout << "Di quale studente? Inserisci il numero: ";
        cin >> studente_scelto;
        cout << "La media dello studente nr. " << studente_scelto << 
        " è: " << calcola_media(lista_studenti[studente_scelto]) << endl;
        cout << "Vuoi calcolare la media di uno studente? [y/n] ";
        cin >> scelta;
    }
    cout << "Vuoi calcolare l'età media degli studenti? [y/n] ";
    cin >> scelta;
    if (scelta == 'y')
    {
        cout << "L'età media degli studenti è: " << calcolo_eta_media(lista_studenti, numero_studenti) << endl;
    }
}

*/


/*

struct contatto
{
    char nome_cognome[L];
    char numero_telefono[L];
};

contatto inserimento_persona()
{
    contatto c;
    cout << "Nome: ";
    cin.ignore();
    cin.getline(c.nome_cognome, L);
    cout << "Numero: ";
    cin.ignore();
    cin.getline(c.numero_telefono, L);
    return c;
}

int ricerca_persona(contatto l_c[], int n)
{
    bool trovato = false;
    int indice = -1;
    char nome_ricerca[L];
    //cout << "Chi vuoi cercare? ";
    //strcpy(nome_ricerca, "Giulia Ghermandi");
    //cout << nome_ricerca << endl;
    cin.ignore();
    cin.getline(nome_ricerca, L);
    //cout << nome_ricerca << endl;
    int i = 0;
    while (i < n && !trovato)
    {
        //cout << l_c[i].nome_cognome << " vs " << nome_ricerca << endl;
        if (!strcmp(l_c[i].nome_cognome, nome_ricerca))
        {
            indice = i;
            trovato = true;
        }
        i++;
    }
    return indice;
}

void cancellazione_persona(contatto l_c[], char nome_canc[], int n)
{
    bool fatto = false;
    int i = 0;
    while (i < n)
    {
        if (!strcmp(l_c[i].nome_cognome, nome_canc) && !fatto)
        {
            cout << "Voglio inserire " << l_c[i+1].nome_cognome << " in " << l_c[i].nome_cognome << " e i è " << i << endl;
            strcpy(l_c[i].nome_cognome, l_c[i+1].nome_cognome);
            strcpy(l_c[i].numero_telefono, l_c[i+1].numero_telefono);
            fatto = true;
        }
        else if (fatto)
        {
            cout << "Voglio inserire " << l_c[i+1].nome_cognome << " in " << l_c[i].nome_cognome << " e i è " << i << endl;
            strcpy(l_c[i].nome_cognome, l_c[i+1].nome_cognome);
            strcpy(l_c[i].numero_telefono, l_c[i+1].numero_telefono);
        }
        i++;
    }
}

int main()
{
    int scelta_bis = 0;
    contatto agenda[L];
    agenda[0] = {"Simone Canova", "3311314585"};
    agenda[1] = {"Giulia Ghermandi", "3313440891"};
    agenda[2] = {"Elena Ghermandi", "3313440666"};
    int numero_contatti = 3;
    while (scelta_bis != -1)
    {
        cout << "Cosa vuoi fare?\n1 - INSERISCI CONTATTO\n2 - RICERCA PERSONA\n3 - CANCELLA PERSONA\n4 - STAMPA AGENDA\n-1 - STOP\n";
        cin >> scelta_bis;
        if (scelta_bis == 1)
        {
            agenda[numero_contatti] = inserimento_persona();
            numero_contatti++;
        }
        else if (scelta_bis == 2)
        {
            int index = ricerca_persona(agenda, numero_contatti);
            if (index == -1) { cout << "Non trovato" << endl; }
            else { cout << "Trovato, il numero è: " << agenda[index].numero_telefono << endl; }
        }
        else if (scelta_bis == 3)
        {
            char nome_da_cancellare[L];
            cout << "Chi vuoi cancellare? ";
            cin.ignore();
            cin.getline(nome_da_cancellare, L-1);
            cancellazione_persona(agenda, nome_da_cancellare, numero_contatti);
            numero_contatti--;
        }
        else if (scelta_bis == 4)
        {
            for (int i = 0; i < numero_contatti; i++)
            {
                cout << agenda[i].nome_cognome << ", " << agenda[i].numero_telefono << endl;
            }
        }
    }
    return 0;
}

*/