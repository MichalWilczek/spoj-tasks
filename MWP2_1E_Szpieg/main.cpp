#include <iostream>
#include <string>
#include <vector> // std:: vector
#include <algorithm> // std:: sort
using namespace std;

vector<string> createVectorWithWords(){
    vector<string> words;
    string word;
    while (getline(cin, word)){
        words.push_back(word);
    }
    return words;
}

void printWords(vector<string> &words){
    int wordsLength = words.size();
    for (int i=0; i<wordsLength; i++){
        cout << words[i] << endl;
    }
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

int main()
{
    vector<string> words = createVectorWithWords();
    sortAlphabetically(words);
    printWords(words);
    return 0;
}
