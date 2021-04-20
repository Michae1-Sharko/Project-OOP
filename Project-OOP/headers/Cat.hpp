#pragma once

#include "Animation.hpp"

namespace AnimationCatType
{
	enum 
	{
		GoToUp,
		GoToDown,
		GoToLeft,
		GoToRight,

		AmountOfTypes
	};
};

class Cat
{
public:
	Cat(sf::String resource);
	
	void update(sf::View& view);
	void draw(sf::RenderWindow& renderWindow);

private:
	Animation m_animations[AnimationCatType::AmountOfTypes];
	int m_currentAnimation = AnimationCatType::GoToUp;

	sf::Vector2f m_position{ 192, 64 };
	sf::Vector2f m_positionToGo{ 192, 64 };
	
	void move(sf::View& view, int side);
};