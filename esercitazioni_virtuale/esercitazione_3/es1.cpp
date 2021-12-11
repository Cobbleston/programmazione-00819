#include <iostream>
#include <string.h>

#define L 100

using namespace std;

int search_a(char s[], int start = 0)
{
    int i = start;
    int tot_a = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'a')
        {
            tot_a++;
        }
        i++;
    };
    return tot_a;
}

int search_a_ric(char s[], int start = 0)
{
    if (s[start] == 'a')
    {
        return 1 + search_a_ric(s, start + 1);
    }
    else if (s[start] != '\0')
    {
        return search_a_ric(s, start + 1);
    }
    else if (s[start] == '\0')
    {
        return 0;
    }
}

int main()
{
    char s[L] = "prova per quattro aa";
    cout << search_a(s) << endl;
    cout << search_a(s, 10) << endl;
    cout << search_a_ric(s) << endl;
    cout << search_a_ric(s, 10) << endl;
    return 0;
}