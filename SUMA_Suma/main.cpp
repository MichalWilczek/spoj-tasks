/*
Napisz program, kt�ry oblicza sum� pojawiaj�cych si� na wej�ciu liczb.

Wej�cie
Na wej�cie programu podana zostanie pewna nieokre�lona, ale niewielka
ilo�� ma�ych liczb ca�kowitych (z zakresu -100..100). Poszczeg�lne
liczby zostan� rozdzielone znakiem nowej linii.

Wyj�cie
Na wyj�ciu ma si� pojawi� ci�g liczbowy, kt�rego i-ta pozycja jest
r�wna sumie i pierwszych wczytanych z wej�cia liczb. Poszczeg�lne
liczby nale�y rozdzieli� znakami nowej linii.
*/

#include <iostream>
using namespace std;

int main()
{
    int suma=0;
    int liczba;
    while(cin >> liczba)
    {
        suma += liczba;
        cout << suma << endl;
    }
    return 0;
}
