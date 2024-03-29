/*
This file contains the function/methods definitions of the user defined
header file cutpproh.
*/

// Implementation file for cutpproh.
// Import necessary files. 
#include <string>
#include <algorithm>
// Import user defined header (current directory.)
#include "cutpproh.hpp"

char CutPpRoH::CutPp::GetCharOnPos(const std::string& strng, const int& pos){
    // Return char on pos. 
    return strng.at(pos);
}

std::string CutPpRoH::CutPp::GetCharsBetweenPos(const std::string& strng, const int& frompos, const int& topos)
{   
    // Return char from startposition to difference of (endposition - startposition).
    return strng.substr(frompos,(topos - frompos));
}

std::vector<int> CutPpRoH::CutPp::CalcSepPos(const std::string& strng, const char& sep)
{   
    /* Save string length by changing type from unsinged long long to int. 
    The equivalent would be:

    int strnglen = strng.size().

    Init vector with 0 and string length. This is necessary to calc all fields,
    otherwise the first and last would be missing. 
    The vector can also be initialised with just the 0 and after adding all indizes the 
    stringlength can be added, this would not require a sort of the vector in the end. */
    std::vector<int> seppos = {0, (int) strng.size()};
    // Iterate through string an check i character matches separator.
    // If yes save index of separator.
    for(int i = 0; i < strng.size(); i++){
        if(strng[i] == sep){
            seppos.push_back(i);
        }
    }
    /* Sorting the vector to calc fields right. If the vector is unsoreted, the field calculation
    goes wrong. Because field 0 would be from 0 to end of string, which is not true. */
    sort(seppos.begin(), seppos.end());
    return seppos;
}
// Returns vector of vectors.
// {{x1,xN-1},{y1,yN-1},...}
std::vector<std::vector<int>> CutPpRoH::CutPp::CalcFields(const std::vector<int>& fields, const std::vector<int> seppos)
{   
    // Fieldstart is always 0. 
    int fieldstart = 0;
    // Init vector to save fieldinfos like startposition and length.
    // Vector design: {{x1,xN-1},{y1,yN-1},...}
    std::vector<std::vector<int>> fieldlist;
    // Foreach loop.
    for(int field : fields){
        fieldstart = seppos[field];
        // Add a vector of fieldstart and fieldlength to vector.
        fieldlist.push_back({fieldstart, seppos[field +1] - seppos[field]});
    }
    return fieldlist;
}

std::string CutPpRoH::CutPp::GetFields(const std::string& strng, const std::vector<int>& fields, const char& sep)
{   
    // Result string.
    std::string resstring;
    // Create string vector, to safe content of fields.
    std::vector<std::string> resstringvec;
    // Get separator positions.
    std::vector<int> seppos = CalcSepPos(strng, sep);
    // Calculate fields (startposition, fieldlength).
    std::vector<std::vector<int>> fieldinfo = CalcFields(fields, seppos);
    // Foreach loop.
    for(std::vector f : fieldinfo){
        // Add substring from fieldstart with fieldlength.
        resstringvec.push_back(strng.substr(f[0], f[1]));
    }
    // Join all subvectors(strings) to one string.
    for(std::string s : resstringvec){
        resstring += s;
    }
    return resstring;
}

std::string CutPpRoH::CutPp::GetFieldsNewSeparator(const std::string& strng, const std::vector<int>& fields, const char& oldsep, const char& newsep)
{
    // Get strings inside the fields and replace old separator with new separator.
    std::string resstring = GetFields(strng, fields, oldsep);
    replace(resstring.begin(),resstring.end(),oldsep,newsep);
    return resstring;
}
