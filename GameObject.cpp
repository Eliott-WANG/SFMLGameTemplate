#include "GameObject.h"
#include <iostream>

string GameObject::id;

void GameObject::Update()
{
	std::cout << "You must override this method !" << std::endl;
}
void GameObject::GameObject() {
	id = Utils::generateUniqueID();
	_sprite.setPosition(position);
}
