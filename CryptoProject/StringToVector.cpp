#include <iostream>

/*This function seperates the string into individual 
characters for easier manipulation*/
std::vector<char> StringToVector(std::string STRING){
    std::vector<char> v;
    std::copy(STRING.begin(), STRING.end(), std::back_inserter(v));

    return v;
}