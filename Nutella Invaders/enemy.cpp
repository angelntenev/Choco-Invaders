//enemy.cpp
#include "enemy.h"
#include "game.h"
#include <iostream>

using namespace std;
using namespace sf;

Enemy::Enemy() : collisionSquare(Vector2f(48, 26)), Entity(IntRect(Vector2i(0, 0), Vector2i(64, 64)))
{
    if (!_texture.loadFromFile("..\\Nutella Invaders\\res\\img\\Enemy1_1.png"))
    {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    setOrigin(32.f, 32.f);
    setTexture(_texture);
    setTextureRect(_sprite);
    collisionSquare.setFillColor(sf::Color::White);
    collisionSquare.setOrigin(24.f, 14.f);
    collisionSquare.setPosition(this->getPosition());
    setScale(1.01, 1.f);

}


void Enemy::Update(float dt)
{
    collisionSquare.setPosition(this->getPosition());
    Pulse(dt);
}