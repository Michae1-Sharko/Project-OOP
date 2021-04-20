#include "../headers/Animation.hpp"

void
Animation::frash()
{
	m_currentFrame = 0;
}

void
Animation::loadFromFile(sf::String resource, sf::IntRect textureRect)
{
	m_texture.loadFromFile(resource);
	m_sprite.setTexture(m_texture);

	m_frames.push_back(textureRect);
	m_sprite.setTextureRect(m_frames.at(m_currentFrame));
}

void
Animation::addFrame(sf::IntRect textureRect)
{
	m_frames.push_back(textureRect);
}

void 
Animation::draw(sf::RenderWindow& renderWindow)
{
	update();
	renderWindow.draw(m_sprite);
}

void
Animation::setPosition(sf::Vector2f newPosition)
{
	m_sprite.setPosition(newPosition);
}

void 
Animation::update()
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() < 100)
		return;
	
	m_currentFrame = (++m_currentFrame) % m_frames.size();
	m_sprite.setTextureRect(m_frames.at(m_currentFrame));
	clock.restart();
}