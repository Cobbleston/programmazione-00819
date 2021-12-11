#include <iostream>
//#include <cmath>
#include "custom_library.h"
#include "custom_library.cpp"

using namespace std;
/*
int bin_to_dec(int b) {
    int res = 0;
    int cont = 0;
    do {
        if (b % 2 == 1) {
            res += pow(2, cont);
        }
        b /= 10;
        cont++;
    } while (b != 0);
    return res;
}


int dec_to_bin(int d) {
    int b = 0;
    int cont = 0;
    while (d > pow(2, cont)) {
        cont++;
    }
    cont--;
    while (d > 0) {
        if (d >= pow(2, cont)) {
            b += pow(10, cont);
            d -= pow(2, cont);
        }
        cont--;
    }
    return b;
}

void oper_bin_stupide(int a, int b) {
    int da = bin_to_dec(a);
    int db = bin_to_dec(b);
    int sum = da + db;
    int mul = da * db;
    cout << dec_to_bin(sum) << ", " << dec_to_bin(mul) << endl;
}

int scambio_cifre(int n) {
    int n1 = 0;
    while (n > 0) {
        n1 = n1*10 + n % 10;
        n /= 10;
    }
    return n1;
}
*/

int main() {
    double num = 0;
    cin >> num;
    cout << ln_bis(num) << endl << sqrt_bis(num) << endl;
    return 0;
}