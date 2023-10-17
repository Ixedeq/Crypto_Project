#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Problem 8-Detecing AES in ECB mode.cpp"
#include "Problem 5 Repeating-key_XOR.cpp"
#include "Problem 6 Decrypting Repeating-Key XOR with Hamming Distance in C++.cpp"
#include "Problem 7 Decrypting AES-128-ECB with OpenSSL.cpp"


int main() {
     // Repeating Key XOR main code
     // Example plaintext
    std::string plaintext =
        "Burning 'em, if you ain't quick and nimble\n"
        "I go crazy when I hear a cymbal";
    
    std::string key = "ICE";  // Encryption key

    // Encrypt the plaintext
    std::string ciphertext = repeating_key_xor(plaintext, key);
    
    // Expected ciphertext in hexadecimal format
    std::string expected_hex = 
        "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272"
        "a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
    
    // Check if the generated ciphertext matches the expected hex
    if (ciphertext == expected_hex) {
        std::cout << "Ciphertext matches expected hex." << std::endl;
    } else {
        std::cout << "Mismatch detected!" << std::endl;
    }
    
    // Output the plaintext and ciphertext to the console
    std::cout << "Plaintext:\n" << plaintext << "\n\n";
    std::cout << "Ciphertext:\n" << ciphertext << "\n";

     //decrypting repeating key in main
     std::string str1 = "this is a test";
    std::string str2 = "wokka wokka!!!";
    std::cout << "Hamming distance: " << hammingDistance(str1, str2) << std::endl;  
    
    std::string base64Ciphertext = "VGhpcyBpcyBhIHRlc3QgbWVzc2FnZQ=="; // Example base64 encoded string ("This is a test message")
    std::string decodedCiphertext = decodeBase64(base64Ciphertext);
    
    decryptRepeatingKeyXOR(decodedCiphertext);


    //Detecting AES in ECB main code
    std::ifstream infile("/mnt/data/8.txt"); // Replace with your file path
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    size_t line_number = 0;
    size_t block_size = 32; // AES block size is 16 bytes, but we're working with hex so it's 32 characters
    while (std::getline(infile, line)) {
        line_number++;
        if (has_repeating_blocks(line, block_size)) {
            std::cout << "Ciphertext on line " << line_number << " is likely encrypted with AES in ECB mode." << std::endl;
        }
    }

    infile.close();

    //Decrypting AES-128-ECB with OpenSSL
    std::string base64_encrypted_data = "your_base64_encrypted_data_here";
    std::string key = "YELLOW SUBMARINE";

    std::string encrypted_data = decode_base64(base64_encrypted_data);
    std::string decrypted_data = decrypt_aes_ecb(encrypted_data, key);

    std::cout << "Decrypted data: " << decrypted_data << std::endl;
    
    return 0;
}
