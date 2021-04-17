#include "../headers/Engine.hpp"
#include "../headers/IEngineState.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

#include <array>

Engine::Engine(sf::VideoMode mode, sf::String title, sf::Uint32 style) :
	m_renderWindow{ mode, title, style }
{
	sf::Vector2i center =
	{
		int(sf::VideoMode::getDesktopMode().width - m_renderWindow.getSize().x) / 2,
		int(sf::VideoMode::getDesktopMode().height - m_renderWindow.getSize().y) / 2
	};
	m_renderWindow.setPosition(center);
}

void
Engine::start()
{
	ImGui::SFML::Init(m_renderWindow);
	std::array<IEngineState*, State::AmountOfStates> arrayOfStates =
	{ 
		new MenuState(), 
		new CameraState() 
	};
	int indexOfNextFrameState = State::Menu;

	while (m_renderWindow.isOpen())
	{
		auto* currentFrameState = arrayOfStates.at(indexOfNextFrameState);

		currentFrameState->eventHandler(m_renderWindow);
		currentFrameState->update(m_renderWindow);
		currentFrameState->draw(m_renderWindow);

		indexOfNextFrameState = currentFrameState->getIndexOfNextFrameState();
	}

	for (auto* state : arrayOfStates)
		delete state;

	ImGui::SFML::Shutdown();
}