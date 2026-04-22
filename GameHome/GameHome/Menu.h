#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class Menu
{
public:
    Menu();
    ~Menu();
    void handleEvent(const std::optional<sf::Event>& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isPlayClicked() const;

private:
    sf::RectangleShape background;
    sf::RectangleShape playButton;
    sf::RectangleShape quitButton;
    bool playClicked = false;
    bool showImage = false;
    sf::Texture* imageTexture = nullptr;
    sf::Sprite* imageSprite = nullptr;
};