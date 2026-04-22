#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, int _windowWidth, int _windowHeight)
    : window(window)
    , windowWidth(_windowWidth)
    , windowHeight(_windowHeight)
{
    clickBar.setFillColor(sf::Color::Green);
    clickBar.setPosition({ 10.f, 10.f });
    clickBar.setSize({ 0.f, 20.f });
}

void Game::handleEvent(const std::optional<sf::Event>& event)
{
    if (state == GameState::Menu)
    {
        menu.handleEvent(event, window);
    }
    else if (state == GameState::Playing)
    {
        if (!event) return;
        if (const auto* e = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (e->button == sf::Mouse::Button::Left)
            {
                clickCount++;
                float width = std::min(clickCount * 10.f, 500.f);
                clickBar.setSize({ width, 20.f });
                std::cout << "Clics: " << clickCount << std::endl;
            }
            if (clickCount >= 50)
            {
                std::cout << "You win!" << std::endl;
                state = GameState::Menu;
                clickCount = 0;
                clickBar.setSize({ 0.f, 20.f });
			}
        }
    }
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
    else
    {
        // Fond noir + barre verte qui grandit
        window.draw(clickBar);
    }
}