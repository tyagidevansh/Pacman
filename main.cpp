#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <array>

#include "Headers/Global.hpp"
#include "Headers/Pacman.hpp"
int main() {
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    bool game_won = false;


    std::vector<std::string> map = {
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

    //game loop
    while (window.isOpen()) { 
        //check if the window has been closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        unsigned short pacmanInitialX = 0;
        unsigned short pacmanInitialY = 0;

        // Draw the map
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
                        //cell.setFillColor(sf::Color::Yellow); // Pellet color
                        break;
                    case 'P':
                        pacmanInitialX = static_cast<unsigned short>(j);
                        pacmanInitialY = static_cast<unsigned short>(i);
                        break;
                    default:
                        cell.setFillColor(sf::Color::Black);
                        break;
                }

                window.draw(cell);
            }
        }

        window.display();

        Pacman pacman;
        pacman.set_position(pacmanInitialX * CELL_SIZE, pacmanInitialY * CELL_SIZE);        
    }

    return 0;
}
