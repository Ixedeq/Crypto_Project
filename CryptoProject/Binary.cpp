#include <iostream>
#include <bitset>
#include "StringToVector.cpp"

/*Sets values to strings since switch statement does not accept strings
I am using this for posible multiple cases of bitset*/
enum VAL{
    HEX
};

VAL HashIt(std::string TYPE){
    if(TYPE == "HEX") return HEX;
    return HEX;
}

std::vector<std::string> ToBinary(std::string STRING, std::string TYPE){
    std::vector<char> CHARS = StringToVector(STRING);
    std::vector<std::string> Binary;

    switch (HashIt(TYPE))
    {
        case HEX: 
            for (const char &c: CHARS) {
                Binary.insert(Binary.end(),  std::bitset<8>(c).to_string());
            }
            break;
        
        default:
            break;
    }
    return Binary;
}