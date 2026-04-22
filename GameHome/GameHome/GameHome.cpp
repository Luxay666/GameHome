#include <SFML/Graphics.hpp>
#include "Game.h"

#define windowWidth 1000
#define windowHeight 1000

int main()
{
    sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), "Simulation");
    window.setVerticalSyncEnabled(true);

    Game game(window, windowWidth, windowHeight);

    while (window.isOpen())
    {
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
             game.handleEvent(event);
        }

        game.update();

        window.clear();
        game.draw();
        window.display();
    }
}