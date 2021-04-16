#include "../headers/Engine.hpp"
#include "../headers/IEngineState.hpp"

#include <array>

Engine::Engine(sf::VideoMode mode, sf::String title, sf::Uint32 style) :
	m_renderWindow{ mode, title, style }
{

}

void
Engine::start()
{
	std::array<IEngineState*, State::AmountOfStates> arrayOfStates =
	{ 
		new MenuState(), 
		new SettingsState() 
	};
	int indexOfNextFrameState = State::Menu;

	while (m_renderWindow.isOpen())
	{
		auto* currentFrameState = arrayOfStates.at(indexOfNextFrameState);

		currentFrameState->update(m_renderWindow);
		currentFrameState->eventHandler(m_renderWindow);
		currentFrameState->draw(m_renderWindow);

		indexOfNextFrameState = currentFrameState->getIndexOfNextFrameState();
	}

	for (auto* state : arrayOfStates)
		delete state;
}