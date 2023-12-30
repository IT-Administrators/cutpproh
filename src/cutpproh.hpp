/*
This header file contains the function/method declarations for the
cutpproh module.
*/

// Conditional pre processor directive.
// Include guard to prevent importing headerfile more than once.
#ifndef CUTPPROH_H
#define CUTPPROH_H

// Include necessary libraries.
#include <string>
#include <vector>
// Define namespaces.
using namespace std;

// Create class.
class CutPpRoH {
    // Public variables and methods than can be used outside the class.
    public:
        // Define class methods.

        /* Used the & operator (pass by reference) to save space. 
        
        Referencing a variable saves space, because the variable which is called by reference 
        is only created once. 

        For example:

        string s = "Test"; Creates a string s which is allocated memory to. 
        string t = s; Creates a string t which is also allocated memory to, by copiing string s.
        This uses double the space than using a reference.
        string& t = s; Uses a changeable reference which points to the memory position of s. So the memory is
        only allocated once. Changing the reference will also change the string s, which can than use more/less
        memory than before.
        const string& t = s; Uses a nonchangeable reference (const) to s. If the reference is changed, string s
        is not changed. The allocated memory is always the same.

        Using an unchangeable reference also gives the opportunity, to call the method/function using variables
        and values. While using a changeable reference the methond/function can only be called by using 
        variables.
        
        The string and the integer are not copied, so they only exist once. 
        The return type must be char because, retrieving a char from a string is type std::char. 
        std::string is defined as class CharT[]. 
        https://en.cppreference.com/w/cpp/string/basic_string */
        char GetCharOnPos(const string& strng, const int& pos); 
        /* Returns chars between starting position until endposition, which is calculated via the 
        difference of endposition - startposition.
        If the start position is smaller than the end position, all characters between
        these positions are returned. 
        If startposition is bigger than the endposition, all characters between startposition until
        end of line are returned. */
        string GetCharBetweenPos(const string& strng, const int& frompos, const int& topos);
        /* Calculate separator positions. This function is a helper function for the field calculation. 
        The separator indizes are important because they are the borders for the field calculation. */
        vector<int> CalcSepPos(const string& strng,const char& sep);
        /* Calculate field informations (starting position and length). This function is a helpfer function for the field calculation. 
        The return type needs to be a vector of int vectors, because this way every field can be 
        processed on it's own later on. 
        vector<vector<int>> = {{x1,xN-1},{y1,yN-1},...} */
        vector<vector<int>> CalcFields(const vector<int>& fields, const vector<int> seppos);
        /* Returns the specified fields and joins them using the same separator*/
        string GetFields(const string& strng, const vector<int>& fields, const char& sep);
        /* Returns the specified fields and joins them using new separator. */
        string GetFieldsNewSeparator(const string& strng, const vector<int>& fields, const char& oldsep, const char& newsep);
};

#endif