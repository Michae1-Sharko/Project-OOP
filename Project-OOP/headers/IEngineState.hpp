#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

struct IEngineState
{
	virtual int getIndexOfNextFrameState() = 0;

	virtual void eventHandler(sf::RenderWindow& renderWindow) = 0;
	virtual void draw(sf::RenderWindow& renderWindow) = 0;
	virtual void update(sf::RenderWindow& renderWindow) = 0;

	virtual ~IEngineState(){ }
};

namespace State
{
	enum
	{
		Menu,
		Camera,

		AmountOfStates
	};
};

#include "States/MenuState.hpp"
#include "States/CameraState.hpp"