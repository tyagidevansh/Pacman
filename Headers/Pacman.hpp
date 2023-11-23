#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Pacman
{
private:
    sf::CircleShape player;
    float speed;
    sf::Vector2f direction;
    sf::Clock clock;

public:
    Pacman();
    void initShape();
    void respawn();
    void move(std::vector<std::string>& map, float deltaTime);
    void handleInput(sf::Event& event);
    void draw(sf::RenderWindow& window);
};
