#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Utils.h"

// The GameObject is an abstract class that represents an object on your scene that needs to run code every frame. You can instantiate a texture to it in your child class constructor and attach it to the sprite for it it to be rendered.
class GameObject
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
public:
	// An optionnal identifier that allows comparison
	std::string id;
	// Default constructor
	GameObject(sf::Vector2f position) { 
		id = Utils::generateUniqueID();
		_sprite.setPosition(position);
	}

	// Runs this method every frame
	virtual void Update() = 0;

	// Allows the Game to render your object
	sf::Sprite GetSprite() { return _sprite; };

	// Not necessary to understand the template, but it allows comparison between instances of GameObject
	bool operator==(const GameObject& rhs) const {
		return id == rhs.id;
	}

	void InitTexture(std::string path) {
		if (!_texture.loadFromFile(path)) throw std::invalid_argument("Texture not found at " + path + "!");
		_sprite.setTexture(_texture);
		_sprite.setOrigin(sf::Vector2f(_texture.getSize().x * 0.5, _texture.getSize().y * 0.5));
	}
};

