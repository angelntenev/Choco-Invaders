//enemy.cpp
#include "enemy.h"
#include "game.h"
#include <iostream>

using namespace std;
using namespace sf;

Enemy::Enemy() : collisionSquare(Vector2f(32, 32)), Entity(IntRect(Vector2i(0, 0), Vector2i(64, 64)))
{
    if (!_texture.loadFromFile("..\\Nutella Invaders\\res\\img\\Enemy1_1.png"))
    {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    setOrigin(32.f, 32.f);
    setTexture(_texture);
    setTextureRect(_sprite);
}