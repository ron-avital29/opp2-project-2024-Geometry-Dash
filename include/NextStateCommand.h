#pragma once
#include "ButtonCommand.h"
#include "Singleton.h"

class Controller;
class GameState;

class NextStateCommand : public ButtonCommand
{
public:
	NextStateCommand(Controller& controller, GameStates nextState);	
	virtual ~NextStateCommand() = default;
	virtual void execute();

private:
	Controller& m_controller;
	//GameState& m_nextState;
	GameStates m_nextState;
};