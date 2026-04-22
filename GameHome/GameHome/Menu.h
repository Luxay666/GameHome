#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void handleEvent(const std::optional<sf::Event>& event);
    void draw();
    bool isPlayClicked() const;

private:
    sf::RenderWindow& window;
    bool playClicked = false;

    std::optional<sf::Font> font;
    std::optional<sf::Text> titleText;
    std::optional<sf::Text> playText;
    std::optional<sf::Text> quitText;

    sf::RectangleShape playButton{ {300.f, 80.f} };
    sf::RectangleShape quitButton{ {300.f, 80.f} };
};