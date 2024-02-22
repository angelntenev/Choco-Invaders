//Entity.h
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public sf::Sprite
{
protected:
	sf::IntRect _sprite;
	bool toBeDestroyed = false;
public:
	explicit Entity(sf::IntRect ir);
	Entity() = delete;
	virtual ~Entity() = default;
	virtual void Update(float dt);

	bool isToBeDestroyed();
	void prepareForDestruction(bool destroy);
	void Pulse(float dt);
};