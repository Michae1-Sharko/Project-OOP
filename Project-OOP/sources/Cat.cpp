#include "../headers/Cat.hpp"

Cat::Cat(sf::String resource)
{
	m_animations[AnimationCatType::GoToUp].loadFromFile(resource, sf::IntRect(0, 0, 32, 32));
	m_animations[AnimationCatType::GoToUp].addFrame(sf::IntRect(32, 0, 32, 32));
	m_animations[AnimationCatType::GoToUp].addFrame(sf::IntRect(64, 0, 32, 32));
	m_animations[AnimationCatType::GoToUp].addFrame(sf::IntRect(32, 0, 32, 32));

	m_animations[AnimationCatType::GoToDown].loadFromFile(resource, sf::IntRect(0, 96, 32, 32));
	m_animations[AnimationCatType::GoToDown].addFrame(sf::IntRect(32, 96, 32, 32));
	m_animations[AnimationCatType::GoToDown].addFrame(sf::IntRect(64, 96, 32, 32));
	m_animations[AnimationCatType::GoToDown].addFrame(sf::IntRect(32, 96, 32, 32));

	m_animations[AnimationCatType::GoToLeft].loadFromFile(resource, sf::IntRect(0, 64, 32, 32));
	m_animations[AnimationCatType::GoToLeft].addFrame(sf::IntRect(32, 64, 32, 32));
	m_animations[AnimationCatType::GoToLeft].addFrame(sf::IntRect(64, 64, 32, 32));
	m_animations[AnimationCatType::GoToLeft].addFrame(sf::IntRect(32, 64, 32, 32));

	m_animations[AnimationCatType::GoToRight].loadFromFile(resource, sf::IntRect(0, 32, 32, 32));
	m_animations[AnimationCatType::GoToRight].addFrame(sf::IntRect(32, 32, 32, 32));
	m_animations[AnimationCatType::GoToRight].addFrame(sf::IntRect(64, 32, 32, 32));
	m_animations[AnimationCatType::GoToRight].addFrame(sf::IntRect(32, 32, 32, 32));
}

void
Cat::update(sf::View& view)
{
	if (m_position.x > m_positionToGo.x)
		move(view, AnimationCatType::GoToRight);
	else if (m_position.x < m_positionToGo.x)
		move(view, AnimationCatType::GoToLeft);

	else if (m_position.y <m_positionToGo.y)
		move(view, AnimationCatType::GoToUp);
	else if (m_position.y > m_positionToGo.y)
		move(view, AnimationCatType::GoToDown);

	else
	{
		int x = rand() % (9 - 1);
		int y = rand() % (6 - 1);

		if (x >= m_positionToGo.x - 2) x++;
		if (y >= m_positionToGo.y - 2) y++;

		m_positionToGo = { float(2 + x) * 32, float(2 + y) * 32 };
	}
}

void 
Cat::draw(sf::RenderWindow& renderWindow)
{
	m_animations[m_currentAnimation].setPosition(m_position);
	m_animations[m_currentAnimation].draw(renderWindow);
}

void 
Cat::move(sf::View& view, int side)
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() < 100)
		return;

	m_position.x += (side == AnimationCatType::GoToLeft) * (4) + (side == AnimationCatType::GoToRight) * (-4);
	m_position.y += (side == AnimationCatType::GoToUp) * (4) + (side == AnimationCatType::GoToDown) * (-4);

	view.move(
		float(side == AnimationCatType::GoToLeft) * (4) + float(side == AnimationCatType::GoToRight) * (-4),
		float(side == AnimationCatType::GoToUp) * (4) + float(side == AnimationCatType::GoToDown) * (-4)
	);

	m_currentAnimation = side;
	clock.restart();
}