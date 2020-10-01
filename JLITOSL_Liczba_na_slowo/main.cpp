#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void defineNumberNames(map<int, string> &numbers)
{
    numbers[1] = "jeden";
    numbers[2] = "dwa";
    numbers[3] = "trzy";
    numbers[4] = "cztery";
    numbers[5] = "piec";
    numbers[6] = "szesc";
    numbers[7] = "siedem";
    numbers[8] = "osiem";
    numbers[9] = "dziewiec";
    numbers[10] = "dziesiec";
    numbers[11] = "jedenascie";
    numbers[12] = "dwanascie";
    numbers[13] = "trzynascie";
    numbers[14] = "czternascie";
    numbers[15] = "pietnascie";
    numbers[16] = "szesnascie";
    numbers[17] = "siedemnascie";
    numbers[18] = "osiemnascie";
    numbers[19] = "dziewietnascie";
    numbers[20] = "dwadziescia";
    numbers[30] = "trzydziesci";
    numbers[40] = "czterdziesci";
    numbers[50] = "piecdziesiat";
    numbers[60] = "szescdziesiat";
    numbers[70] = "siedemdziesiat";
    numbers[80] = "osiemdziesiat";
    numbers[90] = "dziewiecdziesiat";
    numbers[100] = "sto";
    numbers[200] = "dwiescie";
    numbers[300] = "trzysta";
    numbers[400] = "czterysta";
    numbers[500] = "piecset";
    numbers[600] = "szescset";
    numbers[700] = "siedemset";
    numbers[800] = "osiemset";
    numbers[900] = "dziewiecset";
    numbers[1000] = "tys.";
    numbers[1000000] = "mln.";
    numbers[1000000000] = "mld.";
    numbers[1000000000000] = "bln.";
}

int uploadNumbers(vector<string> &numbers)
{
    int numbersAmount;
    string number;
    cin >> numbersAmount;
    for (int i=0; i<numbersAmount; i++)
    {
        cin >> number;
        numbers.push_back(number);
    }
    return numbersAmount;
}

void printDigitUnities(char digit, map<int, string> &numberNames)
{
    switch (digit)
    {
    case '1':
        cout << numberNames[1];
        break;
    case '2':
        cout << numberNames[2];
        break;
    case '3':
        cout << numberNames[3];
        break;
    case '4':
        cout << numberNames[4];
        break;
    case '5':
        cout << numberNames[5];
        break;
    case '6':
        cout << numberNames[6];
        break;
    case '7':
        cout << numberNames[7];
        break;
    case '8':
        cout << numberNames[8];
        break;
    case '9':
        cout << numberNames[9];
        break;
    }
    cout << " ";
}

void printDigitTens(char digitTens, char digitUnities, map<int, string> &numberNames)
{
    switch (digitTens)
    {
    case '0':
        break;
    case '1':
        switch(digitUnities)
        {
        case '0':
            cout << numberNames[10];
            break;
        case '1':
            cout << numberNames[11];
            break;
        case '2':
            cout << numberNames[12];
            break;
        case '3':
            cout << numberNames[13];
            break;
        case '4':
            cout << numberNames[14];
            break;
        case '5':
            cout << numberNames[15];
            break;
        case '6':
            cout << numberNames[16];
            break;
        case '7':
            cout << numberNames[17];
            break;
        case '8':
            cout << numberNames[18];
            break;
        case '9':
            cout << numberNames[19];
            break;
        }
        break;
    case '2':
        cout << numberNames[20];
        break;
    case '3':
        cout << numberNames[30];
        break;
    case '4':
        cout << numberNames[40];
        break;
    case '5':
        cout << numberNames[50];
        break;
    case '6':
        cout << numberNames[60];
        break;
    case '7':
        cout << numberNames[70];
        break;
    case '8':
        cout << numberNames[80];
        break;
    case '9':
        cout << numberNames[90];
        break;
    }
    cout << " ";
}

void printDigitHundreds(char digit, map<int, string> &numberNames){
    switch(digit)
    {
    case '1':
        cout << numberNames[100];
        break;
    case '2':
        cout << numberNames[200];
        break;
    case '3':
        cout << numberNames[300];
        break;
    case '4':
        cout << numberNames[400];
        break;
    case '5':
        cout << numberNames[500];
        break;
    case '6':
        cout << numberNames[600];
        break;
    case '7':
        cout << numberNames[700];
        break;
    case '8':
        cout << numberNames[800];
        break;
    case '9':
        cout << numberNames[900];
        break;
    }
    cout << " ";
}

bool defineNumberFromThreeDigitsSet(string DigitsSet, map<int, string> &numberNames){
    int numberUnities;
    int numberTens;
    int numberHundreds;
    int DigitsSetLength = DigitsSet.length();
    bool threeZeros = false;

    switch (DigitsSetLength)
    {
    // case when 3 digits occur
    case 3:
        numberUnities = DigitsSet[2];
        numberTens = DigitsSet[1];
        numberHundreds = DigitsSet[0];
        if (numberUnities == '0' && numberTens == '0' && numberHundreds == '0'){
            threeZeros = true;
        }
        printDigitHundreds(numberHundreds, numberNames);
        printDigitTens(numberTens, numberUnities, numberNames);
        if (numberTens != '1')
        {
            printDigitUnities(numberUnities, numberNames);
        }
        break;
    // case when 2 digits occur
    case 2:
        numberUnities = DigitsSet[1];
        numberTens = DigitsSet[0];
        printDigitTens(numberTens, numberUnities, numberNames);
        if (numberTens != '1')
        {
            printDigitUnities(numberUnities, numberNames);
        }
        break;
    // case when 1 digit occurs
    case 1:
        numberUnities = DigitsSet[0];
        printDigitUnities(numberUnities, numberNames);
        break;
    }
    return threeZeros;
}

void printNumber(vector<string> &setDigits, map<int, string> &numberNames){
    bool threeZeros;
    vector<string> thousandElements;
    thousandElements.push_back(numberNames[1000000000000]);
    thousandElements.push_back(numberNames[1000000000]);
    thousandElements.push_back(numberNames[1000000]);
    thousandElements.push_back(numberNames[1000]);
    int numberThreeDigitsSetsAmount = setDigits.size();

    int thousandElementsIterator;
    switch (numberThreeDigitsSetsAmount){
    case 2:
        thousandElementsIterator = 3;
        break;
    case 3:
        thousandElementsIterator = 2;
        break;
    case 4:
        thousandElementsIterator = 1;
        break;
    case 5:
        thousandElementsIterator = 0;
        break;
    }

    for (int i=0; i< numberThreeDigitsSetsAmount; i++){
        threeZeros = defineNumberFromThreeDigitsSet(setDigits[i], numberNames);
        if (i < numberThreeDigitsSetsAmount-1){
            // take the case when only zeros occur into account
            if ((threeZeros == false) || (threeZeros == true && i == 0))
            {
                cout << thousandElements[thousandElementsIterator] << " ";
            }
            thousandElementsIterator++;
        }
    }
}

vector<string> divideNumberToSubsets(vector<string> &numbers, int numberPosition)
{
    vector<string> setDigits;
    string number = numbers[numberPosition];
    reverse(number.begin(), number.end());

    int numberLength = number.length();
    string numberSet;
    for (int i = 0; i < numberLength; i += 3){
        if (i+3 < numberLength){
            numberSet = number.substr(i, 3);
        }
        else{
            numberSet = number.substr(i, numberLength-i);
        }
        reverse(numberSet.begin(), numberSet.end());
        setDigits.insert(setDigits.begin(), numberSet); // add numberSet to the front in the vector
    }
    return setDigits;
}

int main()
{
    map<int, string> numberNames;
    defineNumberNames(numberNames);
    vector<string> numbers;
    int numbersAmount = uploadNumbers(numbers);

    for (int i=0; i<numbersAmount; i++){
        vector<string> setDigits = divideNumberToSubsets(numbers, i);
        printNumber(setDigits, numberNames);
        cout << endl;
    }
    return 0;
}
