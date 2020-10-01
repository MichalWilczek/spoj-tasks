#include <iostream>

using namespace std;

int znajdzNajwiekszyWspolnyDzielnik(int liczbaA, int liczbaB)
{
    int pom;
	while(liczbaB!=0)
    {
		pom = liczbaB;
		liczbaB = liczbaA%liczbaB;
		liczbaA = pom;
	}
    return liczbaA;
}

int main()
{
    int iloscPowtorzen;
    cin>>iloscPowtorzen;
    for (int j=0; j<iloscPowtorzen; j++)
    {
        int liczba1, liczba2;
        cin >> liczba1 >> liczba2;
        cout << znajdzNajwiekszyWspolnyDzielnik(liczba1, liczba2) << endl;
    }
    return 0;
}
