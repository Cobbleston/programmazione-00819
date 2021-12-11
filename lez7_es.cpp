#include <iostream>
#include "custom_library.h"
#include "custom_library.cpp"

#define L 50

using namespace std;

int main()
{
    char frase[L] = "Mi ciamo  Simone Canova e sono molto simpatico";
    cout << consonante_forte(frase, L) << endl;
    return 0;
}