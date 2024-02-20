//Entity.h
#pragma once

#include <SFML/Graphics.hpp>


class Entity : public sf::Sprite
{
protected:
	sf::IntRect _sprite;
public:
	explicit Entity(sf::IntRect ir);
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(float dt);


	void Pulse(float dt);
};