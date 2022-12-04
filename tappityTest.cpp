/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
    ASSERT_TRUE(true);
}

TEST(tappityTest, length0)
{
    tappity mytaps("");
    std::string input = "";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
	ASSERT_EQ(dif, 0);
}

TEST(tappityTest, same_length)
{
    tappity mytaps("Hello world");
    std::string input = "Hello world";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
	ASSERT_EQ(dif, 0);
}

TEST(tappityTest, input_longer)
{
    tappity mytaps("Hello world");
    std::string input = "Hello world dwellers";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
	ASSERT_EQ(dif, 9);
}

TEST(tappityTest, phrase_longer)
{
    tappity mytaps("Hello world");
    std::string input = "Hello";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
	ASSERT_EQ(dif, 6);
}

TEST(tappityTest, correct_length0_accu)
{
    tappity mytaps("");
    std::string input = "";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 100);
}

TEST(tappityTest, phrase0_accu)
{
    tappity mytaps("");
    std::string input = "Hello world";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 0);
}

TEST(tappityTest, input0_accu)
{
    tappity mytaps("Hello world");
    std::string input = "";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 0);
}

TEST(tappityTest, correct_accu)
{
    tappity mytaps("Hello world");
    std::string input = "Hello world";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 100);
}

TEST(tappityTest, correct_inp_short_accu)
{
    tappity mytaps("Hello world");
    std::string input = "Hello ";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, ((dif/11)*100));
}

TEST(tappityTest, correct_inp_long_accu)
{
    tappity mytaps("Hello world");
    std::string input = "Hello world wow";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, ((dif/15)*100));
}

TEST(tappityTest, right0p_samelength_accu)
{
    tappity mytaps("Hello world");
    std::string input = "gtaap qrydl";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 0);
}

TEST(tappityTest, right0p_inplonger_accu)
{
    tappity mytaps("Hello world");
    std::string input = "gtaap qrydl wow";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 0);
}

TEST(tappityTest, right0p_reflonger_accu)
{
    tappity mytaps("Hello world");
    std::string input = "gtaap";
	mytaps.entry(input);
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, 0);
}

TEST(tappityTest, right50p_samelength_accu)
{
    tappity mytaps("Hello world");
    std::string input = "Hello qrydl";
	mytaps.entry(input);
    int dif = mytaps.length_difference();
    double accu = mytaps.accuracy();
	ASSERT_EQ(accu, ((dif/11)*100));
}

