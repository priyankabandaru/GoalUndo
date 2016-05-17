/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include<string>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(GoalUndoTest, addgoalndoperation)
{
	GoalUndo test;
	test.addOperation("Copy","Selec");
}
TEST(GoalUndoTest, addoperation)
{
	GoalUndo test;
	test.addOperation("Cp");
}
TEST(GoalUndoTest, addgoalndoperation2)
{
	GoalUndo test;
	test.addOperation("Delete","Select");
}
TEST(GoalUndoTest, addoperation2)
{
	GoalUndo test;
	test.addOperation("del");
}
TEST(GoalUndoTest, getoperation)
{
	GoalUndo test;
  int check;
	std::string goals=test.getOperations();
  std::string expected= "Select del";
  if(goals==expected)
  {
    check=0;
  }
  //int check=expected.compare(goals);
  ASSERT_EQ(check,0);
}
TEST(GoalUndoTest, getgoal)
{
	GoalUndo test;
	std::string goals=test.getGoal();
  std::string expected="Delete";
  int check=expected.compare(goals);
  ASSERT_EQ(check,0);
}
TEST(GoalUndoTest, undoOperation)
{
  GoalUndo test;
  test.undoOperation("Select");
}
TEST(GoalUndoTest, undoOperation1)
{
  GoalUndo test;
  test.undoOperation();
}
TEST(GoalUndoTest, undoGoal)
{
  GoalUndo test;
  test.undoGoal();
}
