#include <iostream>
#include <vector>
#include <bits/stdc++.h> // std:: istringstream
using namespace std;

void printWords(vector<string> &words){
    int wordsLength = words.size();
    for (int i=0; i<wordsLength; i++){
        cout << words[i] << endl;
    }
}

void extractDataFromString(vector<string> &wordsTextOriginal, string phrase)
{
    istringstream ss(phrase);
    do {
        string word;
        ss >> word;
        wordsTextOriginal.push_back(word);
    } while (ss);
}

void uploadLyrics(vector<string> &textOriginalWords, vector<string> &textInputWords){
    string textOriginal;
    string textInput;
    getline(cin, textOriginal);
    cin.sync();
    getline(cin, textInput);

    extractDataFromString(textOriginalWords, textOriginal);
    extractDataFromString(textInputWords, textInput);
}

vector<string> findMissingWords(vector<string> &textOriginalWords, vector<string> &textInputWords){
    vector<string> textInputWordsMissing;
    int i = 0;
    int j = 0;
    while (i < textOriginalWords.size()){
        if (textOriginalWords[i] == textInputWords[j]){
            i++;
            j++;
        }
        else {
            textInputWordsMissing.push_back(textOriginalWords[i]);
            i++;
        }
    }
    return textInputWordsMissing;
}

bool myComparator(string a, string b);
vector<string> sortAlphabetically(vector<string> &words);
void printMissingWords(vector<string> &textInputWordsMissing){
    int textInputWordsMissingSize = textInputWordsMissing.size();
    cout << textInputWordsMissingSize << endl;
    if (textInputWordsMissingSize > 0){
        sortAlphabetically(textInputWordsMissing);
        printWords(textInputWordsMissing);
    }
}

int main()
{
    vector<string> textOriginalWords;
    vector<string> textInputWords;

    uploadLyrics(textOriginalWords, textInputWords);
    vector<string> textInputWordsMissing = findMissingWords(textOriginalWords, textInputWords);
    printMissingWords(textInputWordsMissing);
    return 0;
}

bool myComparator(string a, string b){
    bool comparator;
    comparator = a < b;
    return comparator;
}

vector<string> sortAlphabetically(vector<string> &words){
    int wordsLength = words.size();
    sort(words.begin(), words.end(), myComparator);
    return words;
}
