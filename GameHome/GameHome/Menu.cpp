#include "Menu.h"
#include <iostream>

Menu::Menu()
{
    // Bouton
    playButton.setSize({ 200.f, 80.f });
    playButton.setFillColor(sf::Color::Green);
    playButton.setPosition({ 400.f, 450.f });

    // Police
    if (!font.loadFromFile("arial.ttf"))
        std::cout << "Erreur chargement police\n";

    // Texte
    playText.setFont(font);
    playText.setString("PLAY");
    playText.setCharacterSize(30);
    playText.setFillColor(sf::Color::Black);
    playText.setPosition({ 460.f, 470.f });
}

void Menu::handleEvent(const std::optional<sf::Event>& event, sf::RenderWindow& window)
{
    if (!event) return;

    if (event->is<sf::Event::MouseButtonPressed>())
    {
        auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

        if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (playButton.getGlobalBounds().contains((sf::Vector2f)mousePos))
            {
                playClicked = true;
            }
        }
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(playButton);
    window.draw(playText);
}

bool Menu::isPlayClicked() const
{
    return playClicked;
}