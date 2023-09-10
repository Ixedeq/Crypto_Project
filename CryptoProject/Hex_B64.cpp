
#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
#include <vector>

std::vector<std::byte> getBytes(std::string const &s)
{
    std::vector<std::byte> bytes;
    bytes.reserve(std::size(s));
 
    std::transform(std::begin(s), std::end(s), std::back_inserter(bytes), [](char const &c){
        return std::byte(c);
    });
 
    return bytes;
}
 

void Hexb64Converter(std::string HEX){
    std::vector<std::byte> bytes = getBytes(HEX);
 
    for (auto byte: bytes) {
        std::cout << std::to_integer<int>(byte) << ' ';
    }
}
