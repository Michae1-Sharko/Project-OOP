#pragma once

#include "../IEngineState.hpp"

class CameraState : public IEngineState
{
public:
	CameraState();

	virtual int getIndexOfNextFrameState() override;

	virtual void eventHandler(sf::RenderWindow& renderWindow) final;
	virtual void draw(sf::RenderWindow& renderWindow) final;
	virtual void update(sf::RenderWindow& renderWindow) final;

	virtual ~CameraState();

private:
	int m_currentState = State::Menu;
	bool m_isPaused = false;
};