struct lista
{
    int val;
    lista *next;
};

typedef lista *p_lista;

// altre funzioni

// approssima la radice quadrata
int sqrt_bis(int n);

// approssima il logaritmo, x tra -1 e 1
double ln_bis(double x);

// converte binario in decimale
int bin_to_dec(int b);

// converte decimale in binario
int dec_to_bin(int d);

// scambia le cifre di un numero
int scambio_cifre(int n);

// converte un valore di un array da binario a decimale
int bin_to_dec_array(int vec[], const int l, int p);

// verifica se un array è palindromo
bool arr_palindromo(const int arr[], const int l);

// controlla se un intero è in un array
bool ricerca_arr(const int arr[], const int l, int n);

// stampa senza considerare i duplicati un array
void stampa_no_duplicati(const int arr[], const int l);

// stampa la posizione della seconda occorrenza di un intero in un array (se esiste, altrimenti -1)
int posizione_seconda_occorenza(const int arr[], const int l);

// stampa la n-esima parola di una frase, presa come vettore di caratteri
void parola(char str[], int n, char dest[]);

// prende 3 stringhe e stampa la più lunga
int str_piu_lunga(char s1[], char s2[], char s3[]);

// prende due nomi in input e stampa il primo secondo l'alfabeto
void ordina_nomi(char n1[], char n2[]);

// prende una stringa e un carattere e restituisce in una seconda stringa la prima parola che inizia con c (se esiste)
void parola(char str[], char c, char dest[]);

// data una stringa e la sua lunghezza verifica contenga "gh" o "ch"
bool consonante_forte(char s[], int l);

// genera una lista prendendo in input i valori
p_lista genera_lista_input(int l);

// .