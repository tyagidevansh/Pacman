#include <SFML/Graphics.hpp>
#include "Headers/Global.hpp"
#include <array>
#include <string>

const int gridSize = 40;

std::array<std::string, MAP_HEIGHT> map_sketch = {
	" ################### ",
	" #........#........# ",
	" #o##.###.#.###.##o# ",
	" #.................# ",
	" #.##.#.#####.#.##.# ",
	" #....#...#...#....# ",
	" ####.### # ###.#### ",
	"    #.#   0   #.#    ",
	"#####.# ##=## #.#####",
	"     .  #123#  .     ",
	"#####.# ##### #.#####",
	"    #.#       #.#    ",
	" ####.# ##### #.#### ",
	" #........#........# ",
	" #.##.###.#.###.##.# ",
	" #o.#.....P.....#.o# ",
	" ##.#.#.#####.#.#.## ",
	" #....#...#...#....# ",
	" #.######.#.######.# ",
	" #.................# ",
	" ################### "
};

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

class Pacman {
public:
    sf::CircleShape shape;
    float speed;
    sf::Vector2f direction;

    Pacman() : speed(0.2f), direction(1.0f, 0.0f) {
        initShape();
        respawn();
    }

    void initShape() {
        shape.setRadius(gridSize / 2);
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(gridSize / 2, gridSize / 2);
    }

    void respawn() {
        int startX = 1; // Adjust as needed
        int startY = 1; // Adjust as needed
        shape.setPosition(startX * gridSize, startY * gridSize);
        direction = sf::Vector2f(1.0f, 0.0f);
    }

    void move() {
    sf::Vector2f nextPosition = shape.getPosition() + direction * speed;

    // Check if the next position is within the bounds and not a wall
    int cellX = static_cast<int>(nextPosition.x / CELL_SIZE);
    int cellY = static_cast<int>(nextPosition.y / CELL_SIZE);

    if (cellX >= 0 && cellX < MAP_WIDTH && cellY >= 0 && cellY < MAP_HEIGHT &&
        map_sketch[cellY][cellX] != '#') {
        // Check if Pac-Man encounters food
        if (map_sketch[cellY][cellX] == 'o') {
            // Remove the food (you may want to update your map_sketch array accordingly)
            // Increment score or perform other actions
        }

        shape.move(direction * speed);
    }
}


    void handleInput(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W)
                direction = sf::Vector2f(0.0f, -1.0f);
            else if (event.key.code == sf::Keyboard::S)
                direction = sf::Vector2f(0.0f, 1.0f);
            else if (event.key.code == sf::Keyboard::A)
                direction = sf::Vector2f(-1.0f, 0.0f);
            else if (event.key.code == sf::Keyboard::D)
                direction = sf::Vector2f(1.0f, 0.0f);
        }
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    Pacman pacman;

    sf::Clock clock;
    float elapsedTime = 0.0f;
    const float timePerFoodRespawn = 5.0f; // Adjust as needed

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            pacman.handleInput(event);
        }

        // Move Pac-Man and Ghost
        pacman.move();

        // Check for collisions (you can add more logic here based on your game design)
        sf::FloatRect pacmanBounds = pacman.shape.getGlobalBounds();


        window.clear();

        for (size_t i = 0; i < map.size(); ++i) {
            for (size_t j = 0; j < map[i].size(); ++j) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);

                switch (map[i][j]) {
                    case '#':
                        cell.setFillColor(sf::Color::Blue); // Wall color
                        break;
                    case '.'  || ' ':
                        cell.setFillColor(sf::Color::Black); // Empty space color
                        break;
                    case 'o':
                        cell.setFillColor(sf::Color::Green); // Pellet color
                        break;
                    case 'P':
                        cell.setFillColor(sf::Color::Yellow);
                        break;
                    default:
                        cell.setFillColor(sf::Color::Black);
                        break;
                }

                window.draw(cell);
            }
        }

        window.display();

        // Draw Pac-Man and Ghost
        window.draw(pacman.shape);

        window.display();
    }

    return 0;
}
