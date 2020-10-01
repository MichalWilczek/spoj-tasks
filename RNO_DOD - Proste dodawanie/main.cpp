/*
Twoim zadaniem jest dodaæ wszystkie liczby ca³kowite podane na wejœciu.

Wejœcie
W pierwszym wierszu znajduje siê liczba t testów (0 < t < 100) Ka¿dy test
opisany jest w nastêpuj¹cy sposób. W pierwszym wierszu dana jest liczba
n - liczba liczb do zsumowania. Nastêpnie podanych jest n liczb
pooddzielanych spacj¹.
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
