#include <iostream>
using namespace std;

int** alokujMacierzDwuwymiarowa(int n, int m);
void wczytajDaneDoTablicy(int **tab, int n, int m);
void pokazMacierz(int **tab, int n, int m);
void zwolnijMacierzDwuwymiarowa(int **tab, int n, int m);
void quickSort(int *tab, int left, int right);


bool sprawdzCzyTablicaJestRosnacaNiepowtarzajaca(int *tab, int iloscElementow)
{
    for (int i=0; i<iloscElementow-1; i++)
    {
        if (tab[i]==tab[i+1] || tab[i+1]-tab[i]>1) return false;
    }
    return true;
}

bool sprawdzWarunekSudokuDlaLinii(int **tab, int n, int m)
{
    // warunek dla linii horyzontalnych
    for (int i=0; i<m; i++)
    {
        int *tablicaLinia = new int [n];
        for (int j=0; j<n; j++)
        {
            tablicaLinia[j] = tab[i][j];
        }
        quickSort(tablicaLinia, 0, n-1);
        if (sprawdzCzyTablicaJestRosnacaNiepowtarzajaca(tablicaLinia, n)==false) return false;
        delete [] tablicaLinia;
        tablicaLinia = NULL;
    }

    // warunek dla linii pionowych
    for (int i=0; i<n; i++)
    {
        int *tablicaLinia = new int [m];
        for (int j=0; j<m; j++)
        {
            tablicaLinia[j] = tab[j][i];
        }
        quickSort(tablicaLinia, 0, m-1);
        if (sprawdzCzyTablicaJestRosnacaNiepowtarzajaca(tablicaLinia, m)==false) return false;
        delete [] tablicaLinia;
        tablicaLinia = NULL;
    }
    return true;
}

bool sprawdzLiczbyWMalymKwadracie(int **tab, int nIleElementow, int mIleElementow,  int nIndeks, int mIndeks, int iloscLiczbWBoku)
{
    int *tablicaMalyKwadrat = new int[iloscLiczbWBoku*iloscLiczbWBoku];
    int indeksTemp = 0;
    int indeksMaksMalyKwadrat = iloscLiczbWBoku*iloscLiczbWBoku-1;

    for (int i=nIndeks; i<nIndeks+iloscLiczbWBoku; i++)
    {
        for (int j=mIndeks; j<mIndeks+iloscLiczbWBoku; j++)
        {
            tablicaMalyKwadrat[indeksTemp] = tab[i][j];
            indeksTemp++;
        }
    }

    quickSort(tablicaMalyKwadrat, 0, indeksMaksMalyKwadrat);
    if (sprawdzCzyTablicaJestRosnacaNiepowtarzajaca(tablicaMalyKwadrat, indeksMaksMalyKwadrat)==false) return false;
    delete [] tablicaMalyKwadrat;
    tablicaMalyKwadrat = NULL;
    return true;
}

bool sprawdzWarunekSudokuDlaMalegoKwadratu(int **tab, int n, int m)
{
    // zmienne n oraz m musza byc wielokrotnoscia 3 !!!
    int iloscLiczbBok = 3;
    for (int i=0; i<n; i+=iloscLiczbBok)
    {
        for (int j=0; j<m; j+=iloscLiczbBok)
        {
            if (sprawdzLiczbyWMalymKwadracie(tab, n, m, i, j, iloscLiczbBok)==false) return false;
        }
    }
    return true;
}

int main()
{
    int n=9;
    int m=9;
    int ileTestow;
    cin >> ileTestow;

    for (int i=0; i<ileTestow; i++)
    {
        int **tablica = alokujMacierzDwuwymiarowa(n, m);
        wczytajDaneDoTablicy(tablica, n, m);
        if (sprawdzWarunekSudokuDlaLinii(tablica, n, m)==true && sprawdzWarunekSudokuDlaMalegoKwadratu(tablica, n, m)==true)
        {
            cout << "TAK" << endl;
        }
        else
        {
            cout << "NIE" << endl;
        }
        zwolnijMacierzDwuwymiarowa(tablica, n, m);
    }

    return 0;
}

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

void zwolnijMacierzDwuwymiarowa(int **tab, int n, int m)
{
    for (int i=0; i<n; i++)
    {
        delete [] tab[i];
        tab[i] == NULL;
    }
    delete [] tab;
    tab = NULL;
}

void quickSort(int *tab, int left, int right)
{
    int v=tab[(left+right)/2];
    int i,j,x;
    i=left;
    j=right;
    do
    {
        while (tab[i]<v)
            i++;
        while (tab[j]>v)
            j--;
        if (i<=j)
        {
            x=tab[i];
            tab[i]=tab[j];
            tab[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>left)
        quickSort(tab,left, j);
    if (i<right)
        quickSort(tab, i, right);
}
