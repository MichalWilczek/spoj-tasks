/*
Twoim zadaniem jest doda� wszystkie liczby ca�kowite podane na wej�ciu.

Wej�cie
W pierwszym wierszu znajduje si� liczba t test�w (0 < t < 100) Ka�dy test
opisany jest w nast�puj�cy spos�b. W pierwszym wierszu dana jest liczba
n - liczba liczb do zsumowania. Nast�pnie podanych jest n liczb
pooddzielanych spacj�.
*/

#include <iostream>
using namespace std;

int main()
{
	int liczbaTestow;
	cin >> liczbaTestow;

	for (int i=0; i<liczbaTestow; i++)
	{
		int liczbaZnakowDoZsumowania;
		cin >> liczbaZnakowDoZsumowania;
		int suma=0;
		int tablica[liczbaZnakowDoZsumowania];
		for (int j=0; j<liczbaZnakowDoZsumowania; j++)
		{
			cin >> tablica[j];
			suma += tablica[j];
		}

		cout << suma << endl;
	}
	return 0;
}
