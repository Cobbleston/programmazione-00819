#include <iostream>

using namespace std;

void f(int n)
{
    if (n >= 0)
    {
        int cont = 0;
        while(cont < n)
        {
            if (cont % 2 == 0 && cont % 4 != 0)
            {
                cout << cont << ", ";
            }
            cont++;
        }
    }
}

int f_ric(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else
    {
        if (n % 2 == 0 && n % 4 != 0)
        {
            cout << n << ", ";
            return f_ric(n-1);
        }
        return f_ric(n-1);
    }
}

int main()
{
    int n = 20;
    f(n);
    cout << "\n";
    f_ric(n);
    cout << "\n";
    return 0;
}