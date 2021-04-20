#pragma once

#include "../IEngineState.hpp"
#include "../Cat.hpp"

class CameraState : public IEngineState
{
public:
	CameraState(sf::RenderWindow& renderWindow);

	virtual int getIndexOfNextFrameState() override;

	virtual void eventHandler(sf::RenderWindow& renderWindow) final;
	virtual void draw(sf::RenderWindow& renderWindow) final;
	virtual void update(sf::RenderWindow& renderWindow) final;

	virtual ~CameraState();

private:
	int m_currentState = State::Camera;
	bool m_isPaused = false;

	Cat m_cat{ "resources/cat.png" };

	sf::Texture m_textureRoom;
	sf::Sprite m_room;

	sf::View m_cameraView;
};