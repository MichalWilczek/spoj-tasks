/*
Napisz program, kt�ry wyznacza liczb� pierwiastk�w rzeczywistych r�wnania kwadratowego.

Wej�cie
Na wej�cie programu podana zostanie pewna nieokre�lona, ale niewielka ilo�� zestaw�w danych.
Ka�dy zestaw sk�ada� si� b�dzie z 3 liczb rzeczywistych (wsp�czynnik�w A, B i C
r�wnania Ax^2 + Bx + C = 0) rozdzielonych spacjami. Poszczeg�lne zestawy zostan� rozdzielone
znakiem nowej linii. Mo�na przyj��, �e A jest r�ne od zera.

Wyj�cie
Na wyj�ciu ma si� pojawi� ci�g liczbowy, kt�rego i-ta pozycja jest r�wna liczbie
pierwiastk�w rzeczywistych i-tego wczytanego z wej�cia r�wnania. Poszczeg�lne liczby nale�y
rozdzieli� znakami nowej linii.
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
