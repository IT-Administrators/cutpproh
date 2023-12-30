/*
This file is the driver file to illustrate the implementation of 
cutpproh.cpp.

Compile with:
g++ .\main.cpp .\cutpproh.cpp -o cutpproh
*/

#include <iostream>
#include <string>
// User defined header file.
#include "cutpproh.hpp"

using namespace std;

int main(){
    string demostring = "This is a demonstration string.";
    int startpos = 0;
    int endpos = 4;
    const char separator = ' ';
    const char newseparator = ';';
    vector<int> separatorpositions;
    vector<vector<int>> fieldinfos;
    vector<int> flds = {0,3};
    CutPpRoH::CutPp strobj;

    cout << "This is the test string:" << endl;
    cout << demostring << endl;
    cout << endl;
    cout << "The string length is: " << demostring.size() << endl;
    cout << endl;
    cout << "Return char on position: " << startpos << endl;
    cout << strobj.GetCharOnPos(demostring,startpos) << endl;
    cout << endl;
    cout << "Return char from position " << startpos << " to position: " << endpos << endl;
    cout << strobj.GetCharsBetweenPos(demostring, startpos, endpos) << endl;
    cout << endl;
    cout << "Return all indizes of separator:" << separator << endl;
    separatorpositions = strobj.CalcSepPos(demostring, separator);
    for(int i = 0; i < separatorpositions.size(); i++){
        cout << separatorpositions[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Return all fields with startposition and length:" << endl;
    fieldinfos = strobj.CalcFields(flds, separatorpositions);
    // // Overall vector size. Can not be greater than specified fields count.
    // cout << "Vector size: " << fieldinfos.size() << endl;
    // // Iterate through the fieldinfo vector.
    // for(int i = 0; i < fieldinfos.size(); i++){
    //     cout << "Internal vector size: " << fieldinfos[i].size() << endl;
    //     for(int j = 0; j < fieldinfos[i].size(); j++){
    //         cout << fieldinfos[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Iterate through internal vectors and show startposition and fieldlength.
    for(vector<int> v : fieldinfos){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Return the specified fields joined by specified separator." << endl;
    string newstring = strobj.GetFields(demostring,flds,separator);
    cout << newstring;
    cout << endl;
    cout << endl;

    cout << "Return the specified fields joined by new separator." << endl;
    newstring = strobj.GetFieldsNewSeparator(demostring,flds,separator,newseparator);
    cout << newstring;
    return 0;
}