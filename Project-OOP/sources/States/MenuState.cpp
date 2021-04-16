#include "../headers/States/MenuState.hpp"

MenuState::~MenuState()
{

}

int
MenuState::getIndexOfNextFrameState()
{
	return m_currentState;
}

void
MenuState::eventHandler(sf::RenderWindow& renderWindow)
{
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			renderWindow.close();

		else if (event.type == event.KeyPressed)
		{
			m_currentState = State::Settings;
		}
	}
}

void
MenuState::update(sf::RenderWindow& renderWindow)
{
	m_currentState = State::Menu;
}

void
MenuState::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.clear();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	renderWindow.draw(shape);

	renderWindow.display();
}