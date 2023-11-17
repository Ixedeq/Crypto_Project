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
    EXPECT_EQ(BinaryToHex("0123456789abcdef")[0], "0000");

   EXPECT_EQ(BinaryToHex("0123456789abcdef")[8], "1000");

   EXPECT_EQ(BinaryToHex("0123456789abcdef")[16], "FFFF");

   EXPECT_NO_THROW(BinaryToHex("00123456789aAbBcCdDeEfF"));

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
    EXPECT_NO_THROW(Fixed_Xor("123", "123"));
}

TEST(FixedXorTests, tryCatch)
{
    EXPECT_EXIT(Fixed_Xor("1", "0"),  testing::ExitedWithCode(0), "");
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
    EXPECT_EQ(scoreEnglishText("A"), 1);
}

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

