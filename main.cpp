#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <array>

#include "Headers/Global.hpp"
#include "Headers/Pacman.hpp"
int main() {
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

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

    int pacmanInitialX = 10;
    int pacmanInitialY = 16;

    Pacman pacman; 

    //game loop
    while (window.isOpen()) { 

        sf::Event event;

        pacman.move(map);
        //check if the window has been closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            pacman.handleInput(event);
        }

        // Draw the map
        for (size_t i = 0; i < map.size(); ++i) {
            for (size_t j = 0; j < map[i].size(); ++j) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);

                switch (map[i][j]) {
                    case '#':
                        cell.setFillColor(sf::Color::Blue); // Wall color
                        break;
                    case '.':
                    case ' ':
                        cell.setFillColor(sf::Color::Black); // Empty space color
                        break;
                    case 'o':
                        cell.setFillColor(sf::Color::Yellow); // Pellet color
                        break;
                    case 'P':
                        cell.setFillColor(sf::Color::Black);
                        break;
                    default:
                        cell.setFillColor(sf::Color::Black);
                        break;
                }

                window.draw(cell);
            }
        }
        pacman.draw(window);
        window.display();    
    }

    return 0;
}