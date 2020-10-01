#include <iostream>
#include <string>
using namespace std;

int convertToBinaryAndReverseNumber(int *table, unsigned long long int num)
{
    int tablePosition=0;
    while(num>0)
    {
        table[tablePosition] = (num%2);
        num/=2;
        tablePosition++;
    }
    return tablePosition;
}

void convertToDecimal(int *reverseBinaryNumber, int numberOfBinaryDigits)
{
    unsigned long long int numberReversed = 0;
    unsigned long long int twoToPower = 1;
    for (int i=numberOfBinaryDigits-1; i>=0; i--)
    {
        numberReversed += reverseBinaryNumber[i]*twoToPower;
        twoToPower *= 2;
    }
    cout << numberReversed << endl;
}

void conductMirrorFunction(unsigned long long int number)
{
    int tableLength=64;
    int *reverseBinaryNumber = new int [tableLength];
    int numberOfBinaryDigits = convertToBinaryAndReverseNumber(reverseBinaryNumber, number);
    convertToDecimal(reverseBinaryNumber, numberOfBinaryDigits);
    delete [] reverseBinaryNumber;
}

int main()
{
    unsigned long long int number;
    while(cin>>number)
    {
        conductMirrorFunction(number);
    }
    return 0;
}
