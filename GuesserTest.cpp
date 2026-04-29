/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, distance_gl_gt_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secrett"), 1);
}
TEST(GuesserTest, distance_gl_lt_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secre"), 1);
}
TEST(GuesserTest, distance_lb) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("secret"), 1);
}
TEST(GuesserTest, distance_ub) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SecreT"), 1);
}
TEST(GuesserTest, distance_middle) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("SeCret"), 1);
}
TEST(GuesserTest, distance_lb_and_gl_lt_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("secre"), 2);
}
TEST(GuesserTest, distance_ld_eq_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("sECRET"), 6);
}
TEST(GuesserTest, distance_ld_one_gt_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("sECRETT"), 6);
}
TEST(GuesserTest, distance_ld_one_lt_sl) {
  Guesser object("Secret");
  ASSERT_EQ(object.distance("sECREt"), 5);
}
