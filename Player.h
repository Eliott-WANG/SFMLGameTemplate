#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(sf::Vector2f position) : GameObject(position) {
		InitTexture("res/player.png");
	}
	void Update();
};

