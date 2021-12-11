# Lezione 6
## DICHIARAZIONI, FUNZIONI E PASSAGGIO DEI PARAMETRI

## Esercizi:
1. scrivere una funzione che legge un numero binario da tastiera e 
lo stampa in decimale 
2. scrivere una funzione che legge due numeri binari da tastiera e 
ne stampa la somma e il prodotto (sempre in binario) 
3. scrivere una funzione che dati due numeri interi x e y calcoli 
x^2 + y^2 e x^2 * y 
4. scrivere una funzione che prende in input un intero (che non è 
multiplo di 10) e stampa l’intero con le cifre invertite
---
1. fatto, anche l'inverso
2. fatto, in modo stupido convertendoli
3. banale
4. fatto

## Esercizi:
1. senza usare alcuna libreria (oltre a iostream), crearsi la propria libreria che contiene le funzioni “sqrt” che prende un intero n e ritorna la parte intera della radice quadrata di n, e la funzione “log” che prende un intero n e ritorna la parte intera del  logaritmo di n in base 10
2. scrivere una funzione “ln” che prende in input un double $1+x$, $-1<=x<=1$, e ritorna il logaritmo naturale definito dalla formula (serie di Mercator)
3. scrivere una funzione che risolve le equazioni di 2^ grado $ax^2 + bx + c = 0$

---
1. fatto
2. fatto
3. banale
---
---
---
# Lezione 7
## ARRAY

## Esercizi:

- [x] scrivere una funzione che dato un numero binario memorizzato in un array lo converte in decimale
- [x] palindrome: un array di caratteri è palindromo se leggendolo da destra verso sinistra o da sinistra verso destra si ottiene lo stesso array. Scrivere una funzione che verifica se un array è palindromo o meno 
- [x] scrivere una funzione che prende in input un array di interi a e un intero n e ritorna true o false a seconda che n si trova in a oppure no
- [x] scrivere una funzione che prende in input un array di interi e ne stampa gli elementi senza stampare i duplicati
---
- [x] Definire una funzione che dato un array restituisce la posizione della seconda occorrenza del primo carattere che occorre almeno due volte, restituisce  -1 se nessun carattere occorre almeno due volte. (esame del 29/5/2013) 
- [x] Scrivere un programma che implementa una pila utilizzando un array (definire le funzioni is_empty, push e pop; la funzione push ritorna overflow se l’array è pieno) 
- [x] Scrivere un programma che implementa due pile utilizzando un solo array. In particolare, dato un array di lunghezza L (L è una costante del programma) definire le funzioni push1, pop1, is_empty1 e le funzioni push2, pop2, is_empty2 che implementano sull’array le note funzioni sulle pile. Le funzioni push1 e push2 restituiscono un errore (overflow) solamente se l’array è pieno. (esame del 15/6/2012) 
- [x] Definire una funzione void parola(char str[],int n,char dest[]) che prende come parametri un array str e un intero n e restituisce nel parametro dest la parola corrispondente all’ennesima parola dentro str. Si assuma che una parola sia una qualunque sequenza di caratteri diversi da spazio e che le parole siano separate tra loro da uno o più spazi. In caso di errore la funzione restituisce la parola vuota. (esame del 17/2/2012) - (FATTO PASSANDO LA LUNGHEZZA DI str COME PARAMETRO)

---
---
---

# Lezione 8
## STRINGHE

## Esercizi:

- [x] Scrivere una funzione che prende tre stringhe e stampa la più lunga
- [x] Scrivere una funzione che prende due nomi e stampa il primo dei due secondo l’ordine alfabetico
- [x] Definire una funzione `void parola(char str[], char c, char dest[])` che prende come parametri una stringa `str` e un carattere `c` e restituisce nel parametro `dest` la stringa corrispondente alla prima parola dentro `str` che inizia per `c` se presente. Si assuma che una parola sia una qualunque sequenza di caratteri diversi da spazio e che le parole siano separate tra loro da uno o più spazi.
- [x] Scrivere una funzione che prende in input una stringa `s` e la sua lunghezza e ritorna `true` se contiene le sottostringe `"gh"` o `"ch"` oppure `false` in caso contrario. *[esame 02/2018]*

---
---
---

# Lezione 9
## STRUTTURE

## Esercizi:

- [x] scrivere un programma che definisce una struct studente, chiede all'utente di inserire i dati di uno studente e stampa poi il nome dello studente e la media dei suoi voti 
- [x] scrivere un programma che definisce una struttura giorno dell'anno, chiede all'utente di inserire un giorno e calcola quanti giorni sono passati dall'inizio dell'anno 
- [x] scrivere un programma che gestisce gli studenti di informatica, con le seguenti funzioni: 
    a. inserimento di uno studente 
    b. inserimento di un esame 
    c. calcolo della media dei voti di uno studente 
    d. calcolo dell'eta media degli studenti 
- [x] scrivere un programma che funziona da agenda telefonica, con le seguenti funzioni: 
    a. inserimento di una persona nell'agenda 
    b. ricerca di una persona per nome 
    c. cancellazione di una persona

---
---
---

# Lezione 10
## PUNTATORI

## Esercizi semplici:

- [x] definire una variabile di tipo intero, incrementarla due volte attraverso due puntatori distinti e stampare il risultato 
- [x] allocare una variabile di tipo intero, incrementarla attraverso puntatore, stampare il risultato e deallocarla 
- [x] prendere in input 10 interi e memorizzarli in un array di 10 interi utilizzando i puntatori (le lhs degli assegnamenti sono sempre operazioni *p). Poi stampare i valori 
- [x] definire una struttura di 5 campi interi e memorizzarci 5 interi presi in input utilizzando i puntatori (le lhs degli assegnamenti sono sempre operazioni *p). Poi stampare i valori 
- [x] definire una variante della funzione “scambia” che scambia i valori di due variabili utilizzando i puntatori e usarla all’interno del main 
- [x] (per casa) ridefinire un algoritmo di ordinamento di array accedendo agli elementi attraverso puntatori

# Esercizi sulle liste

- [x] scrivere una funzione che prende una lista di interi e stampa la sequenza di interi memorizzata nella lista 
- [x] scrivere una funzione che crea una lista di lunghezza length (presa in input) i cui elementi sono numeri generati casualmente e ritorna il puntatore alla testa. 
- [x] scrivere un programma che prende una lista di interi e stampa il valore più vicino alla media 
- [x] scrivere una funzione che inverte i nodi di una lista e ritorna il puntatore alla testa della nuova lista.

---

- [x] scrivere una funzione che prende in input una lista e un intero n e rimuove dalla lista tutti gli interi multipli di n, quindi ritorna la lista [DIFFICILE] 
- [x] implementare il crivello di Eratostene 
- [x] scrivere un programma che consente all'utente di lavorare su una lista di interi con le seguenti operazioni:  
  - aggiungere un elemento in fondo 
  - vedere le informazioni dell'elemento corrente 
  - andare avanti di uno 
  - andare indietro di uno 
  - eliminare l'elemento corrente

---

**DA FARE** (Non fatti perchè pensati per le classi)
- [ ] implementare il tipo di dato pila con le operazioni di (a) creazione della pila vuota, (b) push = inserimento di un elemento nella pila, (c) pop = eliminazione di un elemento dalla pila; (d) top = valore dell’ elemento in testa alla pila
- [ ] implementare il tipo di dato coda con le operazioni di (a) creazione della coda vuota, (b) enqueue = inserimento di un elemento nella coda, (c) dequeue = eliminazione di un elemento dalla testa della coda; (d) top_el = valore dell’ elemento in testa alla coda
- [ ] implementare il tipo di dato insieme con le operazioni di (a) creazione dell’insieme vuoto, (b) is_in = appartenenza di un elemento all’insieme (c) union = unione di due insiemi; (d) intersection = intersezione di due insiemi

---

**DA FARE** (Analoghi a quelli già fatti ma più semplici)
- [ ] prendere in input caratteri e creare una lista bidirezionale che li contenga. Stampare i caratteri inseriti in ordine inverso e in ordine normale
- [ ] scrivere un programma che consente all'utente di lavorare su una lista bidirezionale di interi con le seguenti operazioni:
  - aggiungere un elemento in fondo
  - vedere le informazioni dell'elemento corrente
  - andare avanti di uno
  - andare indietro di uno
  - eliminare l'elemento corrente

---
---
---

# Lezione 11