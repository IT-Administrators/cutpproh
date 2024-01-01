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

/* Created a namespace to use it in larger projects. 
The class and its methods can be accessed in two ways: 
- Direct call:
    CutPpRoH::CutPp::Methodname(){}

Using the direct call, only the specified class/method inside that namespace is called.

- Using directive:
    using namespace CutPpRoH;
    CutPp::Methodname(){}

The using directive imports the complete namespace, even the parts that might be
unnessary. */
namespace CutPpRoH {

    // Create class.
    class CutPp {
        /* There's no custom constructor created. The class uses the default constructor/ desctructor created
        by c++. */

        // Public variables and methods that can be used outside the class.
        public:
            // Define class methods.

            /* Used the & operator (pass by reference) to save space. 
            
            Referencing a variable saves space, because the variable which is called by reference 
            is only created once. 

            For example:

            string s = "Test"; Creates a string s which is allocated memory to. 
            string t = s; Creates a string t which is also allocated memory to, by copiing string s.
            This uses double the space than using a reference.
            std::string& t = s; Uses a changeable reference which points to the memory position of s. So the memory is
            only allocated once. Changing the reference will also change the string s, which can than use more/less
            memory than before.
            const std::string& t = s; Uses a nonchangeable reference (const) to s. If the reference is changed, string s
            is not changed. The allocated memory is always the same.

            Using an unchangeable reference also gives the opportunity, to call the method/function using variables
            and values. While using a changeable reference the methond/function can only be called by using 
            variables.
            
            The string and the integer are not copied, so they only exist once. 
            The return type must be char because, retrieving a char from a string is type std::char. 
            std::string is defined as class CharT[]. 
            https://en.cppreference.com/w/cpp/string/basic_string */
            char GetCharOnPos(const std::string& strng, const int& pos); 
            /* Returns chars between starting position until endposition, which is calculated via the 
            difference of endposition - startposition.
            If the start position is smaller than the end position, all characters between
            these positions are returned. 
            If startposition is bigger than the endposition, all characters between startposition until
            end of line are returned. */
            std::string GetCharsBetweenPos(const std::string& strng, const int& frompos, const int& topos);
            /* Calculate separator positions. This function is a helper function for the field calculation. 
            The separator indizes are important because they are the borders for the field calculation. */
            std::vector<int> CalcSepPos(const std::string& strng,const char& sep);
            /* Calculate field informations (starting position and length). This function is a helpfer function for the field calculation. 
            The return type needs to be a vector of int vectors, because this way every field can be 
            processed on it's own later on. 
            std::vector<std::vector<int>> = {{x1,xN-1},{y1,yN-1},...} */
            std::vector<std::vector<int>> CalcFields(const std::vector<int>& fields, const std::vector<int> seppos);
            /* Returns the specified fields and joins them using the same separator*/
            std::string GetFields(const std::string& strng, const std::vector<int>& fields, const char& sep);
            /* Returns the specified fields and joins them using new separator. */
            std::string GetFieldsNewSeparator(const std::string& strng, const std::vector<int>& fields, const char& oldsep, const char& newsep);
    };
}
#endif