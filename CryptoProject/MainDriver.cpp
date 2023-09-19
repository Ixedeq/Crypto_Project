#include <iostream>
#include <bitset>

#include "StringToVector.cpp"
#include "Binary.cpp"
#include "BinaryToDecimal.cpp"
#include "Hex_B64.cpp"
#include "XOR.cpp"

int main(){
    
    std::string EncryptedHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    
    std::string solution = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    std::string converted = Hexb64Converter(EncryptedHex);

    if (solution == converted){
        std::cout << "True\n";
    }
    else{std::cout << "False\n";}

    std::cout << xoring("a", "d") << "\n";
    
    return 0;
}