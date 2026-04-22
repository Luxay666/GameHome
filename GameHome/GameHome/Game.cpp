#include "Game.h"

Game::Game(sf::RenderWindow& window)
    : window(window)
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
    if (state == GameState::Menu)
        menu.draw(window);
}