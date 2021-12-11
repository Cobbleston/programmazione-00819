#include <iostream>
#include <math.h>

using namespace std;

class segmento
{
    protected:
        double x1 = 0;
        double y1 = 0;
        double x2 = 0;
        double y2 = 0;

    public:
        segmento(double xx1, double yy1, double xx2, double yy2)
        {
            if (xx1 >= 0) { x1 = xx1; }
            if (yy1 >= 0) { y1 = yy1; }
            if (xx2 >= 0) { x2 = xx2; }
            if (yy2 >= 0) { y2 = yy2; }
        }
        double lunghezza()
        {
            return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) );
        }
};

class segmenti_adiacenti: public segmento
{
    protected:
        double xv = 0;
        double yv = 0;
    public:
        segmenti_adiacenti(double xx1, double yy1, double xxv, double yyv, double xx2, double yy2):segmento(xx1, yy1, xx2, yy2)
        {
            if (xxv >= 0) { xv = xxv; }
            if (yyv >= 0) { yv = yyv; }
        }
        double lunghezza_primo()
        {
            return sqrt( pow(x1-xv, 2) + pow(y1-yv, 2) );
        }
        double lunghezza_secondo()
        {
            return sqrt( pow(xv-x2, 2) + pow(yv-y2, 2) );
        }
        double lunghezza()
        {
            return lunghezza_primo()+lunghezza_secondo();
        }
};

int main()
{
    segmento s1 = segmento(2, 3, 4, 5);
    segmento s2 = segmento(1, 6, 8, 3.4);
    segmenti_adiacenti sa1 = segmenti_adiacenti(1, 2, 3, 4, 5, 6);
    segmenti_adiacenti sa2 = segmenti_adiacenti(6, 5, 7, 3, 2, 1);

    cout << s1.lunghezza() << endl;
    cout << s2.lunghezza() << endl;
    cout << sa1.lunghezza() << ", " << sa1.lunghezza_primo() << ", " << sa1.lunghezza_secondo() << endl;
    cout << sa2.lunghezza() << ", " << sa2.lunghezza_primo() << ", " << sa2.lunghezza_secondo() << endl;

    return 0;
}