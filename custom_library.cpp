#include <iostream>
#include "custom_library.h"
#include <cmath>
#include <ctime>

using namespace std;

//struct lista
//{
//    int val;
//    lista *next;
//};
//
//typedef lista *p_lista;

int sqrt_bis(int n)
{
    int res = 1;
    for (int i = 0; i < 10; i++)
    {
        res = (res + n / res) / 2;
    }
    return res;
}

double ln_bis(double x)
{
    x -= 1;
    double res = 0;
    for (int i = 1; i <= 50; i++)
    {
        double xp = 1;
        for (int j = 0; j < i; j++)
        {
            xp *= x;
        }
        if (i % 2 == 1)
        {
            res += xp / i;
        }
        else
        {
            res -= xp / i;
        }
    }
    return res;
}

int bin_to_dec(int b)
{
    int res = 0;
    int cont = 0;
    do
    {
        if (b % 2 == 1)
        {
            res += pow(2, cont);
        }
        b /= 10;
        cont++;
    } while (b != 0);
    return res;
}

int dec_to_bin(int d)
{
    int b = 0;
    int cont = 0;
    while (d > pow(2, cont))
    {
        cont++;
    }
    cont--;
    while (d > 0)
    {
        if (d >= pow(2, cont))
        {
            b += pow(10, cont);
            d -= pow(2, cont);
        }
        cont--;
    }
    return b;
}

int scambio_cifre(int n)
{
    int n1 = 0;
    while (n > 0)
    {
        n1 = n1 * 10 + n % 10;
        n /= 10;
    }
    return n1;
}

int bin_to_dec_array(int vec[], const int l, int p)
{
    int res = bin_to_dec(vec[p]);
    return res;
}

bool arr_palindromo(const int arr[], const int l)
{
    bool res = true;
    int i = 0;
    while (res && i < l / 2)
    {
        if (arr[i] != arr[l - i - 1])
        {
            res = false;
        }
        i++;
    }
    return res;
}

bool ricerca_arr(const int arr[], const int l, int n)
{
    bool res = false;
    int i = 0;
    while (!res && i < l)
    {
        if (arr[i] == n)
        {
            res = true;
        }
        i++;
    }
    return res;
}

void stampa_no_duplicati(const int arr[], const int l)
{
    int duplicati[l];
    bool zero_fatto = false;
    for (int i = 0; i < l; i++)
    {
        if (!ricerca_arr(duplicati, l, arr[i]) || (!zero_fatto && arr[i] == 0))
        {
            cout << arr[i] << ", ";
            if (arr[i] == 0)
            {
                zero_fatto = true;
            }
        }
        duplicati[i] = arr[i];
    }
}

int posizione_seconda_occorenza(const int arr[], const int l)
{
    int res = -1;
    int i = 0;
    int j;
    while (res == -1 && i < l)
    {
        j = i + 1;
        while (res == -1 && j < l)
        {
            if (arr[i] == arr[j])
            {
                res = j;
            }
            j++;
        }
        i++;
    }
    return res;
}

void parola(char str[], int n, char dest[])
{
    int i = 0;
    int index_parola = 0;
    int contatore_parole = 1;
    bool trovato = false;
    while (str[i] != '\0' && !trovato)
    {
        if (str[i+1] == ' ' && str[i] != ' ')
        {
            contatore_parole++;
        }
        //cout << "contatore parole: " << contatore_parole << ", " << str[i+1] << ", " << i << endl;
        if (contatore_parole == n && str[i+1] != ' ')
        {
            //cout << "sono dentro" << endl;
            index_parola = i;
            trovato = true;
        }
        i++;
    }
    //cout << index_parola << endl;
    int ind = index_parola+1;
    //cout << ind << endl;
    int k = 0;
    while (str[ind] != '\0' && str[ind] != ' ')
    {
        //cout << str[ind] << endl;
        dest[k] = str[ind];
        ind++;
        k++;
    }
}

int str_piu_lunga(char s1[], char s2[], char s3[])
{
    bool finita_1 = false;
    bool finita_2 = false;
    bool finita_3 = false;
    int i = 0;
    while (true)
    {
        if (s1[i] == '\0') finita_1 = true;
        if (s2[i] == '\0') finita_2 = true;
        if (s3[i] == '\0') finita_3 = true;
        if (finita_1 && finita_2)
        {
            cout << s3 << endl;
            return 0;
        }
        if (finita_2 && finita_3)
        {
            cout << s1 << endl;
            return 0;
        }
        if (finita_1 && finita_3)
        {
            cout << s2 << endl;
            return 0;
        }
        i++;
    }
}

void ordina_nomi(char n1[], char n2[])
{
    int i = 0;
    bool non_finito = true;
    while (n1[i] != '\0' && n2[i] != '\0' && non_finito)
    {
        if (n1[i] < n2[i])
        {
            cout << n1 << endl;
            non_finito = false;
        }
        else if (n1[i] > n2[i])
        {
            cout << n2 << endl;
            non_finito = false;
        }
        i++;
    }
}

void parola(char str[], char c, char dest[])
{
    cout << dest << endl;
    bool non_finito = true;
    int i = 0;
    while (str[i] != '\0' && non_finito)
    {
        if (str[i] == ' ' && str[i+1] == c)
        {
            int indice_inizio = i+1;
            int j = 0;
            while (str[indice_inizio+j] != ' ' && str[indice_inizio+j] != '\0')
            {
                dest[j] = str[indice_inizio+j];
                j++;
            }
            non_finito = false;
            dest[j] = '\0';
        }
        i++;
    }
}

bool consonante_forte(char s[], int l)
{
    bool non_finito = true;
    bool trovato = false;
    int i = 1;
    while (i < l && non_finito && l > 1)
    {
        if ((s[i-1] == 'c' && s[i] == 'h') || (s[i-1] == 'g' && s[i] == 'h'))
        {
            non_finito = false;
            trovato = true;
        }
        i++;
    }
    return trovato;
}

p_lista genera_lista_input(int l)
{
    p_lista head;
    head = new lista;
    p_lista backup;
    backup = head;
    for (int i = 0; i < l; i++)
    {
        cout << "Valore nr. " << i << ":\t";
        cin >> head->val;
        p_lista p1;
        p1 = new lista;
        head->next = p1;
        head = p1;
    }
    return backup;
}



// fine