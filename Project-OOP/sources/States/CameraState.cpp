#include "../headers/States/CameraState.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

const int global_CAT_JOKES_AMOUNT = 41;
const char* global_cats_jokes[global_CAT_JOKES_AMOUNT] =
{
	"What do cats like to eat on a hot day? A mice-cream cone!",
	"Why do cats always get their way ? They are very purr - suasive!",
	"How do two cats end a fight ? They hiss and make up!",
	"What should you use to comb a cat ? A catacomb!",
	"What is a cat's favorite movie? The Sound of Mewsic!",
	"How do you know a cat is agitated ? He's having a hissy fit!",
	"What's a cat's favorite magazine ? Good Mousekeeping!",
	"Why did the cat wear a fancy dress ? She was feline fine!",
	"What's a cat's favorite color ? Purr - ple!",
	"Why was the cat afraid of the tree ? Because of its bark!",
	"What did the cat say when it was confused ? \"I'm purr-plexed!\"",
	"What's a cat's favorite dessert ? Chocolate mouse!",
	"Where does a cat go when it loses its tail ? The re - tail store!",
	"What do you call a cat who lives in an igloo ? An eskimew!",
	"How do cats stop crimes ? They call claw enforcement!",
	"Why was the cat so agitated ? Because he was in a bad mewd!",
	"What do you call a cat who loves to bowl ? An alley cat!",
	"What do cats love to do in the morning ? Read the mewspaper!",
	"How is cat food sold ? Usually, purr the can!",
	"What do baby cats always wear ? Diapurrs!",
	"Funny cat joke about a scratch pad",
	"Why are cats great singers ? Because they're very mewsical!",
	"Why can't cats play poker in the jungle? Too many cheetahs!",
	"What's another name for a cat's house ? A scratch pad!",
	"What should you say to your cat when you leave the house ? \"Have a mice day!\"",
	"What do cats use to make coffee ? A purr - colator!",
	"How does a cat decide what it wants from the store ? It flips through the cat - alog!",
	"In what kind of weather is a vet the busiest ? When it's raining cats and dogs!",
	"What do you call a cat wearing shoes ? A puss in boots!",
	"What type of cat works for the Red Cross ? A first aid cat!",
	"Why do cats always win video games ? Because they have nine lives!",
	"What state has a lot of cats and dogs ? Petsylvania!",
	"What's a cat's favorite game to play with a mouse ? Catch!",
	"What do you call a pile of kittens ? A meowntain!",
	"What do cats eat for breakfast ? Mice Krispies!",
	"Where do cats always fly out of when they travel ? Kitty Hawk!",
	"How does a cat sing scales ? Do - re - mew!",
	"Why did the cat eat the lemons ? He was a sourpuss!",
	"What's a cat's favorite subject in school ? Hisss - tory!",
	"What types of cats purr the best ? Purrr - sians!",
	"What sports do cats play ? Hairball!",
};

CameraState::CameraState(sf::RenderWindow& renderWindow)
{
	m_textureRoom.loadFromFile("resources/roomUp.png");
	m_room.setTexture(m_textureRoom);

	m_cameraView.setSize(160.f, 160.f);
	m_cameraView.setCenter(192.f + 16.f, 64.f + 16.f);
}

CameraState::~CameraState() { }

int
CameraState::getIndexOfNextFrameState()
{
	return m_currentState;
}

void
CameraState::eventHandler(sf::RenderWindow& renderWindow)
{
	m_currentState = State::Camera;

	sf::Clock deltaClock;
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			m_currentState = State::Menu;

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			m_isPaused = true;
	}

	ImGui::SFML::Update(renderWindow, deltaClock.restart());
}

void
CameraState::update(sf::RenderWindow& renderWindow)
{
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

	static int random_joke = 0;
	static bool wasOpened = false;

	if (m_isPaused && !wasOpened)
	{
		random_joke = rand() % global_CAT_JOKES_AMOUNT;
		ImGui::OpenPopup("[MS]: Pause", ImGuiPopupFlags_AnyPopup);

		wasOpened = true;
	}

	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
	if (ImGui::BeginPopupModal("[MS]: Pause", NULL, windowFlags))
	{
		ImGui::Text("%s\n\n", global_cats_jokes[random_joke]);
		ImGui::Separator();

		if (ImGui::Button("Continue##Button", ImVec2(-FLT_MIN, 30)))
		{
			ImGui::CloseCurrentPopup();

			m_isPaused = false;
			wasOpened = false;
		}
		ImGui::EndPopup();
	}

	if (m_isPaused == false)
	{
		m_cat.update(m_cameraView);
		renderWindow.setView(m_cameraView);
	}
}

void
CameraState::draw(sf::RenderWindow& renderWindow)
{
	renderWindow.clear();

	renderWindow.draw(m_room);
	m_cat.draw(renderWindow);

	ImGui::SFML::Render(renderWindow);
	renderWindow.display();
}