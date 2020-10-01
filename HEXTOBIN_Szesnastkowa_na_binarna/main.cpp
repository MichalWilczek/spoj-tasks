#include <iostream>
#include <map>
using namespace std;

void defineTranslatorFromHexadecimalToDecimal(map<char, string> &hexadecimalNumberDictionary){
    hexadecimalNumberDictionary['0']="0000";
    hexadecimalNumberDictionary['1']="0001";
    hexadecimalNumberDictionary['2']="0010";
    hexadecimalNumberDictionary['3']="0011";
    hexadecimalNumberDictionary['4']="0100";
    hexadecimalNumberDictionary['5']="0101";
    hexadecimalNumberDictionary['6']="0110";
    hexadecimalNumberDictionary['7']="0111";
    hexadecimalNumberDictionary['8']="1000";
    hexadecimalNumberDictionary['9']="1001";
    hexadecimalNumberDictionary['A']="1010";
    hexadecimalNumberDictionary['B']="1011";
    hexadecimalNumberDictionary['C']="1100";
    hexadecimalNumberDictionary['D']="1101";
    hexadecimalNumberDictionary['E']="1110";
    hexadecimalNumberDictionary['F']="1111";
}

void translateHexadecimalToDecimal(map<char, string> &hexadecimalNumberDictionary){
    char hexadecimalNumber;
    while (cin >> hexadecimalNumber) {
        string decimalNumber = hexadecimalNumberDictionary[hexadecimalNumber];
        cout << decimalNumber << endl;
    }
}

int main()
{
    map<char, string> hexadecimalNumberDictionary;
    defineTranslatorFromHexadecimalToDecimal(hexadecimalNumberDictionary);
    translateHexadecimalToDecimal(hexadecimalNumberDictionary);
}
