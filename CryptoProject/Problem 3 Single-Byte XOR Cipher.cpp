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

int main() {
    const std::string hexStr = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    std::string bytes = hexToBytes(hexStr);
   
    double bestScore = 0;
    char bestKey = 0;
    std::string bestDecryption;
   
    for (int c = 0; c <= 255; c++) {
        std::string decrypted = xorWithChar(bytes, char(c));
        double currentScore = scoreEnglishText(decrypted);
        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestKey = char(c);
            bestDecryption = decrypted;
        }
    }
   
    std::cout << "Key: " << bestKey << std::endl;
    std::cout << "Decrypted message: " << bestDecryption << std::endl;

    return 0;
}
