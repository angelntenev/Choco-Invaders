//player.cpp
#include "player.h"
#include "game.h"
#include <iostream>
#include <filesystem>

using namespace std;
using namespace sf;

namespace fs = std::filesystem;

const Keyboard::Key controls[4] =
{
    Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D
};


Player::Player() : _hp(3), _speed(250), collisionSquare(Vector2f(32,32)), Entity(IntRect(Vector2i(0, 0), Vector2i(64, 64)))
{
    setOrigin(Vector2f(32.f, 32.f));
    if (!_texture.loadFromFile("..\\Nutella Invaders\\res\\img\\Player.png"))
    {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    setTexture(_texture);
    setTextureRect(_sprite);
    setPosition(gameWidth / 2, gameHeight / 2);
    setScale(1.01, 1.f);

}

void Player::Update(float dt)
{
    Entity::Update(dt);

    float direction_x = 0.0f, direction_y = 0.0f;
    if (Keyboard::isKeyPressed(controls[0]))
    {
        if (!(getPosition().y < gameHeight * 0.5))
        {
            direction_y--;
        }
    }
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (!(getPosition().y > gameHeight - 32))
        {
            direction_y++;
        }
    }
    if (Keyboard::isKeyPressed(controls[2]))
    {
        if (!(getPosition().x < 0))
        {
            direction_x--;
        }
    }
    if (Keyboard::isKeyPressed(controls[3]))
    {
        if (!(getPosition().x > gameWidth))
        {
            direction_x++;
        }
    }


    move(Vector2f(direction_x * _speed * dt, direction_y * _speed * dt));
    Veer(direction_x);
    Pulse(dt);
}

void Player::Veer(float power)
{
    float rotation = this->getRotation();
    bool shifted = false;

    if (power > 0)
    {
        if ((180.f - rotation) >= 165)
        {
            rotate(power * 0.005);
            shifted = true;    
        }
    }

    if (power < 0)
    {
        if ((180.f - rotation) <= -165)
        {
            rotate(power * 0.005);
            shifted = true;
        }
    }
    
    if (!shifted)
    {
        if (rotation < 30)
        {
            rotate(-0.01);
        }
        if (rotation > 330)
        {
            rotate(0.005);

        }
    }
}