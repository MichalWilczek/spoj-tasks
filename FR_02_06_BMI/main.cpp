#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double convertToMetresFromCentimetres(double centimetres)
{
    double metres = centimetres / 100;
    return metres;
}

double calculateBMI(double mass, double height){
    // mass in [kg] and height in [m]
    height = convertToMetresFromCentimetres(height);
    double BMI = mass / pow(height, 2);
    return BMI;
}

void checkRangeBMI(double BMI, string name,
                   vector<string> &niedowagaPeopleBMI,
                   vector<string> &wartoscPrawidlowaPeopleBMI,
                   vector<string> &nadwagaPeopleBMI){
    if (BMI < 18.5){
        niedowagaPeopleBMI.push_back(name);
    }
    else if (18.5 <= BMI && BMI < 25.0){
        wartoscPrawidlowaPeopleBMI.push_back(name);
    }
    else{
        nadwagaPeopleBMI.push_back(name);
    }
}

void printDataVector(vector<string> &dataVector){
    int dataVectorLength = dataVector.size();
    for (int i=0; i<dataVectorLength; i++){
        cout << dataVector[i] << endl;
    }
}

void groupPeopleAccToBMI(vector<string> &niedowagaPeopleBMI,
                         vector<string> &wartoscPrawidlowaPeopleBMI,
                         vector<string> &nadwagaPeopleBMI)
{
    string name;
    double weight;
    double height;
    double BMI;

    int peopleAmount;
    cin >> peopleAmount;
    for (int i = 0; i < peopleAmount; i++){
        cin >> name;
        cin >> weight;
        cin >> height;
        BMI = calculateBMI(weight, height);

        if (BMI < 18.5){
            niedowagaPeopleBMI.push_back(name);
        }
        else if (18.5 <= BMI && BMI < 25.0){
            wartoscPrawidlowaPeopleBMI.push_back(name);
        }
        else{
            nadwagaPeopleBMI.push_back(name);
        }
    }
}

void printDataAboutPeoplesBMI(vector<string> &niedowagaPeopleBMI,
                         vector<string> &wartoscPrawidlowaPeopleBMI,
                         vector<string> &nadwagaPeopleBMI)
{
    cout << "niedowaga" << endl;
    printDataVector(niedowagaPeopleBMI);
    cout << endl;
    cout << "wartosc prawidlowa" << endl;
    printDataVector(wartoscPrawidlowaPeopleBMI);
    cout << endl;
    cout << "nadwaga" << endl;
    printDataVector(nadwagaPeopleBMI);
}


int main()
{
    vector<string> niedowagaPeopleBMI;
    vector<string> wartoscPrawidlowaPeopleBMI;
    vector<string> nadwagaPeopleBMI;
    groupPeopleAccToBMI(niedowagaPeopleBMI, wartoscPrawidlowaPeopleBMI, nadwagaPeopleBMI);
    printDataAboutPeoplesBMI(niedowagaPeopleBMI, wartoscPrawidlowaPeopleBMI, nadwagaPeopleBMI);
    return 0;
}
