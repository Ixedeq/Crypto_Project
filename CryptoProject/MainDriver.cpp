#include <iostream>
#include <bitset>

#include "StringToVector.cpp"
#include "Binary.cpp"
#include "BinaryToDecimal.cpp"
#include "Hex_B64.cpp"
#include "BinaryToHex.cpp"
#include "XOR.cpp"
//#include "SingleCharXor.cpp"

int main(){
    
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

    //Problems 4 and 5-Tony
        string hexInput = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    string base64Output = HexToBase64(hexInput);
    cout << "Hex: " << hexInput << endl;
    cout << "Base64: " << base64Output << endl;

    string hexString1 = "1c0111001f010100061a024b53535009181c";
    string hexString2 = "686974207468652062756c6c277320657965";

    try {
        string xorResult = XORHexStrings(hexString1, hexString2);
        cout << "Hex String 1: " << hexString1 << endl;
        cout << "Hex String 2: " << hexString2 << endl;
        cout << "XOR Result: " << xorResult << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
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

    cout << "Best Key: " << static_cast<int>(best_key) << endl;
    cout << "Decrypted Message: " << best_decrypted_message << endl;

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

    cout << "Best Key: " << static_cast<int>(best_key) << endl;
    cout << "Decrypted Message: " << best_decrypted_message << endl;
    
    
    return 0;
}
