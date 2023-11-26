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
    bool map_collision(bool i_collect_pellets, bool i_use_door, float i_x, float i_y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map);
    void move(std::vector<std::string>& map, float deltaTime);
    void handleInput(sf::Event& event);
    void draw(sf::RenderWindow& window);
};