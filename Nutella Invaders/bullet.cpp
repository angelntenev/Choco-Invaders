//bullet.cpp
#include "bullet.h"


using namespace std;
using namespace sf;

Bullet::Bullet(Vector2f spawnLocation, bool direction) : _speed(500), collisionSquare(Vector2f(4, 16)), Entity(IntRect(Vector2i(0, 0), Vector2i(32, 32)))
{
    setOrigin(16, 16);
    if (!_texture.loadFromFile("..\\Nutella Invaders\\res\\img\\Weapon1.png"))
    {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    setTexture(_texture);
    setTextureRect(_sprite);
    setPosition(spawnLocation);
    collisionSquare.setFillColor(sf::Color::White);
    collisionSquare.setOrigin(2, 8);
    if (!direction)
    {
        _speed = _speed * (-1);
    }
}

void Bullet::Update(float dt)
{
    Entity::Update(dt);
    collisionSquare.setPosition(this->getPosition().x, this->getPosition().y - 5);
    move(Vector2f(0, -_speed * dt));

}
