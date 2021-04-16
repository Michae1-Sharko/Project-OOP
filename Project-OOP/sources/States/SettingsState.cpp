#include "../headers/States/SettingsState.hpp"

SettingsState::~SettingsState()
{

}

int
SettingsState::getIndexOfCurrentState()
{
	return m_currentState;
}

void
SettingsState::eventHandler(sf::RenderWindow& renderWindow)
{
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			renderWindow.close();

		else if (event.type == event.KeyPressed)
		{
			m_currentState = State::Menu;
		}
	}
}

void
SettingsState::update(sf::RenderWindow& renderWindow)
{
	m_currentState = State::Settings;
}

void
SettingsState::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.clear();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	renderWindow.draw(shape);

	renderWindow.display();
}