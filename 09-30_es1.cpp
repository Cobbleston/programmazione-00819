// // Scambiare due char
//
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     char x, y;
//     cin >> x >> y;
//     char tmp;
//     tmp = x;
//     x = y;
//     y = tmp;
//     cout << x << y;
//     return (0);
// }

// // Scambiare due interi senza tmp
// 
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     int x, y;
//     cin >> x >> y;
//     x = x + y;
//     y = y - x;
//     x = x + y;
//     y = y * -1;
//     cout << x << y;
//     return (0);
// }

// // Invertire ordine tre reali
// 
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     float x, y, z;
//     cin >> x >> y >> z;
//     float tmp;
//     tmp = x;
//     x = z;
//     z = tmp;
//     cout << x << y << z;
//     return (0);
// }

// // scrivere un programma che prende in input un prezzo in euro (inclusi centesimi) e stampa quante e quali monete sono
// // necessarie per pagarlo (con un numero minimo di monete)
// 
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     double prezzo;
//     cout << "input: ";
//     cin >> prezzo;
// 
//     int euro = (int) prezzo;
//     int cent = (int) 100 * (prezzo - euro);
// 
//     int due_euro = (euro - (euro % 2)) / 2;
//     euro -= due_euro * 2;
// 
//     int un_euro = euro;
// 
//     int cinquanta_cent = (cent - (cent % 50)) / 50;
//     cent -= cinquanta_cent * 50;
// 
//     int venti_cent = (cent - (cent % 20)) / 20;
//     cent -= venti_cent * 20;
// 
//     int dieci_cent = (cent - (cent % 10)) / 10;
//     cent -= dieci_cent * 10;
// 
//     int cinque_cent = (cent - (cent % 5)) / 5;
//     cent -= cinque_cent * 5;
// 
//     int due_cent = (cent - (cent % 2)) / 2;
//     cent -= due_cent * 2;
// 
//     int un_cent = cent;
// 
//     cout << "Monete da 2 euro: " << due_euro << endl;
//     cout << "Monete da 1 euro: " << un_euro << endl;
//     cout << "Monete da 50 cent: " << cinquanta_cent << endl;
//     cout << "Monete da 20 cent: " << venti_cent << endl;
//     cout << "Monete da 10 cent: " << dieci_cent << endl;
//     cout << "Monete da 5 cent: " << cinque_cent << endl;
//     cout << "Monete da 2 cent: " << due_cent << endl;
//     cout << "Monete da 1 cent: " << un_cent << endl;
//     cout << "Prezzo iniziale: " << prezzo << endl;
//     return (0);
// }

// Prendere due lunghezze di cateti in input e calcolare l'ipotenusa

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    double x, y;
    // cin >> x >> y;
    srand(time(0));
    x = rand() % 100 + 1;
    y = rand() % 100 + 1;

    double ipo = sqrt(pow(x, 2) + pow(y, 2));
    cout << x << ", " << y << ", " << ipo;

    return (0);
}