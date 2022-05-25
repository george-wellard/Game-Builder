#include "StateMachine.h"

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	// Starting adding process
	this->_isAdding = true;
	this->_isReplacing = isReplacing;

	// Moving state into new stae
	this->_newState = std::move(newState);
}

void StateMachine::RemoveSate()
{
	// Starting removing process
	this->_isRemoving = true;
}

void StateMachine::ProcessStateChange()
{
	// removing state if it is not empty
	if (this->_isRemoving && !this->_states.empty())
	{
		// Removing state on top of stack
		this->_states.pop();

		// Resuming app if state is not empty 
		if (!this->_states.empty())
		{
			this->_states.top()->Resume();
		}

		// 
		this->_isRemoving = false;
	}

	// Adding new sate
	if (this->_isAdding)
	{
		// Checking if top of stack isn't empty
		if (!this->_states.empty())
		{
			// Replacing it if it is
			if (this->_isReplacing)
			{
				this->_states.pop();
			}
			else
			{
				// Pausing state if it isn't for smooth transition 
				this->_states.top()->Pause();
			}
		}

		// Pushing new state to top of stack
		this->_states.push(std::move(this->_newState));
		this->_states.top()->Init();
		this->_isAdding = false;
	}
}

// Getting state on top of stack
StateRef& StateMachine::GetActiveState()
{
	return this->_states.top();
}