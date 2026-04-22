#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "Simulation");
    window.setVerticalSyncEnabled(true);

    Game game(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
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