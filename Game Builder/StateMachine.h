#pragma once
#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
	public:

		// constructor
		StateMachine()
		{

		}
		// deconstructor
		~StateMachine()
		{

		}

		// Adding state
		void AddState(StateRef newState, bool isReplacing = true);

		// Removing state
		void RemoveSate();

		// Process for state chaning 
		void ProcessStateChange();

		// Get state on top of stack
		StateRef& GetActiveState();

	private:

		// stack of states
		std::stack<StateRef> _states;
		// state
		StateRef _newState;

		// boolean for state processes
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
};

