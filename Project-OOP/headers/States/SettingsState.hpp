#pragma once

#include "../IEngineState.hpp"

class SettingsState : public IEngineState
{
public:
	virtual int getIndexOfNextFrameState() final;

	virtual void eventHandler(sf::RenderWindow& renderWindow) final;
	virtual void draw(sf::RenderWindow& renderWindow) final;
	virtual void update(sf::RenderWindow& renderWindow) final;

	virtual ~SettingsState();

private:
	int m_currentState = State::Settings;
};