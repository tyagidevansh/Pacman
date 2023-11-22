#include <SFML/Graphics.hpp>
#include <math.h>
#include "Headers/Global.hpp"
#include "Headers/Pacman.hpp"

Pacman::Pacman() {
    position = {0, 0};
    player.setRadius(CELL_SIZE / 2);
    player.setFillColor(sf::Color::Yellow);
}

bool map_collision(bool i_collect_pellets, short i_x, short i_y, std::vector<std::string> map){
    bool output = 0;

    float cell_x = i_x / static_cast<float>(CELL_SIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE);

    for (int a = 0; a < 4; a++){
        int x = 0;
        int y = 0;

        switch (a){
            case 0:
            
        }
    }
    
}

void Pacman::draw(sf::RenderWindow& window) {
    sf::CircleShape player(CELL_SIZE / 2);
    player.setPosition(position.x, position.y);
    window.draw(player);
}

void Pacman::set_position(unsigned short i_x, unsigned short i_y) {
    position = {i_x, i_y};
}

void Pacman::handle_input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        position.x -= 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        position.x += 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        position.y -= 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        position.y += 2;
    }
}

void Pacman::update