#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

string HexToBase64(const string& hexInput) {
    // Step 1: Convert hexadecimal to binary
    vector<unsigned char> binaryData;
    for (size_t i = 0; i < hexInput.length(); i += 2) {
        string byteString = hexInput.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(stoi(byteString, nullptr, 16));
        binaryData.push_back(byte);
    }

    // Step 2: Convert binary to base64
    string base64Output;
    static const char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    size_t i = 0;
    while (i < binaryData.size()) {
        unsigned char byte1 = binaryData[i++];
        unsigned char byte2 = (i < binaryData.size()) ? binaryData[i++] : 0;
        unsigned char byte3 = (i < binaryData.size()) ? binaryData[i++] : 0;

        unsigned char char1 = byte1 >> 2;
        unsigned char char2 = ((byte1 & 0x03) << 4) | (byte2 >> 4);
        unsigned char char3 = ((byte2 & 0x0F) << 2) | (byte3 >> 6);
        unsigned char char4 = byte3 & 0x3F;

        base64Output += base64Chars[char1];
        base64Output += base64Chars[char2];
        base64Output += base64Chars[char3];
        base64Output += base64Chars[char4];
    }

    // Calculate padding based on the original hex input length
    size_t padding = 3 - (binaryData.size() % 3);
    while (padding-- > 0) {
        base64Output += '=';
    }

    return base64Output;
}

// Function to perform XOR operation on two equal-length buffers as hex strings
string XORHexStrings(const string& hexString1, const string& hexString2) {
    if (hexString1.length() != hexString2.length()) {
        throw runtime_error("Hex strings must have equal length.");
    }

    vector<unsigned char> binaryData1;
    vector<unsigned char> binaryData2;

    // Convert hex strings to binary
    for (size_t i = 0; i < hexString1.length(); i += 2) {
        string byteString1 = hexString1.substr(i, 2);
        string byteString2 = hexString2.substr(i, 2);
        unsigned char byte1 = static_cast<unsigned char>(stoi(byteString1, nullptr, 16));
        unsigned char byte2 = static_cast<unsigned char>(stoi(byteString2, nullptr, 16));
        binaryData1.push_back(byte1);
        binaryData2.push_back(byte2);
    }

    // Perform XOR operation on binary data
    vector<unsigned char> result(binaryData1.size());
    for (size_t i = 0; i < binaryData1.size(); ++i) {
        result[i] = binaryData1[i] ^ binaryData2[i];
    }

    // Convert binary result to hex string
    stringstream hexResult;
    hexResult << hex << uppercase << setfill('0');
    for (unsigned char byte : result) {
        hexResult << setw(2) << static_cast<int>(byte);
    }

    return hexResult.str();


}

std::string xor_decrypt(const std::vector<unsigned char>& ciphertext, unsigned char key) {
    std::string decrypted;
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        decrypted += static_cast<char>(ciphertext[i] ^ key);
    }
    return decrypted;
}

double score_english_text(const std::string& text) {
    // Define the frequency of English letters (in lowercase)
    std::map<char, double> letter_frequency = {
        {'a', 0.0817}, {'b', 0.0149}, {'c', 0.0278}, {'d', 0.0425},
        {'e', 0.1270}, {'f', 0.0223}, {'g', 0.0202}, {'h', 0.0609},
        {'i', 0.0697}, {'j', 0.0015}, {'k', 0.0077}, {'l', 0.0403},
        {'m', 0.0241}, {'n', 0.0675}, {'o', 0.0751}, {'p', 0.0193},
        {'q', 0.0010}, {'r', 0.0599}, {'s', 0.0633}, {'t', 0.0906},
        {'u', 0.0276}, {'v', 0.0098}, {'w', 0.0236}, {'x', 0.0015},
        {'y', 0.0197}, {'z', 0.0007}
    };

    double score = 0.0;
    for (char c : text) {
        char lc = std::tolower(c);
        if (letter_frequency.count(lc)) {
            score += letter_frequency[lc];
        }
    }
    return score;
}

