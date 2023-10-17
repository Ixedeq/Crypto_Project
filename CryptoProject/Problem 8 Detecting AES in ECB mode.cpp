#include <iostream>
#include <fstream>
#include <string>
#include <set>

bool has_repeating_blocks(const std::string& ciphertext, size_t block_size) {
    std::set<std::string> seen_blocks;
    for (size_t i = 0; i < ciphertext.size(); i += block_size) {
        std::string block = ciphertext.substr(i, block_size);
        if (seen_blocks.find(block) != seen_blocks.end()) {
            // Repeating block found
            return true;
        }
        seen_blocks.insert(block);
    }
    return false;
}
