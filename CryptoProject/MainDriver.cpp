#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Problem8-Detecing AES in ECB mode.cpp"


int main() {

    //Detecting AES in ECB
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
