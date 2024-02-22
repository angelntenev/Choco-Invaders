//bullet.h
#pragma once
#include "Entity.h"

class Bullet : public Entity
{
private:
	float _speed;
	sf::Texture _texture;
public:
	sf::RectangleShape collisionSquare;
	Bullet(sf::Vector2f spawnLocation, bool direction);
	void Update(float dt) override;
};

