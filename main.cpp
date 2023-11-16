#include "Util.h"

using namespace std;

int main(){
    ofstream ExternalFile("File.txt"); 


    // // Problem1
    // if(HexToB64(HexToBytes(Problem1_Hex)) == Problem1_Solution){
    //     cout << "Problem1 is working" << endl;
    // }
    // //problem2
    // if(BinaryToHex(Fixed_Xor(HexToBytes(Problem2_Hex1), HexToBytes(Problem2_Hex2))) == Problem2_Solution){
    //     cout << "Problem2 is working" << endl;
    // }
    // //problem3
    // if(SingleByteXor(HexToBytes(Problem3_Hex)) == Problem3_Solution){
    //     cout << "Problem3 is working" << endl;
    // }

    // //problem4
    string test = DetectingSingleXor(Problem4_FileName);
   
    cout << (test) << endl;
    
    //cout << Problem4_solution << endl; 
    //cout << ((test).compare(Problem4_solution))<< endl;    
    // if(((test).compare(Problem4_solution))==0){
    //       cout << "Problem4 is working" << endl; 
    //  }
    // else{
    //     cout << "Wtf" << endl;
    // }
    //cout<<endl<<"4 Solution"<<DetectingSingleXor(Problem4_FileName)<<endl<<endl;

    // if(BinaryToHex(RepeatingKeyXor(Problem5_Stanza, Problem5_Key)) == Problem5_Answer){
    //     cout << "problem5 is working" << endl;
    // }

    // cout << BinaryToHex(B64Decoder())<< endl;
    //BreakXor("breakXor.txt");
    //cout << fileContent;
}