//enemy.h
#pragma once

#include "Entity.h"

class Enemy : public Entity
{
private:
	float _speed;
	float _hp;
	sf::Texture _texture;
	sf::RectangleShape collisionSquare;
public:
	Enemy();
	//void Update(float dt) override;
};

