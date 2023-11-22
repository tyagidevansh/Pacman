#include <sfml/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tutorial", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    sf::CircleShape player(30.f);
    player.setFillColor(sf::Color::Yellow);

    sf::CircleShape inky(20.f, 3);
    
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                break;
            }    
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            player.move(-2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            player.move(2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            player.move(0, -2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            player.move(0, 2);
        }

        window.clear();
        window.draw(inky);
        window.draw(player);
        window.display();
    }

    return 0;
}