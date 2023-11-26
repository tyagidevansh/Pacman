#include <SFML/Graphics.hpp>
#include<iostream>
#include"Player_123.h"


int main()

{   //Creating a window
    sf::RenderWindow window(sf::VideoMode(512,512),"SFML TUTORIAL",sf::Style::Default);
    sf::Texture playertexture;
    playertexture.loadFromFile("Pacman16.png");

    Player player(&playertexture,sf::Vector2u(6,4),0.1f,100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;
    /*    
    sf::Vector2u textureSize=playertexture.getSize();
    textureSize.x /= 6;
    textureSize.y /= 4;
    player.setTextureRect(sf::IntRect(textureSize.x * 1, textureSize.y * 0, textureSize.x, textureSize.y));
    */

    //GAME LOOP
    while (window.isOpen()) {
        deltaTime=clock.restart().asSeconds();
        sf::Event evnt;
        
        //So that we can interact with our window while it's open
       
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
            
        
        
        player.update(deltaTime);

        window.clear(sf::Color::Black);
        player.draw(window);
        window.display();
    }
    return 0;
}