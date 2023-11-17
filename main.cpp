#include "Util.h"

using namespace std;

int main(){
    ofstream ExternalFile("File.txt"); 


    // Problem1
    if(HexToB64(HexToBytes(Problem1_Hex)) == Problem1_Solution){
        cout << "Problem1 is working" << endl;
    }
    //problem2
    if(BinaryToHex(Fixed_Xor(HexToBytes(Problem2_Hex1), HexToBytes(Problem2_Hex2))) == Problem2_Solution){
        cout << "Problem2 is working" << endl;
    }
    //problem3
    if(SingleByteXor(HexToBytes(Problem3_Hex)) == Problem3_Solution){
        cout << "Problem3 is working" << endl;
    }

    //problem4
    string test = DetectingSingleXor(Problem4_FileName);

    if((test == Problem4_solution)){
        cout << "Problem4 is working" << endl; 
    }

    //problem5
    if(BinaryToHex(RepeatingKeyXor(Problem5_Stanza, Problem5_Key)) == Problem5_Answer){
        cout << "problem5 is working" << endl;
    }

    // cout << BinaryToHex(B64Decoder())<< endl;
    //BreakXor("breakXor.txt");
    //cout << fileContent;

     /************************************
     Problem 8: Detecting AES in ECB main code-zo
    *************************************/
    std::ifstream infile("/crypto_proj/Problem8.txt"); // Replace with your file path
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
}
