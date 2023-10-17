#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {
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
    return 0;
}
