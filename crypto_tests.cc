#include <gtest/gtest.h>
#include "Util.h"

TEST(HexToBytesTests, TryCatch){
  EXPECT_EXIT(HexToBytes("1"),testing::ExitedWithCode(0), "");
}
TEST(HexToBytesTests, SwitchCase){
  EXPECT_NO_THROW(HexToBytes("00123456789aAbBcCdDeEfF"));
  EXPECT_EQ(HexToBytes("0123456789abcdef")[0], "0000");
  EXPECT_EQ(HexToBytes("0123456789abcdef")[16], "1111");
  EXPECT_ANY_THROW(HexToBytes("G"));
}
TEST(HexToB64Tests, ProperReturn){
  EXPECT_EQ(HexToB64(HexToBytes("0123456789abcdef")), "ASNFZ4mrze8=");
  EXPECT_EQ(HexToB64(HexToBytes("1f2b")), "Hys=");
  EXPECT_EQ(HexToB64(HexToBytes(Problem1_Hex)), Problem1_Solution);
}
TEST(CryptoProblems, Problem1){
  // expect equality 
  EXPECT_EQ(HexToB64(HexToBytes(Problem1_Hex)), Problem1_Solution);
}
TEST(CryptoProblems, Problem2){
  // expect equality
  EXPECT_EQ(BinaryToHex(Fixed_Xor(HexToBytes(Problem2_Hex1), HexToBytes(Problem2_Hex2))), Problem2_Solution);
}
TEST(CryptoProblems, Problem3){
  // expect equality
  EXPECT_EQ(SingleByteXor(HexToBytes(Problem3_Hex)), Problem3_Solution);
}

/**************************
    BinaryToHex
***************************/
TEST(BinaryToHexTests, switchTests)
{

  vector <string> hexValues16 = {"0123456789abcdef"};
  vector <string> hexValues24 = {"00123456789aAbBcCdDeEfF"};
  string result1 = "0000";
  string result2 = "1000";
  string result3 = "FFFF";
   EXPECT_EQ(BinaryToHex(hexValues16)[0], result1);
   EXPECT_EQ(BinaryToHex(hexValues16)[8], result2);
   EXPECT_EQ(BinaryToHex(hexValues16)[16], result3);
   EXPECT_NO_THROW(BinaryToHex(hexValues24));

   // RYAN test invalid input
   vector <string> badInput = {"ghijkplo"};
   EXPECT_EXIT(BinaryToHex(badInput)[0], testing::ExitedWithCode(0), "");

}

/**************
B64Decoder
**************/

TEST(B64DecoderTests, returnTest)
{
   //test string to see if triggers throw
   //using first 18 chars from given string in problem
    EXPECT_NO_THROW(B64Decoder("49276d206b696c6c69"));
    EXPECT_EQ(B64Decoder("49276d206b696c6c69"), "SSdtIGtpbGxp");
}
/*******************
    FixedXor Tests
********************/

TEST(FixedXorTests, returnTest)
{
  vector <string> one = {"123"};
  vector <string> test = {"123"};

    EXPECT_NO_THROW(Fixed_Xor(one, test));
}
TEST(FixedXorTests, tryCatch)
{
    vector <string> bytestring1 = {"1"};
  vector <string> bytestring2 = {"0"};
    EXPECT_EXIT(Fixed_Xor(bytestring1, bytestring2),  testing::ExitedWithCode(0), "");


// RYAN - Testing two unequal length byte strings
    vector <string> bytestring3 = {"1234"};
    vector <string> bytestring4 = {"123"};
    
    EXPECT_EXIT(Fixed_Xor(bytestring3, bytestring4), testing::ExitedWithCode(0),"");

}

/*****************
    Char To Bytes
*****************/
TEST(CharToByteTests, returnTest)
{
    EXPECT_EQ(CharToByte(3), "0000 0011");
    EXPECT_NE(CharToByte(3), "0000011");
}

/**************************
 ScoreEnglishTextTests
***************************/

TEST(scoreEnglishTextTests, returnTest)
{
    EXPECT_EQ(scoreEnglishText("A"), 6);
}

/***************************
 Detecting Single Xor
****************************/
TEST(DetectingSingleXorTests, returnTest)
{
  EXPECT_EQ(DetectingSingleXor(Problem4_FileName), Problem4_solution);

  // RYAN Test bad file name enter
  // I think this should return an empty string????? Not too sure
  EXPECT_EQ(DetectingSingleXor("ima/bad/filename.txt"), "");
  
}

/*************************
  Repeating Key Xor
**************************/
TEST(RepeatingKeyXorTests, returnTest)
{
  string notEqual = "100123ba46fcd";
  EXPECT_EQ(RepeatingKeyXor(Problem5_Stanza,Problem5_Key), Problem5_Answer);
  EXPECT_NE(RepeatingKeyXor(Problem5_Stanza, Problem5_Key), notEqual);
}

TEST(RepeatingKeyXorTests, inputValidation)
{
  string badKey = "FIRE";
  
  EXPECT_ANY_THROW(RepeatingKeyXor(Problem5_Stanza, badKey));
}


/******************
 Hamming Distance
******************/
TEST(HammingDistTests, returnTest)
{
  EXPECT_EQ(hammingDist("Bed", "cad"), 2);
}
TEST(HammingDistTests, InputValidation)
{
  string throwTest = "Bed";
  string throwTest2 = "3";
  //check that if a different data type is passed, there will be a throw
  EXPECT_ANY_THROW(hammingDist(throwTest, throwTest2));
}
/***************
 Break Xor
****************/
// TEST(BreakXorTests returnTest)
// {

//   //This needs to be added to the util file
//   EXPECT_EQ(BreakXor(problem_6_file), problem_6_result);

// }

TEST(HasRepeatingBlocksTests,  returnTest)
{
  string test = "8a10247f90d0a05538888ad6205882196f5f6d05c21ec8dca0cb0be02c3f8b09e382963f443aa514daa501257b09a36bf8c4c392d8ca1bf4395f0d5f2542148c7e5ff22237969874bf66cb85357ef99956accf13ba1af36ca7a91a50533c4d89b7353f908c5a166774293b0bf6247391df69c87dacc4125a99ec417221b58170e633381e3847c6b1c28dda2913c011e13fc4406f8fe73bbf78e803e1d995ce4d";

  EXPECT_NE(has_repeating_blocks(test, 4),has_repeating_blocks(test, 2));
  EXPECT_FALSE(has_repeating_blocks(test, 4));
  EXPECT_NO_THROW(has_repeating_blocks(test, 4));

}
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

 
