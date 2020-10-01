#include <iostream>
using namespace std;

int** alokujMacierzDwuwymiarowa(int n, int m)
{
    int **tab;
    tab = new int*[n];
    for (int i=0; i<n; i++)
    {
        tab[i] = new int[m];
    }
    return tab;
}

void zwolnijMacierzDwuwymiarowa(int **tab, int n, int m)
{
    for (int i=0; i<n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    tab = NULL;
}

void wczytajDaneDoTablicy(int **tab, int n, int m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> tab[i][j];
        }
    }
    cout << endl;
}

int** transponujMacierz(int **tab, int n, int m)
{
    int **tabT = alokujMacierzDwuwymiarowa(m, n);
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            tabT[i][j] = tab[j][i];
        }
    }
    return tabT;
}

void pokazMacierz(int **tab, int n, int m)
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **tablica = alokujMacierzDwuwymiarowa(n, m);

    wczytajDaneDoTablicy(tablica, n, m);
    int **tablicaT = transponujMacierz(tablica, n, m);
    pokazMacierz(tablicaT, n, m);

    zwolnijMacierzDwuwymiarowa(tablica, n, m);
    zwolnijMacierzDwuwymiarowa(tablicaT, m, n);

    return 0;
}
