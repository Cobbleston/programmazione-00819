#include <iostream>

#define L 100

using namespace std;

// Versione sbagliata

void strcat(char dest[], char src[])
{
    int i,j;
    i=0;
    while(dest[i]!='\0')
        i++;
    while(src[j]!='\0')
    {
        dest[i]=src[j];
        j++;
    }
}

// Il primo errore sta nel non inizializzare anche j a 0
// Il secondo errore sta nel non incrementare i nel secondo while

void strcat_sistemata(char dest[], char src[])
{
    int i,j;
    i = 0;
    j = 0;
    while(dest[i] != '\0')
        i++;
    while(src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
}

int main()
{
    char prima_parola[L] = "voglio scrivere ";
    char seconda_parola[L] = "qualcosa";
    strcat_sistemata(prima_parola, seconda_parola);
    cout << prima_parola << ", " << seconda_parola << endl;
}