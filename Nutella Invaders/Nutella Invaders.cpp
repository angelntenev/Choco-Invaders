#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "Entity.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

using namespace sf;
using namespace std;

unique_ptr<Player> player = make_unique<Player>();
vector<unique_ptr<Enemy>> enemies;
vector<unique_ptr<Bullet>> bullets;

float timeSinceLastBullet = 0.0f;
const float bulletCooldown = 0.3f;

//gameWidth = 800, gameHeight = 600;


void Load()
{
    int numEnemiesPerRow = 10; 
    float spacingX = gameWidth / (numEnemiesPerRow + 1); // Spacing along the x-axis
    float spacingY = gameHeight / 10; // Spacing along the y-axis
    float offsetY = gameHeight / 8; // Starting Y offset for the first row

    for (int i = 0; i < 20; i++)
    {
        enemies.push_back(make_unique<Enemy>());

        int row = i / numEnemiesPerRow;
        int posInRow = i % numEnemiesPerRow;

        float posX = (posInRow + 1) * spacingX; 
        float posY = offsetY + row * spacingY;

        enemies.back()->setPosition(posX, posY);
    }

}

void Update(RenderWindow& window)
{
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == Event::Closed) 
        {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) 
    {
        window.close();
    }
    timeSinceLastBullet += dt;
    if (Keyboard::isKeyPressed(Keyboard::Space) && timeSinceLastBullet >= bulletCooldown)
    {
        bullets.push_back(make_unique<Bullet>(player->getPosition(), true));
        timeSinceLastBullet = 0.0f;
    }

    player->Update(dt);

    for (const auto& bullet : bullets)
    {
        bullet->Update(dt);
        sf::FloatRect bulletBounds = bullet->collisionSquare.getGlobalBounds();
        for (const auto& enemy : enemies)
        {
            sf::FloatRect enemyBounds = enemy->collisionSquare.getGlobalBounds();
            if (bulletBounds.intersects(enemyBounds))
            {
                enemy->prepareForDestruction(true);
                bullet->prepareForDestruction(true);
                break;
            }
            if (bullet->getPosition().y < 0)
            {
                bullet->prepareForDestruction(true);
            }
        }
    }



    // Remove destroyed bullets
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const std::unique_ptr<Bullet>& bullet) {
            return bullet->isToBeDestroyed();
        }), bullets.end());

    // Remove destroyed enemies
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const std::unique_ptr<Enemy>& enemy) {
            return enemy->isToBeDestroyed();
        }), enemies.end());



    for (const auto& enemy : enemies)
    {
        enemy->Update(dt);
    }



    //Pulse(player, dt);
}

void Render(RenderWindow& window) 
{
    // Draw Everything
    window.draw(*player);
    for (const auto& enemy : enemies) 
    {
        //window.draw(enemy->collisionSquare);
        window.draw(*enemy);
    }
    for (const auto& bullet : bullets)
    {
        window.draw(*bullet);
        //window.draw(bullet->collisionSquare);
    }
}

int main()
{
    RenderWindow window(VideoMode(gameWidth, gameHeight), "Nutella Invaders");
    Load();
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}

