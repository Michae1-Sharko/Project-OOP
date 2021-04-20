#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class Animation
{
public:
	void frash();
	void loadFromFile(sf::String resourceName, sf::IntRect textureRect);
	void addFrame(sf::IntRect textureRect);

	void setPosition(sf::Vector2f newPosition);
	
	void draw(sf::RenderWindow& renderWindow);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_currentFrame = 0;
	std::vector<sf::IntRect> m_frames;

	void update();
};