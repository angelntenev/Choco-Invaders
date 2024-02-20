#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "Entity.h"
#include "player.h"

using namespace sf;
using namespace std;

Player* player = new Player();



void Load()
{

    
}

void Update(RenderWindow& window)
{
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    player->Update(dt);

    //Pulse(player, dt);
}

void Render(RenderWindow& window) {
    // Draw Everything
    window.draw(*player);
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

