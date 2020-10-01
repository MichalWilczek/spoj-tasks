
/*
JPESEL - Pesel
Jan Kowalski musi wpisa� do systemu szpitalnego dane osobowe pacjenta,
opr�cz imienia i nazwiska musi r�wnie� wpisa� PESEL pacjenta. Jakie�
by�o jego zdziwienie, gdy spostrzeg�, �e pewnych pacjent�w system nie
przyjmowa� z powodu wadliwego PESELu.

Twoim zadaniem jest sprawdzenie, czy podana liczba 11-cyfrowa jest
poprawnym PESELem.

Aby sprawdzi� czy dany PESEL jest prawid�owy nale�y wykona�
nast�puj�ce dzia�ania:

Pierwsz� cyfr� mno�ymy przez 1,
drug� cyfr� mno�ymy przez 3,
trzeci� cyfr� mno�ymy przez 7,
czwarta cyfr� mno�ymy przez 9,
pi�t� cyfr� mno�ymy przez 1,
sz�st� cyfr� mno�ymy przez 3,
si�dm� cyfr� mno�ymy przez 7,
�sm� cyfr� mno�ymy przez 9,
dziewi�t� cyfr� mno�ymy przez 1,
dziesi�t� cyfr� mno�ymy przez 3,
jedenast� cyfr� mno�ymy przez 1.

Tak uzyskane 11 iloczyn�w dodajemy do siebie. Je�li ostatnia cyfra tej
sumy jest zerem to podany PESEL jest prawid�owy. Przyk�ad dla numeru
PESEL 44051401458

4*1 + 4*3 + 0*7 + 5*9 + 1*1 + 4*3 + 0*7 + 1*9 + 4*1 + 5*3 + 8*1 =
4 + 12 + 0 + 45 + 1 + 12 + 0 + 9 + 4 + 15 + 8 = 110

�r�d�o: www.wikipedia.pl

Je�li suma jest wi�ksza od zera, wtedy sprawdzamy jej poprawno��. W
przeciwnym przypadku nr PESEL jest b��dny. Poniewa� ostatnia cyfra
liczby 110 jest zerem wi�c podany PESEL jest prawid�owy.

Na wej�ciu podana jest w pojedy�czej linii ilo�� t<=100 numer�w PESEL
do sprawdzenia. W kolejnych t liniach s� 11-cyfrowe liczby.

Output
W pojedy�czej linii powinna zosta� wy�wietlona litera D, je�li numer
PESEL jest poprawny lub N, gdy nie.
*/

#include <iostream>

using namespace std;

int oblicz_sume_z_peselu(long long numer_pesel)
{
    long long wartosc_calkowita=numer_pesel;
    int szyfr[11] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int pesel_cyfry[11];
    int reszta;
    int suma = 0;

    for (int i=10; i>=0; i--)
    {
        reszta = wartosc_calkowita%10;
        pesel_cyfry[i] = reszta;
        wartosc_calkowita = (wartosc_calkowita - reszta)/10;
        suma += szyfr[i]*pesel_cyfry[i];
    }

    return suma;
}

void sprawdz_poprawnosc_numeru_pesel(int suma_numer_pesel)
{
    if (suma_numer_pesel%10 == 0)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
}

int main()
{
    int ilosc_iteracji;
    cin >> ilosc_iteracji;

    long long numer_pesel;
    for (int i=0; i< ilosc_iteracji; i++)
    {
        cin >> numer_pesel;
        sprawdz_poprawnosc_numeru_pesel(oblicz_sume_z_peselu(numer_pesel));
    }

    return 0;
}
