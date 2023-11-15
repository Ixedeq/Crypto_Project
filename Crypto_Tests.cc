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
  EXPECT_EQ(Single_Byte_Xor(HexToBytes(Problem3_Hex)), Problem3_Solution);
}