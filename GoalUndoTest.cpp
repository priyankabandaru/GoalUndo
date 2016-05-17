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
TEST(GoalUndoTest, addgoal_ndoperation)
{
	GoalUndo test;
	test.addOperation("Copy","Selec");
}
TEST(GoalUndoTest, addoperation)
{
	GoalUndo test;
  test.addOperation("Copy","Selec");
	test.addOperation("Cp");
}
TEST(GoalUndoTest, addgoalndoperation2)
{
	GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
	test.addOperation("Delete","Select");
}
TEST(GoalUndoTest, addoperation2)
{
	GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
	test.addOperation("Delete","Select");
	test.addOperation("del");
}
TEST(GoalUndoTest, getoperation)
{
	GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.addOperation("Delete","Select");
  test.addOperation("del");
  ASSERT_EQ("Select del",test.getOperations());
}
TEST(GoalUndoTest, getgoal)
{
	GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.addOperation("Delete","Select");
  test.addOperation("del");
  ASSERT_EQ("Delete",test.getGoal());
}
TEST(GoalUndoTest, undoOperation)
{
  GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.addOperation("Delete","Select");
  test.addOperation("del");
  test.undoOperation("Selec");
  test.undoGoal();
  ASSERT_EQ("Cp",test.getOperations());

}
TEST(GoalUndoTest, undoOperation1)
{
  GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.addOperation("Delete","Select");
  test.addOperation("del");
  test.undoOperation();
  ASSERT_EQ("Select",test.getOperations());
}

TEST(GoalUndoTest, undoGoal)
{
  GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.addOperation("Delete","Select");
  test.addOperation("del");
  test.undoGoal();
  ASSERT_EQ("Copy",test.getGoal());
}
TEST(GoalUndoTest,undoGoalEmpty)
{
  GoalUndo test;
  ASSERT_EQ("",test.getGoal());
}
TEST(GoalUndoTest,goalwithlastoperationdel)
{
  GoalUndo test;
  test.addOperation("Copy","Selec");
  test.addOperation("Cp");
  test.undoOperation();
  test.undoOperation();
  ASSERT_EQ("",test.getGoal());
}
