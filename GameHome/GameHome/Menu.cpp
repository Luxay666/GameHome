#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window)
    : window(window)
{
    // Font
    font.emplace();
    if (!font->openFromFile("assets/OldeTome.ttf"))
    {
        std::cout << "ERREUR: police introuvable" << std::endl;
    }

    // Titre
    titleText.emplace(*font, "MON JEU", 80);
    titleText->setFillColor(sf::Color::White);
    titleText->setPosition({ 300.f, 150.f });

    // Bouton Play
    playButton.setPosition({ 350.f, 400.f });
    playButton.setFillColor(sf::Color(70, 130, 180));

    playText.emplace(*font, "Play", 50);
    playText->setFillColor(sf::Color::White);
    playText->setPosition({ 435.f, 410.f });

    // Bouton Quit
    quitButton.setPosition({ 350.f, 550.f });
    quitButton.setFillColor(sf::Color(180, 70, 70));

    quitText.emplace(*font, "Quit", 50);
    quitText->setFillColor(sf::Color::White);
    quitText->setPosition({ 435.f, 560.f });
}

void Menu::handleEvent(const std::optional<sf::Event>& event)
{
    if (const auto* e = event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (e->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f mouse = { (float)e->position.x, (float)e->position.y };

            if (playButton.getGlobalBounds().contains(mouse))
                playClicked = true;

            if (quitButton.getGlobalBounds().contains(mouse))
                window.close();
        }
    }
}

void Menu::draw()
{
    window.draw(playButton);
    window.draw(quitButton);
    if (titleText) window.draw(*titleText);
    if (playText)  window.draw(*playText);
    if (quitText)  window.draw(*quitText);
}

bool Menu::isPlayClicked() const
{
    return playClicked;
}