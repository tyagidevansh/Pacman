#include "Headers/Pacman.hpp"
//#include "Headers/MapCollision.hpp"

Pacman::Pacman() : speed(100.0f), direction(1.0f, 0.0f) {
    initShape();
    respawn();
}

void Pacman::initShape() {
    player.setRadius((CELL_SIZE-2)/ 2);
    player.setFillColor(sf::Color::Yellow);
    player.setOrigin(CELL_SIZE/2, CELL_SIZE);
    player.setPosition(11 * CELL_SIZE, 16 * CELL_SIZE);
}

void Pacman::respawn() {
    direction = sf::Vector2f(1.0f, 0.0f);
}

bool Pacman::wall_collision(std::vector<std::string>& map) {
    sf::FloatRect playerBounds = player.getGlobalBounds();

    // Calculate the new width and height to make the rect 20% smaller
    float smallerWidth = playerBounds.width * 0.8f;
    float smallerHeight = playerBounds.height * 0.8f;

    // Adjust the left and top to keep the same position
    float adjustedLeft = playerBounds.left + (playerBounds.width - smallerWidth) / 2;
    float adjustedTop = playerBounds.top + (playerBounds.height - smallerHeight) / 2;

    // Create the smaller FloatRect
    sf::FloatRect smallerPlayerBounds(adjustedLeft, adjustedTop, smallerWidth, smallerHeight);

    int leftCell = static_cast<int>(std::max(0.0f, smallerPlayerBounds.left) / CELL_SIZE);
    int rightCell = static_cast<int>(std::min(MAP_WIDTH * CELL_SIZE - 1.0f, smallerPlayerBounds.left + smallerPlayerBounds.width - 1.0f) / CELL_SIZE);
    int topCell = static_cast<int>(std::max(0.0f, smallerPlayerBounds.top) / CELL_SIZE);
    int bottomCell = static_cast<int>(std::min(MAP_HEIGHT * CELL_SIZE - 1.0f, smallerPlayerBounds.top + smallerPlayerBounds.height - 1.0f) / CELL_SIZE);

    // Check collision based on the direction
    if (direction.x < 0 && (leftCell >= 0 && (map[topCell][leftCell] == '#' || map[bottomCell][leftCell] == '#'))) {
        printf("Collision - Left\n");
        return true;
    }
    if (direction.x > 0 && (rightCell < MAP_WIDTH && (map[topCell][rightCell] == '#' || map[bottomCell][rightCell] == '#'))) {
        printf("Collision - Right\n");
        return true;
    }
    if (direction.y < 0 && (topCell >= 0 && (map[topCell][leftCell] == '#' || map[topCell][rightCell] == '#'))) {
        printf("Collision - Up\n");
        return true;
    }
    if (direction.y > 0 && (bottomCell < MAP_HEIGHT && (map[bottomCell][leftCell] == '#' || map[bottomCell][rightCell] == '#'))) {
        printf("Collision - Down\n");
        return true;
    }

    return false;
}

void Pacman::move(std::vector<std::string>& map, float deltaTime) {
    if (!wall_collision(map)) {
        sf::Vector2f nextPosition = player.getPosition() + direction * speed * deltaTime;
        player.setPosition(nextPosition);
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
