#include "Player.h"

void Player::Update()
{
	std::cout << "Je suis un player" << std::endl;
	_sprite.rotate(10.f);
}
