#pragma once

#include "../IEngineState.hpp"

class MenuState : public IEngineState
{
public:
	virtual int getIndexOfNextFrameState() final;

	virtual void eventHandler(sf::RenderWindow& renderWindow) final;
	virtual void draw(sf::RenderWindow& renderWindow) final;
	virtual void update(sf::RenderWindow& renderWindow) final;

	virtual ~MenuState();

private:
	int m_currentState = State::Menu;
};