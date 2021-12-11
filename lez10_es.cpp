#include <iostream>
#include <ctime>
//#include "custom_library.h"
//#include "custom_library.cpp"

#define L 10

using namespace std;

struct lista
{
    int val;
    lista *next = NULL;
};

typedef lista *p_lista;

void scambia_1(int x, int y) // NON FUNZIONA
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void scambia_2(int *p, int *q) //Usa scambia_2(int &x, int &y)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void scambia_3(int& x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void scambia_4(int *p, int *q) // NON FUNZIONA
{
    int *tmp;
    tmp = p;
    p = q;
    q = tmp;
}

void sort_ptr(int arr[])
{
    for (int i = 0; i < L; i++)
    {
        for (int j = i; j < L; j++)
        {
            if (arr[i] > arr[j])
            {
                scambia_2(&arr[i], &arr[j]);
            }
        }
    }
}

p_lista search_el(p_lista p, const int e) // Risolto
{
    while ((p->val != e)&&(p->next != NULL))
        p = p->next;
    if (p->val == e) return(p);
    else return(NULL);
}

p_lista create_list_input_inverse(int n) // prende la lista al contrario
{
	p_lista p = NULL;
	p_lista tmp;
	for (int i = 0; i < n ; i = i+1)
    {
		tmp = new lista;
        cin >> tmp->val;
		//tmp->val = rand() % (3*n+1);
		tmp->next = p;
		p = tmp;
	}
	return p;
}

p_lista create_list_input(int n) // prende la lista, funziona
{
	p_lista p;
    p = new lista;
    p_lista backup = p;
    cin >> p->val;
    for (int i = 0; i < n-1; i++)
    {
        p->next = new lista;
        p = p->next;
        cin >> p->val;
    }
	return backup;
}

p_lista create_list_random(int n) // Fatta dal prof, prende la lista al contrario random
{
	srand(time(0));
	p_lista p = NULL;
	p_lista tmp;
	for (int i = 0; i < n ; i = i+1)
    {
		tmp = new lista ;
		tmp->val = rand() % (3*n+1);
		tmp->next = p;
		p = tmp;
	}
	return p;
}

void print_list(p_lista p) // stampa i valori della lista, testata
{
	while (p != NULL)
    {
		cout << '[' << p->val << "], ";
		p = p->next;
	}
	cout << endl;
}

void print_list_tab(p_lista p) // stampa i valori della lista, testata
{
	while (p != NULL)
    {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
}

void print_list_complete(p_lista p) // stampa lista con associato l'indirizzo, testata
{
	while (p != NULL)
    {
		cout << "[" << p << ", " << p->val << "]  ";
		p = p->next;
	}
	cout << endl;
}

p_lista remove_items(p_lista list, int i) // funziona, del prof
{
	p_lista head = list;
    p_lista prev = list;
    p_lista tmp;
	while (list != NULL)
    {
		if (list->val % i == 0)
        {
			if (list == head)
            {
				// skip by one updaing the head
				tmp = head ;
				head = list->next;
				delete tmp ;
				prev = head;
				list = head ;
			}
            else
            {
				// skip by one
				tmp = prev->next ;
				prev->next = list->next;
				delete tmp ;
				list = prev->next ;
			}
		}
        else
        {
			prev = list;
			list = list->next;
		}
    }
    return head;
}

p_lista remove_multiple(p_lista head, int n) // rimuove i multipli di n, funziona
{
    p_lista p;
    p = new lista;
    p = head;
    while (p->val % n == 0 && p->next != NULL)
    {
        head = p->next;
        p = p->next;
    }
    if (p->val % n == 0)
    {
        head = NULL;
    }
    if (p != NULL)
    {
        while (p->next != NULL)
        {
            if ((p->next)->val % n == 0)
            {
                p->next = (p->next)->next;
            }
            else
            {
                p = p->next;
            }
        }
    }
    return head;
}

p_lista genera_elenco_naturali(int n)
{
    p_lista head = new lista;
    p_lista backup = head;
    for (int i = 0; i < n; i++)
    {
        head->val = i+1;
        p_lista tmp = new lista;
        head->next = tmp;
        if (i == n-1) { head->next = NULL; }
        else { head = head->next; }
    }
    return backup;
}

p_lista genera_crivello_eratostene(int n)
{
    p_lista head = (genera_elenco_naturali(n))->next;
    p_lista iter = head;
    p_lista iter_bis = head;
    int i;
    while (iter->next != NULL)
    {
        i = iter->val;
        iter = remove_multiple(iter, i);
        iter = iter->next;
    }
    return head;
}

p_lista inverti_lista(p_lista p)
{
	p_lista successivo, precedente = NULL ;
	while (p != NULL)
    {
	    successivo = p -> next;
	    p -> next = precedente;
	    precedente = p;
	    p = successivo;
	}
	return precedente;
}

p_lista aggiungi_elemento_coda(p_lista p, int n)
{
    p_lista backup = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new lista;
    p->next->val = n;
    p->next->next = NULL;
    return backup;
}

int analizza_nodo(p_lista p)
{
    return p->val;
}

p_lista torna_indietro(p_lista backup_head, p_lista p)
{
    while (backup_head->next != p)
    {
        backup_head = backup_head->next;
    }
    return backup_head;
}

p_lista elimina_nodo_corrente(p_lista backup_head, p_lista p)
{
    p = torna_indietro(backup_head, p);
    p->next = p->next->next;
    return backup_head;
}


int main()
{
    p_lista head = create_list_random(20);
    p_lista backup_h = head;
    print_list(head);
    int n = -1;
    head = head->next->next;
    cout << analizza_nodo(head) << endl;
    head = torna_indietro(backup_h, head);
    cout << analizza_nodo(head) << endl;
    head = head->next->next->next;
    cout << analizza_nodo(head) << endl;
    head = elimina_nodo_corrente(backup_h, head);
    print_list(head);
}





/*
int main()
{
    p_lista head = create_list_random(20);
    int m, n = -1;
    while (n != 0)
    {
        print_list(head);
        cout << "Scegli cosa fare:" << endl;
        cout << "0 - spegni" << endl;
        cout << "1 - aggiungi un elemento in fondo alla lista" << endl;
        cout << "2 - vedi informazioni elemento corrente" << endl;
        cout << "3 - vai avanti" << endl;
        cout << "4 - vai indietro" << endl;
        cout << "5 - elimina elemento corrente" << endl;
        if (n == 1)
        {
            cout << "Inserisci il numero da aggiungere: ";
            cin >> m;
            aggiungi_elemento_coda(head, m);
        }
    }



    return 0;
}
*/