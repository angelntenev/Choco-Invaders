#include "Entity.h"
#include "game.h"

using namespace std;
using namespace sf;

Entity::Entity(IntRect ir) : sf::Sprite()
{
	_sprite = ir;
}

void Entity::Update(float dt) {


}

void Entity::Pulse(float dt) {
    Vector2f scale = this->getScale();

    if (scale.x > 1 && scale.y == 1) {
        if (scale.x > 1.1) {
            scale.y = 0.99;
            this->setScale(scale);
        }
        else {
            this->scale(1.00002, 1);
        }
    }
    else if (scale.x > 1) {
        if (scale.x > 1) {
            this->scale(1.0f / 1.00001f, 1);
            scale = this->getScale();
            if (scale.x < 1) {
                scale.y = 1;
                scale.x = 1.001;
                this->setScale(scale);
            }
        }
    }
}
