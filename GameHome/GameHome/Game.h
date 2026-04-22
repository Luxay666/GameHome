#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

enum class GameState { Menu, Playing };

class Game
{
public:
    Game(sf::RenderWindow& window);
    void handleEvent(const std::optional<sf::Event>& event);
    void update();
    void draw();

private:
    sf::RenderWindow& window;
    GameState state = GameState::Menu;
    Menu menu;
};