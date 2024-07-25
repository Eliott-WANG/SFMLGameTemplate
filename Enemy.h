#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(sf::Vector2f position) : GameObject(position) {
		InitTexture("res/enemy.png");
	};
	void Update();
};