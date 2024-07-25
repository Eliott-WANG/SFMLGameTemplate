#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	std::vector<GameObject*> _objects;

	bool InitUI();
public:
	Game();
	sf::RenderWindow window;
	const static int WINDOW_WIDTH = 1600;
	const static int WINDOW_HEIGHT = 900;

	void Start();
	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);
};