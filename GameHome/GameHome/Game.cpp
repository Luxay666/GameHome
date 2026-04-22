#include "Game.h"

Game::Game(sf::RenderWindow& window, int _windowWidth, int _windowHeight)
    : window(window)
    , windowWidth(_windowWidth)
    , windowHeight(_windowHeight)
{

}

void Game::handleEvent(const std::optional<sf::Event>& event)
{
    if (state == GameState::Menu)
        menu.handleEvent(event, window);
}

void Game::update()
{
    if (state == GameState::Menu && menu.isPlayClicked())
        state = GameState::Playing;
}

void Game::draw()
{
    std::cout << "state: " << (int)state << std::endl;
    if (state == GameState::Menu)
        menu.draw(window);
}