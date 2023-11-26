#include "Headers/Pacman.hpp"

Pacman::Pacman() : speed(100.0f), direction(1.0f, 0.0f)  {
    initShape();
    respawn();
}

void Pacman::initShape() {
    player.setRadius(CELL_SIZE / 2);
    player.setFillColor(sf::Color::Yellow);
    player.setOrigin(CELL_SIZE / 2, CELL_SIZE / 2);
    player.setPosition(11 * CELL_SIZE, 16 * CELL_SIZE);
}

void Pacman::respawn() {
    direction = sf::Vector2f(1.0f, 0.0f);
}

bool Pacman::map_collision(bool i_collect_pellets, bool i_use_door, float i_x, float i_y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map) {
    bool output = false;

    // Getting the exact position.
    float cell_x = i_x / CELL_SIZE;
    float cell_y = i_y / CELL_SIZE;

    // A ghost/Pacman can intersect 4 cells at most.
    for (unsigned char a = 0; a < 4; a++) {
        short x = 0;
        short y = 0;

        switch (a) {
            case 0: // Top left cell
                x = static_cast<short>(floor(cell_x));
                y = static_cast<short>(floor(cell_y));
                break;
            case 1: // Top right cell
                x = static_cast<short>(ceil(cell_x));
                y = static_cast<short>(floor(cell_y));
                break;
            case 2: // Bottom left cell
                x = static_cast<short>(floor(cell_x));
                y = static_cast<short>(ceil(cell_y));
                break;
            case 3: // Bottom right cell
                x = static_cast<short>(ceil(cell_x));
                y = static_cast<short>(ceil(cell_y));
                break;
        }

        // Making sure that the position is inside the map.
        if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x) {
            if (!i_collect_pellets) { // Here we only care about the walls.
                if (Cell::Wall == i_map[x][y] || (!i_use_door && Cell::Door == i_map[x][y])) {
                    output = true;
                }
            } else { // Here we only care about the collectables.
                if (Cell::Energizer == i_map[x][y]) {
                    output = true;
                    i_map[x][y] = Cell::Empty;
                } else if (Cell::Pellet == i_map[x][y]) {
                    i_map[x][y] = Cell::Empty;
                }
            }
        }
    }

    return output;
}


void Pacman::move(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& map, float deltaTime) {
    std::array<bool, 4> walls{};
    
    // Check collisions in each direction
    walls[0] = map_collision(false, false, player.getPosition().x + PACMAN_SPEED * deltaTime, player.getPosition().y, map);
    walls[1] = map_collision(false, false, player.getPosition().x, player.getPosition().y - PACMAN_SPEED * deltaTime, map);
    walls[2] = map_collision(false, false, player.getPosition().x - PACMAN_SPEED * deltaTime, player.getPosition().y, map);
    walls[3] = map_collision(false, false, player.getPosition().x, player.getPosition().y + PACMAN_SPEED * deltaTime, map);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && walls[0] == false) {
        player.move(PACMAN_SPEED * deltaTime, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && walls[1] == false) {
        player.move(0.0f, -PACMAN_SPEED * deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && walls[2] == false) {
        player.move(-PACMAN_SPEED * deltaTime, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && walls[3] == false) {
        player.move(0.0f, PACMAN_SPEED * deltaTime);
    }
}


void Pacman::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            direction = sf::Vector2f(0.0f, -1.0f);
        } else if (event.key.code == sf::Keyboard::Down) {
            direction = sf::Vector2f(0.0f, 1.0f);
        } else if (event.key.code == sf::Keyboard::Left) {
            direction = sf::Vector2f(-1.0f, 0.0f);
        } else if (event.key.code == sf::Keyboard::Right) {
            direction = sf::Vector2f(1.0f, 0.0f);
        }
    }
}

void Pacman::draw(sf::RenderWindow& window) {
    window.draw(player);
}