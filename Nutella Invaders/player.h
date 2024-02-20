//player.h
#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	float _speed;
	float _hp;
	sf::Texture _texture;
	sf::RectangleShape collisionSquare;
public:
	Player();
	void Update(float dt) override;
};

