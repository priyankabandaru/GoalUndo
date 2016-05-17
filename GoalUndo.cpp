#include "GoalUndo.h"
#include <string>

/* undoGoal
   When there are existing goals, it removes the most recently added
   one, along with any associated operations
*/
void GoalUndo::undoGoal()
{
	if( !goals.empty() )
	{
		goals.pop();
	}
}

/* undoOperation
   When there is an existing goal with more than one operation, remove the most
   recently added operation. When there is only one operation in the most
   recently added goal, it removes both the operation and the goal (i.e. goals
   cannot exist without any operations in it).
*/
void GoalUndo::undoOperation()
{
	if( !goals.empty() )
	{
		goals.top().operations.pop_back();

		if( goals.top().operations.empty() )
		{
			undoGoal();
		}
	}
}

/* undoOperation(undoOp)
   Overloaded undoOperation that searches the most recent goal (LIFO order)
   for an operation that matches the argument and removes (only) the first
   match found. If there are no matches, nothing is removed.
*/
void GoalUndo::undoOperation(std::string undoOp)
{
	if( !goals.empty() )
	{
		std::vector<std::string>::iterator iter;

		for(iter=goals.top().operations.end()-1; 
			iter > goals.top().operations.begin();
			--iter )
		{
			if( iter->compare(undoOp) == 0 ) //match!
			{
				goals.top().operations.erase(iter);
				break; //only remove first LIFO match
			}
		}
	}
}

/* getGoal
   Returns the name of the most recently added goal, or an empty string
   if there are no goals.
*/
std::string GoalUndo::getGoal()
{
	if( goals.empty() )
		return "";
	else
		return goals.top().name;
}

/* getOperations
   Returns the names of all of the operations in the most recently added goal,
   with a space between each operation.
*/
std::string GoalUndo::getOperations()
{
	if( goals.empty() )
		return "";
	else
	{
		std::string allOps = "";
		std::vector <std::string> listOps = goals.top().operations;

		std::vector<std::string>::iterator iter;
		for( iter=goals.top().operations.begin();
			 iter < goals.top().operations.end();
			 iter++ )
		{
			allOps += *iter;
			//add space between each operation (but not last)
			if( iter < goals.top().operations.cend()-1 )
				allOps += " ";
		}
		return allOps;
	}
}

/* addOperation(newGoal,newOp)
   Adds a new operation (newOp) within a new goal (newGoal). Both have to be
   non-empty strings. If either argument is an empty string, nothing is added.
*/
void GoalUndo::addOperation(std::string newGoal, std::string newOp)
{
	if(!newGoal.empty() && !newOp.empty())
	{
		Goal latest;
		latest.name = newGoal;
		goals.push(latest);
		addOperation( newOp );
	}
}

/* addOperation(newOp)
   Adds a new operation (newOp) within the most recently added goal. If the
   argument is an empty string, nothing is added. If no goals exist, it
   creates a new goal with the same name as the new operation
*/
void GoalUndo::addOperation(std::string newOp)
{
	if(!newOp.empty())
	{
		if( goals.empty() )
		{
			addOperation( newOp, newOp );
		}
		else
		{
			goals.top().operations.push_back(newOp);
		}
	}
}
