#pragma once

class State
{
public:

	// initilize state
	virtual void Init() = 0; 

	// input for states
	virtual void HandleInput() = 0;

	// Updating states
	virtual void Update(float dt) = 0;

	// Drawing state assets
	virtual void Draw(float dt) = 0;

	// Pausing states
	virtual void Pause() { }

	// Resuming states
	virtual void Resume() { }

private:

};