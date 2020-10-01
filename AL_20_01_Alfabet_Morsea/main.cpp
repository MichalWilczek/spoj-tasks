#include <iostream>
#include <map>
using namespace std;

void defineMorseAlphabetMap(map<char, string> &letterMorseDictionary){
    letterMorseDictionary[' '] = "/";
    letterMorseDictionary['A'] = ".-";
    letterMorseDictionary['B'] = "-...";
    letterMorseDictionary['C'] = "-.-.";
    letterMorseDictionary['D'] = "-..";
    letterMorseDictionary['E'] = ".";
    letterMorseDictionary['F'] = ".-..";
    letterMorseDictionary['G'] = "--.";
    letterMorseDictionary['H'] = "....";
    letterMorseDictionary['I'] = "..";
    letterMorseDictionary['J'] = ".---";
    letterMorseDictionary['K'] = "-.-";
    letterMorseDictionary['L'] = "..-.";
    letterMorseDictionary['M'] = "--";
    letterMorseDictionary['N'] = "-.";
    letterMorseDictionary['O'] = "---";
    letterMorseDictionary['P'] = ".--.";
    letterMorseDictionary['Q'] = "--.-";
    letterMorseDictionary['R'] = ".-.";
    letterMorseDictionary['S'] = "...";
    letterMorseDictionary['T'] = "-";
    letterMorseDictionary['U'] = "..-";
    letterMorseDictionary['V'] = "...-";
    letterMorseDictionary['W'] = ".--";
    letterMorseDictionary['X'] = "-..-";
    letterMorseDictionary['Y'] = "-.--";
    letterMorseDictionary['Z'] = "--..";
}

char transformLowercaseToUppercase(char letter){
    if (letter >= 'a' && letter <='z'){
        letter -= 32;
    }
    return letter;
}

void translateTextToMorseAlphabet(map<char, string> &letterMorseDictionary){
    string phrase;
    while (getline(cin, phrase)){
        for (int i=0; i<phrase.length(); i++){
        char letter = transformLowercaseToUppercase(phrase[i]);
        cout << letterMorseDictionary[letter];
        if (letter != ' ') cout << "/";
        }
        cout << endl;
    }
}

int main()
{
    map<char, string> letterMorseDictionary;
    defineMorseAlphabetMap(letterMorseDictionary);
    translateTextToMorseAlphabet(letterMorseDictionary);
    return 0;
}
