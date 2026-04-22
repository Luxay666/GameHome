#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, int _windowWidth, int _windowHeight)
    : window(window)
    , windowWidth(_windowWidth)
    , windowHeight(_windowHeight)
{
    barBackground.setSize({ (float)windowWidth - 20.f, 20.f });
    barBackground.setPosition({ 10.f, 10.f });
    barBackground.setFillColor(sf::Color(80, 80, 80));

	sky.setSize({ 1000.f, 1000.f });
	sky.setFillColor(sf::Color(135, 206, 235));

    barFill.setSize({ 0.f, 20.f });
    barFill.setPosition({ 10.f, 10.f });
    barFill.setFillColor(sf::Color(70, 200, 100));

    house.setSize({ 300.f, 200.f });
    house.setPosition({ 350.f, 500.f });
    house.setFillColor(sf::Color(210, 180, 140));
    house.setOutlineColor(sf::Color(100, 70, 40));
    house.setOutlineThickness(2.f);

    door.setSize({ 60.f, 90.f });
    door.setPosition({ 470.f, 610.f });
    door.setFillColor(sf::Color(100, 70, 40));

    windowLeft.setSize({ 60.f, 60.f });
    windowLeft.setPosition({ 390.f, 540.f });
    windowLeft.setFillColor(sf::Color(215, 206, 0));
    windowLeft.setOutlineColor(sf::Color(100, 70, 40));
    windowLeft.setOutlineThickness(2.f);

    windowRight.setSize({ 60.f, 60.f });
    windowRight.setPosition({ 550.f, 540.f });
    windowRight.setFillColor(sf::Color(215, 206, 0));
    windowRight.setOutlineColor(sf::Color(100, 70, 40));
    windowRight.setOutlineThickness(2.f);

    roof.setPointCount(3);
    roof.setPoint(0, { 330.f, 500.f });
    roof.setPoint(1, { 680.f, 500.f });
    roof.setPoint(2, { 500.f, 320.f });
    roof.setFillColor(sf::Color(180, 60, 40));
    roof.setOutlineColor(sf::Color(120, 40, 20));
    roof.setOutlineThickness(2.f);

    chimney.setSize({ 40.f, 80.f });
    chimney.setPosition({ 560.f, 360.f });
    chimney.setFillColor(sf::Color(150, 100, 80));
    chimney.setOutlineColor(sf::Color(100, 70, 40));
    chimney.setOutlineThickness(2.f);

    grass.setSize({ 1000.f, 100.f });
    grass.setPosition({ 0.f, 700.f });
    grass.setFillColor(sf::Color(60, 160, 60));

    path.setSize({ 60.f, 110.f });
    path.setPosition({ 470.f, 700.f });
    path.setFillColor(sf::Color(180, 150, 100));

    sun.setSize({ 80.f, 80.f });
    sun.setPosition({ 50.f, 50.f });
    sun.setFillColor(sf::Color(255, 220, 50));

    treeBody.setSize({ 30.f, 80.f });
    treeBody.setPosition({ 200.f, 620.f });
    treeBody.setFillColor(sf::Color(100, 60, 20));

    tree.setPointCount(3);
    tree.setPoint(0, { 150.f, 620.f });
    tree.setPoint(1, { 280.f, 620.f });
    tree.setPoint(2, { 215.f, 450.f });
    tree.setFillColor(sf::Color(30, 130, 30));
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
            if (clickCount < maxClicks)
            {
                clickCount++;
                float maxWidth = (float)windowWidth - 20.f;
                float stepWidth = maxWidth / maxClicks;
                barFill.setSize({ stepWidth * clickCount, 20.f });
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
        window.draw(sky);
        window.draw(barBackground);
        window.draw(barFill);
		if (clickCount == 0) std::cout << "Clique pour construire ta maison" << std::endl;
        if (clickCount >= 10) window.draw(house);
        if (clickCount >= 20) window.draw(roof);
        if (clickCount >= 30) window.draw(door);
        if (clickCount >= 40) { window.draw(windowLeft); window.draw(windowRight); }
        if (clickCount >= 50) window.draw(chimney);
        if (clickCount >= 60) window.draw(grass);
        if (clickCount >= 70) window.draw(path);
        if (clickCount >= 80) { window.draw(treeBody); window.draw(tree); }
        if (clickCount >= 90) window.draw(sun);
        if (clickCount == 100) std::cout << "Tu merite le diamant sur ow pour etre aller aussi loin" << std::endl;
    }
}