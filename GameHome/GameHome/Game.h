#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Menu.h"

enum class GameState { Menu, Playing };

class Game
{
public:
    Game(sf::RenderWindow& _window, int _windowWidth, int _windowHeight);
    ~Game() = default;
    void handleEvent(const std::optional<sf::Event>& event);
    void update();
    void draw();

private:
    sf::RenderWindow& window;
    int windowWidth;
    int windowHeight;
    Menu menu;
    GameState state = GameState::Menu;
    int clickCount = 0;
    sf::RectangleShape clickBar;
};