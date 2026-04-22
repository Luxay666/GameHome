#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class Menu
{
public:
    Menu();

    void handleEvent(const std::optional<sf::Event>& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    bool isPlayClicked() const;

private:
    sf::RectangleShape playButton;
    sf::Text playText;
    sf::Font font;
    bool playClicked = false;
};