#include "Enemy.h"

void Enemy::Update()
{
	std::cout << "Everybody wants to me my enemy" << std::endl;
	_sprite.rotate(-10.f);

}
