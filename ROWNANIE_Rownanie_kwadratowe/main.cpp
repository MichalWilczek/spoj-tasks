/*
Napisz program, który wyznacza liczbê pierwiastków rzeczywistych równania kwadratowego.

Wejœcie
Na wejœcie programu podana zostanie pewna nieokreœlona, ale niewielka iloœæ zestawów danych.
Ka¿dy zestaw sk³adaæ siê bêdzie z 3 liczb rzeczywistych (wspó³czynników A, B i C
równania Ax^2 + Bx + C = 0) rozdzielonych spacjami. Poszczególne zestawy zostan¹ rozdzielone
znakiem nowej linii. Mo¿na przyj¹æ, ¿e A jest ró¿ne od zera.

Wyjœcie
Na wyjœciu ma siê pojawiæ ci¹g liczbowy, którego i-ta pozycja jest równa liczbie
pierwiastków rzeczywistych i-tego wczytanego z wejœcia równania. Poszczególne liczby nale¿y
rozdzieliæ znakami nowej linii.
*/

#include <iostream>
#include <math.h>
using namespace std;

int sprawdzLiczbePierwiastkow(double a, double b, double c)
{
    double delta = pow(b, 2) - 4*a*c;
    if (delta>0) return 2;
    else if (delta==0) return 1;
    else return 0;
}

int main()
{
    double a,b,c;
    while (cin >> a >> b >> c)
    {
        cout << sprawdzLiczbePierwiastkow(a,b,c) << endl;
    }
    return 0;
}
