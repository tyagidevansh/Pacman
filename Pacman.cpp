#include "Headers/Pacman.hpp"

Pacman::Pacman() : speed(0.2f), direction(1.0f, 0.0f) {
    initShape();
    respawn();
}

void Pacman::initShape() {
    player.setRadius(CELL_SIZE / 2);
    player.setFillColor(sf::Color::Yellow);
    player.setOrigin(CELL_SIZE / 2, CELL_SIZE / 2);
}

void Pacman::respawn() {
    int startX = 10; 
    int startY = 16; 
    player.setPosition(startX * CELL_SIZE, startY * CELL_SIZE);
    direction = sf::Vector2f(1.0f, 0.0f);
}

void Pacman::move(std::vector<std::string>& map) {
    sf::Vector2f nextPosition = player.getPosition() + direction * speed;

    int cellX = static_cast<int>(nextPosition.x / CELL_SIZE);
    int cellY = static_cast<int>(nextPosition.y / CELL_SIZE);

    if (cellX >= 0 && cellX < MAP_WIDTH && cellY >= 0 && cellY < MAP_HEIGHT && map[cellY][cellX] != '#') {
        if (map[cellY][cellX] == '.') {
            map[cellY][cellX] = ' ';
        }
        player.setPosition(nextPosition);
    }
}

void Pacman::handleInput(sf::Event& event) {
    speed = 0.5f;
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            direction = sf::Vector2f(0.0f, -speed);
        } else if (event.key.code == sf::Keyboard::Down) {
            direction = sf::Vector2f(0.0f, speed);
        } else if (event.key.code == sf::Keyboard::Left) {
            direction = sf::Vector2f(-speed, 0.0f);
        } else if (event.key.code == sf::Keyboard::Right) {
            direction = sf::Vector2f(speed, 0.0f);
        }
    }
}

void Pacman::draw(sf::RenderWindow& window) {
    window.draw(player);
}
