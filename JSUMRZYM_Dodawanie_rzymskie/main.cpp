#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

map<int, string> defineNumbersArabicTranslator();
map<string, int> defineNumbersRomanTranslator();
void printDigitUnities(char digit, map<int, string> &numberNames);
void printDigitTens(char digitTens, char digitUnities, map<int, string> &numberNames);
void printDigitHundreds(char digit, map<int, string> &numberNames);
void printDigitThousands(char digit, map<int, string> &numberNames);


string convertIntegerToString(int number)
{
    stringstream ss;
    ss << number;
    string numberStr;
    ss >> numberStr;
    return numberStr;
}

vector<string> extractSingleNumbersFromRomanNumber(string number)
{
    vector<char> keyRomanNumbers = {'M', 'D', 'C', 'L', 'X', 'V'};
    vector<string> subNumbers;
    string subNumber;
    int numberLetters = number.length();
    int subNumberStart = 0;
    int subNumberEnd = 0;
    for (int i=0; i<numberLetters; i++){

        for (int j=0; j<keyRomanNumbers.size(); j++){

            if (number[i] == keyRomanNumbers[j] && number[i] != number[i + 1]){
                subNumberEnd = i;
                int subNumberLength = subNumberEnd - subNumberStart +1;
                subNumber = number.substr(subNumberStart, subNumberLength);
                subNumberStart = subNumberEnd + 1;
                subNumbers.push_back(subNumber);
            }
        }
    }
    if (subNumberStart < numberLetters){
        subNumber = number.substr(subNumberStart, numberLetters-subNumberStart);
        subNumbers.push_back(subNumber);
    }
    return subNumbers;
}

int translateArabicNumberFromRoman(string romanNumber, map<string, int> translatorNumbersRoman)
{
    vector<string> subNumbers = extractSingleNumbersFromRomanNumber(romanNumber);
    int arabicNumber = 0;
    int subnumbersAmount = subNumbers.size();

    for (int i=0; i<subnumbersAmount-1; i++){
        int subNumberArabicFirst = translatorNumbersRoman[subNumbers[i]];
        int subNumberArabicSecond = translatorNumbersRoman[subNumbers[i+1]];
        if (subNumberArabicFirst < subNumberArabicSecond){
            arabicNumber -= subNumberArabicFirst;
        }
        else{
            arabicNumber += subNumberArabicFirst;
        }
    }
    int subNumberArabicLast = translatorNumbersRoman[subNumbers[subnumbersAmount - 1]];
    arabicNumber += subNumberArabicLast;
    return arabicNumber;
}

int addTwoIntegers(int number1, int number2){
    return number1 + number2;
}

vector<string> divideNumberToSubsets(string numberArabic)
{
    vector<string> setDigits;
    reverse(numberArabic.begin(), numberArabic.end());

    int numberLength = numberArabic.length();
    string numberSet;
    for (int i = 0; i < numberLength; i += 3){
        if (i+3 < numberLength){
            numberSet = numberArabic.substr(i, 3);
        }
        else{
            numberSet = numberArabic.substr(i, numberLength-i);
        }
        reverse(numberSet.begin(), numberSet.end());
        setDigits.insert(setDigits.begin(), numberSet); // add numberSet to the front in the vector
    }
    return setDigits;
}

void defineNumberFromThreeDigitsSet(string DigitsSet, map<int, string> &numberNames){
    char numberUnities;
    char numberTens;
    char numberHundreds;
    int DigitsSetLength = DigitsSet.length();

    switch (DigitsSetLength)
    {
    // case when 3 digits occur
    case 3:
        numberUnities = DigitsSet[2];
        numberTens = DigitsSet[1];
        numberHundreds = DigitsSet[0];
        printDigitHundreds(numberHundreds, numberNames);
        printDigitTens(numberTens, numberUnities, numberNames);
        printDigitUnities(numberUnities, numberNames);
        break;
    // case when 2 digits occur
    case 2:
        numberUnities = DigitsSet[1];
        numberTens = DigitsSet[0];
        printDigitTens(numberTens, numberUnities, numberNames);
        printDigitUnities(numberUnities, numberNames);
        break;
    // case when 1 digit occurs
    case 1:
        numberUnities = DigitsSet[0];
        printDigitUnities(numberUnities, numberNames);
        break;
    }
    cout << endl;
}

void printRomanNumber(vector<string> &vectorContent, map<int, string> &numberNames)
{
    int vectorContentLength = vectorContent.size();
    if (vectorContentLength == 1){
        defineNumberFromThreeDigitsSet(vectorContent[0], numberNames);
    }
    else if (vectorContentLength == 2){
        char valueThousand = vectorContent[0][0];
        switch (valueThousand)
        {
        case '1':
            cout << numberNames[1000];
            break;
        case '2':
            cout << numberNames[2000];
            break;
        case '3':
            cout << numberNames[3000];
            break;
        }
        defineNumberFromThreeDigitsSet(vectorContent[1], numberNames);
    }
}


int main()
{
    map<string, int> translatorNumbersRoman = defineNumbersRomanTranslator();
    map<int, string> translatorNumbersArabic = defineNumbersArabicTranslator();

    string romanNumber1;
    string romanNumber2;
    while(cin >> romanNumber1 && cin >> romanNumber2){
        int arabicNumber1 = translateArabicNumberFromRoman(romanNumber1, translatorNumbersRoman);
        int arabicNumber2 = translateArabicNumberFromRoman(romanNumber2, translatorNumbersRoman);
        string sumArabicNumbers = convertIntegerToString(arabicNumber1 + arabicNumber2);
        vector<string> setDigits = divideNumberToSubsets(sumArabicNumbers);
        printRomanNumber(setDigits, translatorNumbersArabic);
    }
    return 0;
}

map<int, string> defineNumbersArabicTranslator()
{
    map<int, string> translatorNumbersArabic;
    translatorNumbersArabic[1] = "I";
    translatorNumbersArabic[2] = "II";
    translatorNumbersArabic[3] = "III";
    translatorNumbersArabic[4] = "IV";
    translatorNumbersArabic[5] = "V";
    translatorNumbersArabic[6] = "VI";
    translatorNumbersArabic[7] = "VII";
    translatorNumbersArabic[8] = "VIII";
    translatorNumbersArabic[9] = "IX";
    translatorNumbersArabic[10] = "X";
    translatorNumbersArabic[20] = "XX";
    translatorNumbersArabic[30] = "XXX";
    translatorNumbersArabic[40] = "XL";
    translatorNumbersArabic[50] = "L";
    translatorNumbersArabic[60] = "LX";
    translatorNumbersArabic[70] = "LXX";
    translatorNumbersArabic[80] = "LXXX";
    translatorNumbersArabic[90] = "XC";
    translatorNumbersArabic[100] = "C";
    translatorNumbersArabic[200] = "CC";
    translatorNumbersArabic[300] = "CCC";
    translatorNumbersArabic[400] = "CD";
    translatorNumbersArabic[500] = "D";
    translatorNumbersArabic[600] = "DC";
    translatorNumbersArabic[700] = "DCC";
    translatorNumbersArabic[800] = "DCCC";
    translatorNumbersArabic[900] = "CM";
    translatorNumbersArabic[1000] = "M";
    translatorNumbersArabic[2000] = "MM";
    translatorNumbersArabic[3000] = "MMM";
    return translatorNumbersArabic;
}


map<string, int> defineNumbersRomanTranslator()
{
    map<string, int> translatorNumbersRoman;
    translatorNumbersRoman["I"] = 1;
    translatorNumbersRoman["II"] = 2;
    translatorNumbersRoman["III"] = 3;
    translatorNumbersRoman["IV"] = 4;
    translatorNumbersRoman["V"] = 5;
    translatorNumbersRoman["VI"] = 6;
    translatorNumbersRoman["VII"] = 7;
    translatorNumbersRoman["VIII"] = 8;
    translatorNumbersRoman["IX"] = 9;
    translatorNumbersRoman["X"] = 10;
    translatorNumbersRoman["XX"] = 20;
    translatorNumbersRoman["XXX"] = 30;
    translatorNumbersRoman["XL"] = 40;
    translatorNumbersRoman["L"] = 50;
    translatorNumbersRoman["LX"] = 60;
    translatorNumbersRoman["LXX"] = 70;
    translatorNumbersRoman["LXXX"] = 80;
    translatorNumbersRoman["XC"] = 90;
    translatorNumbersRoman["C"] = 100;
    translatorNumbersRoman["CC"] = 200;
    translatorNumbersRoman["CCC"] = 300;
    translatorNumbersRoman["CD"] = 400;
    translatorNumbersRoman["D"] = 500;
    translatorNumbersRoman["DC"] = 600;
    translatorNumbersRoman["DCC"] = 700;
    translatorNumbersRoman["DCCC"] = 800;
    translatorNumbersRoman["CM"] = 900;
    translatorNumbersRoman["M"] = 1000;
    translatorNumbersRoman["MM"] = 2000;
    translatorNumbersRoman["MMM"] = 3000;
    return translatorNumbersRoman;
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
}

void printDigitTens(char digitTens, char digitUnities, map<int, string> &numberNames)
{
    switch (digitTens)
    {
    case '0':
        break;
    case '1':
        cout << numberNames[10];
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
}

void printDigitThousands(char digit, map<int, string> &numberNames){
    switch(digit)
    {
    case '1':
        cout << numberNames[1000];
        break;
    case '2':
        cout << numberNames[2000];
        break;
    case '3':
        cout << numberNames[3000];
        break;
    }
}
