#include "../headers/States/MenuState.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

MenuState::~MenuState(){}

int
MenuState::getIndexOfNextFrameState()
{
	return m_currentState;
}

void
MenuState::eventHandler(sf::RenderWindow& renderWindow)
{
	sf::Clock deltaClock;
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::Closed)
			renderWindow.close();
	}
	ImGui::SFML::Update(renderWindow, deltaClock.restart());
}

void
MenuState::update(sf::RenderWindow& renderWindow)
{
	m_currentState = State::Menu;

	ImGuiWindowFlags windowFlags =
	{
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoNav |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoBringToFrontOnFocus |
		ImGuiWindowFlags_AlwaysAutoResize
	};

	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
	ImGui::Begin("[MS]: My Cat's Life", NULL, windowFlags);

	if (ImGui::Button("play the game...", ImVec2(180, 40)))
		m_currentState = State::Camera;
	
	ImGui::End();
}

void
MenuState::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.clear();
	ImGui::SFML::Render(renderWindow);
	renderWindow.display();
}