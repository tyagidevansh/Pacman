// #include <sfml/Graphics.hpp>

// int main(){
//     sf::RenderWindow window(sf::VideoMode(512, 512), "Tutorial", sf::Style::Close | sf::Style::Titlebar);
//     window.setFramerateLimit(60);

//     sf::CircleShape player(30.f);
//     player.setFillColor(sf::Color::Yellow);

//     sf::CircleShape inky(20.f, 3);
    
//     while (window.isOpen()){
//         sf::Event event;
//         while(window.pollEvent(event)){
//             if(event.type == sf::Event::Closed){
//                 window.close();
//                 break;
//             }    
//         }

//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
//             player.move(-2, 0);
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
//             player.move(2, 0);
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
//             player.move(0, -2);
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
//             player.move(0, 2);
//         }

//         window.clear();
//         window.draw(inky);
//         window.draw(player);
//         window.display();
//     }

//     return 0;
// }

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Headers/Global.hpp"
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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        window.clear(sf::Color::Black);

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
                        cell.setFillColor(sf::Color::Yellow); // Pac-Man color
                        break;
                    // Add cases for other elements (ghosts, etc.) as needed
                    default:
                        cell.setFillColor(sf::Color::Black);
                        break;
                }

                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
