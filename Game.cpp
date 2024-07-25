#include "Game.h"


Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window") {
	window.setFramerateLimit(1);
}

void Game::Start() {
	InitUI();
}

void Game::AddGameObject(GameObject* go)
{
	std::cout << "Added gamobject with id " << go->id << std::endl;
	_objects.push_back(go);
}

void Game::RemoveGameObject(GameObject* go)
{
	_objects.erase(std::remove(_objects.begin(), _objects.end(), go), _objects.end());
	//std::cout << _objects.size() << std::endl;
}

bool Game::InitUI()
{
	Player p(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
	AddGameObject(&p);

	Enemy e(sf::Vector2f(WINDOW_WIDTH/4, WINDOW_HEIGHT/4));
	AddGameObject(&e);

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear screen
		window.clear();

		for (int idxObj = 0; idxObj < _objects.size(); idxObj++) {
			_objects[idxObj]->Update();
			window.draw(_objects[idxObj]->GetSprite());
		}

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}