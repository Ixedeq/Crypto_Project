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
    std::vector<char> VEC = StringToVector(STRING);
    std::vector<std::string> result;

    switch (HashIt(TYPE))
    {
        case HEX: 
            for (auto const&c: VEC) {
                switch (c) {
                    case '0':
                        result.insert(result.begin(), "0000");
                        break;
                    case '1':
                        result.insert(result.begin(), "0001");
                        break;
                    case '2':
                        result.insert(result.begin(), "0010");
                        break;
                    case '3':
                        result.insert(result.begin(), "0011");
                        break;
                    case '4':
                        result.insert(result.begin(), "0100");
                        break;
                    case '5':
                        result.insert(result.begin(), "0101");
                        break;
                    case '6':
                        result.insert(result.begin(), "0110");
                        break;
                    case '7':
                        result.insert(result.begin(), "0111");
                        break;
                    case '8':
                        result.insert(result.begin(), "1000");
                        break;
                    case '9':
                        result.insert(result.begin(), "1001");
                        break;
                    case 'A':
                    case 'a':
                        result.insert(result.begin(), "1010");
                        break;
                    case 'B':
                    case 'b':
                        result.insert(result.begin(), "1011");
                        break;
                    case 'C':
                    case 'c':
                        result.insert(result.begin(), "1100");
                        break;
                    case 'D':
                    case 'd':
                        result.insert(result.begin(), "1101");
                        break;
                    case 'E':
                    case 'e':
                        result.insert(result.begin(), "1110");
                        break;
                    case 'F':
                    case 'f':
                        result.insert(result.begin(), "1111");
                        break;
                    case '.':
                        result.insert(result.begin(), ".");
                        break;
                    default:
                        throw std::invalid_argument("\nInvalid hexadecimal digit ");
                        
                    }
            }
            break;
        
        default:
            std::cout<< "Default\n";
            break;
    }
    return result;
}