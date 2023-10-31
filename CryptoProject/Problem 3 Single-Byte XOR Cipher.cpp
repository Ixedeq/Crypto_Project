#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

std::string hexToBytes(const std::string &hex) {
    std::string bytes;
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        bytes.append(1, byte);
    }
    return bytes;
}

double scoreEnglishText(const std::string &text) {
    static const std::string freq = "etaoinshrdlcumwfgypbvkjxqz";
    double score = 0;
    for (char c : text) {
        char lower = tolower(c);
        size_t pos = freq.find(lower);
        if (pos != std::string::npos) {
            score += (freq.size() - pos);
        }
    }
    return score;
}

std::string xorWithChar(const std::string &input, char c) {
    std::string output;
    for (char i : input) {
        output += i ^ c;
    }
    return output;
}

