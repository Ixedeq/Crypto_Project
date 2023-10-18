#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Function to perform the repeating-key XOR operation
std::string repeating_key_xor(const std::string& plaintext, const std::string& key) {
    std::ostringstream oss;  // Using a string stream to build the hex output
    
    // Loop through each character in the plaintext
    for (size_t i = 0; i < plaintext.size(); ++i) {
        // XOR the current character with the corresponding key character
        char xor_result = plaintext[i] ^ key[i % key.size()];
        
        // Convert the XOR result to a two-digit hex value and add it to the output stream
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(xor_result);
    }
    
    return oss.str();  // Convert the stream to a string and return it
}
 
