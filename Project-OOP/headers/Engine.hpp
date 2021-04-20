#pragma once

#include <SFML/Graphics.hpp>

class Engine
{
public:
	Engine(
		sf::VideoMode mode = sf::VideoMode { 640, 640 },
		sf::String title = "[MS]: My Cat's Life",
		sf::Uint32 style = sf::Style::Default
	);
	void start();

private:
	sf::RenderWindow m_renderWindow;
};