#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <openssl/bio.h>
#include <openssl/evp.h>

// Calculate Hamming distance
int hammingDistance(const std::string& s1, const std::string& s2) {
    int distance = 0;
    for (size_t i = 0; i < s1.size(); ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            if ((s1[i] >> bit) & 1 != (s2[i] >> bit) & 1) {
                ++distance;
            }
        }
    }
    return distance;
}

// Evaluate text's resemblance to English (Stub)
double scoreEnglishText(const std::string& text) {
    return 0.0; 
}

// XOR input with a single byte key
std::string singleByteXOR(const std::string& input, char key) {
    std::string output;
    for(char c : input) {
        output.push_back(c ^ key);
    }
    return output;
}

// Identify most probable single-byte XOR key
char findSingleByteXORKey(const std::string& cipher) {
    char probableKey = 0;
    double maxScore = std::numeric_limits<double>::lowest();

    for(int key = 0; key < 256; ++key) {
        std::string decrypted = singleByteXOR(cipher, static_cast<char>(key));
        double score = scoreEnglishText(decrypted);
        if(score > maxScore) {
            maxScore = score;
            probableKey = static_cast<char>(key);
        }
    }
    return probableKey;
}

// Calculate probable key size using normalized edit distance
size_t computeKeySize(const std::string& ciphertext) {
    size_t probableKeySize = 0;
    double minNormalizedDistance = std::numeric_limits<double>::max();

    for(size_t keysize = 2; keysize <= 40; keysize++) {
        std::string chunk1 = ciphertext.substr(0, keysize);
        std::string chunk2 = ciphertext.substr(keysize, keysize);
        double normalizedDistance = static_cast<double>(hammingDistance(chunk1, chunk2)) / keysize;
        
        if(normalizedDistance < minNormalizedDistance) {
            minNormalizedDistance = normalizedDistance;
            probableKeySize = keysize;
        }
    }
    return probableKeySize;
}

// Generate transposed blocks for analysis
std::vector<std::string> transposeBlocks(const std::string& ciphertext, size_t keysize) {
    std::vector<std::string> transposedBlocks(keysize);
    for(size_t i = 0; i < ciphertext.size(); i += keysize) {
        std::string block = ciphertext.substr(i, keysize);
        for(size_t j = 0; j < block.size(); ++j) {
            transposedBlocks[j].push_back(block[j]);
        }
    }
    return transposedBlocks;
}

// Decode base64 string
std::string decodeBase64(const std::string& base64) {
    BIO* b64 = BIO_new(BIO_f_base64());
    BIO* bmem = BIO_new_mem_buf(base64.c_str(), static_cast<int>(base64.length()));
    b64 = BIO_push(b64, bmem);
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // Ignore newlines - write everything in one line
    std::vector<char> buffer(base64.length());
    int decodedSize = BIO_read(b64, buffer.data(), static_cast<int>(buffer.size()));
    BIO_free_all(b64);
    return std::string(buffer.data(), decodedSize);
}

// Decrypt repeated-key XOR'd text
void decryptRepeatingKeyXOR(const std::string& base64Ciphertext) {
    // Assumption: base64Ciphertext is base64 decoded
    
    size_t keySize = computeKeySize(base64Ciphertext);
    
    std::vector<std::string> transposedBlocks = transposeBlocks(base64Ciphertext, keySize);
    
    std::string key;
    for(const auto& block : transposedBlocks) {
        char keyByte = findSingleByteXORKey(block);
        key.push_back(keyByte);
    }

    // std::string decryptedMessage = repeatingKeyXOR(base64Ciphertext, key); // This function is not defined
    // std::cout << "Decrypted message: " << decryptedMessage << std::endl;
}
