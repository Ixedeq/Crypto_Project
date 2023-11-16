#pragma once 
#include <iostream> 
#include <bitset>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ofstream ExternalFile("File.txt"); 

const string Problem1_Hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
const string Problem1_Solution = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

const string Problem2_Hex1 = "1c0111001f010100061a024b53535009181c";
const string Problem2_Hex2 = "686974207468652062756c6c277320657965";
const string Problem2_Solution = "746865206b696420646f6e277420706c6179";

const string Problem3_Hex = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
const string Problem3_Solution = "Cooking MC's like a pound of bacon";

const string Problem4_FileName = "HexList.txt";
const string Problem4_solution = "Now that the party is jumping\n";

const string Problem5_Stanza = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
const string Problem5_Key = "ICE";
const string Problem5_Answer = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";

vector<string> HexToBytes(const string& hex) {
  vector<string> ByteString;
  try{
    if(hex.length() % 2 == 0){
    }
    else{
      throw hex;
    }
  }
  catch(...){
    cout << ("Must be an even amount of hex digits\n");
    exit(0);
  }
  for (int i = 0; i < hex.length(); i++) {
    switch (hex[i]) {
      case '0':{
          ByteString.insert(ByteString.end(), "0000");
          break;
      }
      case '1':{
          ByteString.insert(ByteString.end(), "0001");
          break;
      }
      case '2':{
          ByteString.insert(ByteString.end(), "0010");
          break;
      }
      case '3':{
          ByteString.insert(ByteString.end(), "0011");
          break;
      }
      case '4':{
          ByteString.insert(ByteString.end(), "0100");
          break;
      }
      case '5':{
          ByteString.insert(ByteString.end(), "0101");
          break;
      }
      case '6':{
          ByteString.insert(ByteString.end(), "0110");
          break;
      }
      case '7':{
          ByteString.insert(ByteString.end(), "0111");
          break;
      }
      case '8':{
          ByteString.insert(ByteString.end(), "1000");
          break;
      }
      case '9':{
          ByteString.insert(ByteString.end(), "1001");
          break;
      }
      case 'A':
      case 'a':{
          ByteString.insert(ByteString.end(), "1010");
          break;
      }
      case 'B':
      case 'b':{
          ByteString.insert(ByteString.end(), "1011");
          break;
      }
      case 'C':
      case 'c':{
          ByteString.insert(ByteString.end(), "1100");
          break;
      }
      case 'D':
      case 'd':{
          ByteString.insert(ByteString.end(), "1101");
          break;
      }
      case 'E':
      case 'e':{
          ByteString.insert(ByteString.end(), "1110");
          break;
      }
      case 'F':
      case 'f':{
          ByteString.insert(ByteString.end(), "1111");
          break;
      }
      case '.':{
          ByteString.insert(ByteString.end(), ".");
          break;
      }
      default:{
          throw invalid_argument("\nInvalid hexadecimal digit ");
      }
    }
  }
  ///Test code to make sure that the proper bytes are returned///
  // for(int i = 0; i < ByteString.size(); i++){
  //   cout << ByteString[i] << endl;
  // }          
  return ByteString;
}
string HexToB64(vector<string> ByteString){
  
  char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; 
  string AllBytes;
  string tempSegment;
  vector<int> segmentedBytes;
  string encrypted;

  for(int i = 0; i < ByteString.size(); i++){
    AllBytes.append(ByteString[i]);
  }

  for(int i = 0; i < AllBytes.length(); i++){
    if(i % 6 == 0 && i != 0){
      segmentedBytes.insert(segmentedBytes.end(), stoi(tempSegment, 0, 2));
      tempSegment = "";
    }
    tempSegment += AllBytes[i];
  }

  if (tempSegment.length() == 6){
    segmentedBytes.insert(segmentedBytes.end(), stoi(tempSegment, 0, 2));
  }
  else {
    while(tempSegment.length() != 6){
      tempSegment += '0';
      if (tempSegment.length() == 6){
        segmentedBytes.insert(segmentedBytes.end(), stoi(tempSegment, 0, 2));
        segmentedBytes.insert(segmentedBytes.end(), 64);
      }
    }
  }

  for(int i = 0; i < segmentedBytes.size(); i++){
    encrypted += char_set[segmentedBytes[i]];
  }

  return encrypted;    
}
vector<string> B64Decoder(string B64String){
  vector<int> B64Num;
  string binary;
  vector<string> BinaryBytes;

  string char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

  if (B64String.back() == '='){
    B64String.pop_back();
  } 
  for(int j = 0; j < B64String.length(); j++){
    for (int i = 5; i >= 0; i--) { 
      int k = char_set.find(B64String[j]) >> i; 
      if (k & 1){
        binary += '1'; 
      }
      else{
        binary += '0'; 
      }
    }
  }
  string temp;
  for(int i = 1; i < binary.length()+1; i++){
    temp += binary[i-1];
    if((i) % 4 == 0){
      BinaryBytes.insert(BinaryBytes.end(), temp);
      temp = "";
    }
  }
  return BinaryBytes;
  
}
string BinaryToHex(vector<string> Binary){
    string hex = "";
    for(int i = 0; i < Binary.size(); i++){
        switch (stoi(Binary[i], 0, 2)){
            case 0:
                hex += "0";
                break;
            case 1:
                hex += "1";
                break;
            case 2:
                hex += "2";
                break;
            case 3:
                hex += "3";
                break;
            case 4:
                hex += "4";
                break;
            case 5:
                hex += "5";
                break;
            case 6:
                hex += "6";
                break;
            case 7:
                hex += "7";
                break;
            case 8:
                hex += "8";
                break;
            case 9:
                hex += "9";
                break;
            case 10:
                hex += "a";
                break;
            case 11:
                hex += "b";
                break;
            case 12:
                hex += "c";
                break;
            case 13:
                hex += "d";
                break;
            case 14:
                hex += "e";
                break;
            case 15:
                hex += "f";
                break;
            default: 
                throw invalid_argument("\nInvalid hexadecimal digit ");
                exit(0);
        }
    }
    return hex;
}
vector<string> Fixed_Xor(vector<string> ByteString1, vector<string> ByteString2){
  vector<string> fullXor;
  string currentXor;
  try{
    if(ByteString1.size() == ByteString2.size()){
    }
    else {
      throw 505;
    }
  }
  catch(...){
    cout << "Not the same amount of bytes" << endl;
    exit(0);
  }
  for(int i = 0; i < ByteString1.size(); i++){
    for(int j = 0; j < ByteString1[i].length(); j++){
      currentXor += ((ByteString1[i][j]-'0')^(ByteString2[i][j]-'0'))+'0';
    }
    fullXor.insert(fullXor.end(), currentXor);
    currentXor = "";
  }
  return fullXor;
}
string BinaryToText(vector<string> binary) {
    string binaryString;
    for(int i = 0; i < binary.size(); i++){
      binaryString.append(binary[i]);
    }
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    text.pop_back();
    return text;
}
vector<string> CharToByte(int n) { 
  string binary;
  vector<string> BinaryBytes;

  for (int i = 7; i >= 0; i--) { 
      int k = n >> i; 
      if (k & 1){
        binary += '1'; 
      }
      else{
        binary += '0'; 
      }
      if(i%4 == 0 && i != 0){
        BinaryBytes.insert(BinaryBytes.end(), binary);
        binary = "";
      }
  }
  BinaryBytes.insert(BinaryBytes.end(), binary); 
  return BinaryBytes;
} 
double scoreEnglishText(const std::string &text) {
    static const std::string freq = "etaoinshrdlcumwfgypbvkjxqzETAOINSHRDLCUMWFGYPBVKJXQZ";
    double score = 0;
    for (int i = 0; i < text.length(); i++) {
        size_t pos = freq.find(text[i]);
        if (pos != std::string::npos) {
            score += (freq.size() - pos);
        }
    }
    return score;
}
vector<string> RepeatingKeyXor(string stanza, string keys){
  int keyIndex = 0;
  vector<string> Binary;
  vector<string> TempBinary;
  for(int i = 0; i < stanza.size(); i++){
      if(keyIndex >= keys.length()){
          keyIndex = 0;
      }
      stanza[i] = stanza[i] ^ keys[keyIndex];
      keyIndex++;
  }
  // for(int i = 0; i < stanza.size(); i++){
  //     hex += BinaryToHex(CharToByte(stanza[i]));
  // }
  for(int i = 0; i < stanza.size(); i++){
    TempBinary = CharToByte(stanza[i]);
    Binary.insert(Binary.end(), TempBinary.begin(), TempBinary.end());
  }
  // return hex;
  return Binary;
}
string SingleByteXor(vector<string> Binary){
  double score = 0;
  double tempscore;
  char ToChar;
  string ToString, result;
  vector<string> XoredString;

  string Text = BinaryToText(Binary);
  string processedText;

  for(int Char = 0; Char < 256; Char++){
    ToChar = Char;
    ToString = ToChar;
    processedText = BinaryToText(RepeatingKeyXor(Text, ToString));
    tempscore = scoreEnglishText(processedText);
    if(tempscore > score){
      score = tempscore;
      //ExternalFile << processedText << endl;
      result = processedText;
    }
  }
  return result;
}
string DetectingSingleXor(string FileName){
  ifstream file (FileName);

  double score = 0;
  double tempScore;
  string Answer, xored, line;

  while(file){
    file >> line;
    if(file){
      xored = SingleByteXor(HexToBytes(line));
      tempScore = scoreEnglishText(xored);
      if(tempScore > score){
        score = tempScore;
        Answer = xored;
      }
    }
  }
  return Answer;
}
int hammingDist(string oneString, string twoString) { 
    vector<string> stringOne, stringTwo;

    int hammingDist = 0;
    for(int i = 0; i<oneString.length(); i++){
        if(oneString[i]!= twoString[i]){
            hammingDist++;
        }
    }

    return hammingDist;
} 
string BreakXor(string FileName){
  ifstream file(FileName);
  string fileContent;

  for( string line; getline( file, line ); ){
    fileContent += line;
  }

  vector<string> FileBytes = B64Decoder(fileContent);
  string Tempbytes1;
  string Tempbytes2;
  vector<int> Distances;
  vector<int> TempDist;

  int KEY_SIZE;

  for(int KEYSIZE = 2; KEYSIZE < (FileBytes.size()/2); KEYSIZE++){
    for(int i = 0; i < KEYSIZE; i++){
      Tempbytes1 += (FileBytes[i]);
      Tempbytes2 += (FileBytes[i+KEYSIZE]);
    }
    Distances.insert(Distances.end(), (hammingDist(Tempbytes1, Tempbytes2)));
    Tempbytes1 = "";
    Tempbytes2 = "";
  }
  TempDist = Distances;
  sort(Distances.begin(), Distances.end());

  for(int i = 0; i < TempDist.size(); i++){
    if (Distances[0] == TempDist[i]){
      KEY_SIZE = i+2;
      break;
    }
  }

  TempDist.clear();
  Distances.clear();

  int fileIndex = 0;
  string blockString;
  vector<string> block;
  
  fileContent = BinaryToText(FileBytes);
  for(int i = 0; i < fileContent.length(); i++){
    if(fileIndex > KEY_SIZE){
      block.push_back(blockString);
      blockString = "";
      fileIndex = 0;
    }
    blockString += fileContent[i];
    fileIndex++;
  }

  string transposedContent;
  vector<string> transposedBlock;

  for(int i = 0; i<KEY_SIZE; i++){
    for(int k = 0; k < block.size(); k++){
      transposedContent += block[k][i];
    }
    transposedBlock.push_back(transposedContent);
    transposedContent = "";
  }
  for(int i = 0; i < transposedBlock.size(); i++){
    cout<<"Block "<<i<<endl<<endl;
    cout<<transposedBlock[i]<<endl<<endl<<endl;
  }


  return "hi";
}

