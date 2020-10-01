
/*
JPESEL - Pesel
Jan Kowalski musi wpisaæ do systemu szpitalnego dane osobowe pacjenta,
oprócz imienia i nazwiska musi równie¿ wpisaæ PESEL pacjenta. Jakie¿
by³o jego zdziwienie, gdy spostrzeg³, ¿e pewnych pacjentów system nie
przyjmowa³ z powodu wadliwego PESELu.

Twoim zadaniem jest sprawdzenie, czy podana liczba 11-cyfrowa jest
poprawnym PESELem.

Aby sprawdziæ czy dany PESEL jest prawid³owy nale¿y wykonaæ
nastêpuj¹ce dzia³ania:

Pierwsz¹ cyfrê mno¿ymy przez 1,
drug¹ cyfrê mno¿ymy przez 3,
trzeci¹ cyfrê mno¿ymy przez 7,
czwarta cyfrê mno¿ymy przez 9,
pi¹t¹ cyfrê mno¿ymy przez 1,
szóst¹ cyfrê mno¿ymy przez 3,
siódm¹ cyfrê mno¿ymy przez 7,
ósm¹ cyfrê mno¿ymy przez 9,
dziewi¹t¹ cyfrê mno¿ymy przez 1,
dziesi¹t¹ cyfrê mno¿ymy przez 3,
jedenast¹ cyfrê mno¿ymy przez 1.

Tak uzyskane 11 iloczynów dodajemy do siebie. Jeœli ostatnia cyfra tej
sumy jest zerem to podany PESEL jest prawid³owy. Przyk³ad dla numeru
PESEL 44051401458

4*1 + 4*3 + 0*7 + 5*9 + 1*1 + 4*3 + 0*7 + 1*9 + 4*1 + 5*3 + 8*1 =
4 + 12 + 0 + 45 + 1 + 12 + 0 + 9 + 4 + 15 + 8 = 110

ród³o: www.wikipedia.pl

Jeœli suma jest wiêksza od zera, wtedy sprawdzamy jej poprawnoœæ. W
przeciwnym przypadku nr PESEL jest b³êdny. Poniewa¿ ostatnia cyfra
liczby 110 jest zerem wiêc podany PESEL jest prawid³owy.

Na wejœciu podana jest w pojedyñczej linii iloœæ t<=100 numerów PESEL
do sprawdzenia. W kolejnych t liniach s¹ 11-cyfrowe liczby.

Output
W pojedyñczej linii powinna zostaæ wyœwietlona litera D, jeœli numer
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
