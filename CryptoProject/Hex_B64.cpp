
#include <iostream>
#include "Binary.cpp"

void Hexb64Converter(std::string HEX){
    std::vector<std::string> Binary = ToBinary(HEX, "HEX");
    for (auto const&c: Binary) {
        std::cout << c << " ";
    }
}
