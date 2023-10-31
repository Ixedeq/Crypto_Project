#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Problem 8-Detecing AES in ECB mode.cpp"
#include "Problem 5 Repeating-key_XOR.cpp"
#include "Problem 6 Decrypting Repeating-Key XOR with Hamming Distance in C++.cpp"
#include "Problem 7 Decrypting AES-128-ECB with OpenSSL.cpp"
#include "StringToVector.cpp"
#include "Binary.cpp"
#include "BinaryToDecimal.cpp"
#include "Hex_B64.cpp"
#include "BinaryToHex.cpp"
#include "XOR.cpp"
#include "Problems 4 and 5"
#include "Problem 3 Single-Byte XOR Cipher.cpp"

int main() {

     //Alex
     std::string EncryptedHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string solution = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   
    if (Hexb64Converter(EncryptedHex) == solution){
        std::cout << "True\n";
    }
    else{std::cout << "False\n";}

    std::string xor1 = "1c0111001f010100061a024b53535009181c";
    std::string xor2 = "686974207468652062756c6c277320657965";
    std::string xorAnswer = "746865206b696420646f6e277420706c6179";

    if (xoring(xor1, xor2) == xorAnswer){
        std::cout << "True\n";
    }
    else{std::cout << "False\n";}

    std::string SingleXor = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    std::cout << xoring(SingleXor, "f") << "\n";  

     
     // Repeating Key XOR main code -zo
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

     //decrypting repeating key in main - zo
     std::string str1 = "this is a test";
    std::string str2 = "wokka wokka!!!";
    std::cout << "Hamming distance: " << hammingDistance(str1, str2) << std::endl;  
    
    std::string base64Ciphertext = "VGhpcyBpcyBhIHRlc3QgbWVzc2FnZQ=="; // Example base64 encoded string ("This is a test message")
    std::string decodedCiphertext = decodeBase64(base64Ciphertext);
    
    decryptRepeatingKeyXOR(decodedCiphertext);


    //Detecting AES in ECB main code-zo
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

    //Decrypting AES-128-ECB with OpenSSL-Zo
    std::string base64_encrypted_data = "your_base64_encrypted_data_here";
    std::string key = "YELLOW SUBMARINE";

    std::string encrypted_data = decode_base64(base64_encrypted_data);
    std::string decrypted_data = decrypt_aes_ecb(encrypted_data, key);
    std::cout << "Decrypted data: " << decrypted_data << std::endl;

     /************************
          Problem 3 - Zo
     *************************/
   

    /**************************
         Problems 4 and 5-Tony
     **************************/
    string hexInput = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    string base64Output = HexToBase64(hexInput);
    std::cout << "Hex: " << hexInput << std::endl;
    std::cout << "Base64: " << base64Output << std::endl;

    string hexString1 = "1c0111001f010100061a024b53535009181c";
    string hexString2 = "686974207468652062756c6c277320657965";

    try {
        string xorResult = XORHexStrings(hexString1, hexString2);
        std::cout << "Hex String 1: " << hexString1 << std::endl;
        std::cout << "Hex String 2: " << hexString2 << std::endl;
        std::cout << "XOR Result: " << xorResult << std::endl;
    }
    catch (const exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }

    string encrypted_hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    vector<unsigned char> encrypted_bytes;

    for (size_t i = 0; i < encrypted_hex.length(); i += 2) {
        string byteString = encrypted_hex.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(stoi(byteString, nullptr, 16));
        encrypted_bytes.push_back(byte);
    }

    unsigned char best_key = 0;
    double best_score = 0;
    string best_decrypted_message;

    for (unsigned char key = 0; key < 256; ++key) {
        string decrypted = xor_decrypt(encrypted_bytes, key);
        double score = score_english_text(decrypted);

        if (score > best_score) {
            best_score = score;
            best_key = key;
            best_decrypted_message = decrypted;
        }
    }

    std::cout << "Best Key: " << static_cast<int>(best_key) << std::endl;
    std::cout << "Decrypted Message: " << best_decrypted_message << std::endl;

    ifstream file("crypto.txt");  

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    unsigned best_key2 = 0;
    double best_score2 = 0;
    string best_decrypted_message2;

    while (getline(file, line)) {
        // Process each line in the file
        string encrypted_hex = line;
        vector<unsigned char> encrypted_bytes;

        for (size_t i = 0; i < encrypted_hex.length(); i += 2) {
            string byteString = encrypted_hex.substr(i, 2);
            unsigned char byte = static_cast<unsigned char>(stoi(byteString, nullptr, 16));
            encrypted_bytes.push_back(byte);
        }

        for (unsigned char key = 0; key < 256; ++key) {
            string decrypted = xor_decrypt(encrypted_bytes, key);
            double score = score_english_text(decrypted);

            if (score > best_score) {
                best_score2 = score;
                best_key2 = key;
                best_decrypted_message2 = decrypted;
            }
        }
    }

    std::cout << "Best Key: " << static_cast<int>(best_key) << std::endl;
    std::cout << "Decrypted Message: " << best_decrypted_message << std::endl;
    
    
    return 0;
}
