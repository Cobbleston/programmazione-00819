// // Stampare la tabella differenze rapporti con tre numeri con if
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     double x, y, z;
//     char c;
//     cin >> x >> y >> z;
//     cin >> c;
// 
//     if (c == '-') {
//         cout << "\t" << x << "\t" << y << "\t" << z << endl;
//         cout << x << "\t" << x - x << "\t" << y - x << "\t" << z - x << endl;
//         cout << y << "\t" << x - y << "\t" << y - y << "\t" << z - y << endl;
//         cout << z << "\t" << x - z << "\t" << y - z << "\t" << z - z << endl;
//     }
//     if (c == '/') {
//         cout << "\t" << x << "\t" << y << "\t" << z << endl;
//         cout << x << "\t" << x / x << "\t" << y / x << "\t" << z / x << endl;
//         cout << y << "\t" << x / y << "\t" << y / y << "\t" << z / y << endl;
//         cout << z << "\t" << x / z << "\t" << y / z << "\t" << z / z << endl;
//     }
// }

// // prendi 3 numeri, se uno dei tre è divisore di entrambi gli altri stampa 1, altrimenti 0
// 
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     int x, y, z;
//     cin >> x >> y >> z;
// 
//     if ((y % x == 0 && z % x == 0) || (x % y == 0 && z % y == 0) || (y % z == 0 && x % z == 0)) {
//         cout << 1;
//     }
//     else {
//         cout << 0;
//     }
// 
//     cout << ((y % x == 0 && z % x == 0) || (x % y == 0 && z % y == 0) || (y % z == 0 && x % z == 0));
// }

// // Approssimazione di e^x
// 
// #include <iostream>
// #include <cmath>
// 
// using namespace std;
// 
// double fact(int n) {
//     double res = 1;
//     for (double i = n; i > 0; i--) {
//         res *= i;
//     }
//     return res;
// }
// 
// int main() {
//     double res = 1;
//     double x;
//     double n;
//     cin >> x >> n;
//     for (int i = 1; i <= n; i++) {
//         res += pow(x, i)/fact(i);
//         cout << "test, " << res << ", " << pow(x, i)/fact(i) << endl;
//     }
//     cout << res << ", " << exp(x);
//     return 0;
// }

// // Stampare triangolo di tartaglia, cicli for
// // CHIEDI A CIONI
// 
// #include <iostream>
// 
// using namespace std;
// 
// int main() {
//     int h = 0;
//     cin >> h;
//     int temp = h-1;
//     int tart = 0;
// 
//     for (int i = 0; i < h; i++) {
//         int num = 1;
// 
//         //calcolo n!
//         for (int j = 1; j <= i; j++)
//  	 	 	 num *= j;
// 
//         //faccio gli spazi del triangolo
//         for (int j = 0; j < temp; j++)
//              cout << "\t";
// 
//         //scrivo i numeri
//         for (int j = 0; j <= i; j++) {
//             int k = 1;
//             int nk = 1;
//             //calcolo k!
//             for (int l = 1; l <= j; l++) {
//                 k *= l;
//             }
// 
//             for (int l = 1; l <= i-j; l++) {
//                 nk *= l;
//             }
//             tart = num/(k*nk);
// 
//             cout << tart << "\t\t";
// 
//         }
//         temp--;
//         cout << "" << endl;
//     }
// 
// 
//     return(0);
// }