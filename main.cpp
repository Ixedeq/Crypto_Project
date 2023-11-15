#include "Util.h"

using namespace std;

int main(){
    // cout << BinaryToHex(B64Decoder())<< endl;
    vector<string> oneByte, twoByte;
    string Test1 = "this is a test";
    string Test2 = "wokka wokka!!!";

    for(int i = 0; i < Test1.length(); i++){
        oneByte.insert(oneByte.end(), CharToByte(Test1[i]).begin(), CharToByte(Test1[i]).end());
        twoByte.insert(twoByte.end(), CharToByte(Test2[i]).begin(), CharToByte(Test2[i]).end());
    }
    BreakXor("breakXor.txt");
    //cout << fileContent;
}