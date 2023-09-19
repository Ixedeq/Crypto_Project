#include <iostream>
#include <bitset>

#include "StringToVector.cpp"
#include "Binary.cpp"
#include "BinaryToDecimal.cpp"
#include "Hex_B64.cpp"
#include "BinaryToHex.cpp"
#include "XOR.cpp"
//#include "SingleCharXor.cpp"

int main(){
    
    std::string EncryptedHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string solution = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   
    if (Hexb64Converter(EncryptedHex) == solution){
        std::cout << "True\n";
    }
    else{std::cout << "False\n";}

    std::string xor1 = "1c0111001f010100061a024b53535009181c";
    std::string xor2 = "686974207468652062756c6c277320657965";
    std::string xorAnswer = "746865206b696420646f6e277420706c6179";

    if (xoring(xor1, xor2) == xorAnswer){
        std::cout << "True\n";
    }
    else{std::cout << "False\n";}

    std::string SingleXor = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    std::cout << xoring(SingleXor, "f") << "\n";
    
    return 0;
}