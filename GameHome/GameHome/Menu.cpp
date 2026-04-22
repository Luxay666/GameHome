#include "Menu.h"
#include <iostream>

Menu::Menu()
{
    background.setSize({ 1000.f, 1000.f });
    background.setFillColor(sf::Color(30, 30, 60));

    playButton.setSize({ 200.f, 50.f });
    playButton.setFillColor(sf::Color(70, 130, 180));
    playButton.setPosition({ 400.f, 400.f });

    quitButton.setSize({ 200.f, 50.f });
    quitButton.setFillColor(sf::Color(180, 70, 70));
    quitButton.setPosition({ 400.f, 500.f });

    imageTexture = new sf::Texture("assets/home.jpg");
    imageSprite = new sf::Sprite(*imageTexture);
    imageSprite->setPosition({ 0.f, 0.f });
}

Menu::~Menu()
{
    delete imageSprite;
    delete imageTexture;
}

void Menu::handleEvent(const std::optional<sf::Event>& event, sf::RenderWindow& window)
{
    if (!event) return;
    if (const auto* e = event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (e->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f mouse = (sf::Vector2f)sf::Mouse::getPosition(window);
            if (playButton.getGlobalBounds().contains(mouse))
            {
                showImage = true;
                playClicked = true;
            }
            if (quitButton.getGlobalBounds().contains(mouse))
                window.close();
        }
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(background);
    if (showImage && imageSprite)
        window.draw(*imageSprite);
    else
    {
        window.draw(playButton);
        window.draw(quitButton);
    }
}

bool Menu::isPlayClicked() const { return playClicked; }