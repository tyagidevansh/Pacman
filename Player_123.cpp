#include "Player_123.h"
#include<SFML/Graphics.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime, float speed)
	:animation(texture,ImageCount,switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setRadius(20);
	body.setPosition(256.0, 256.0);
	body.setTexture(texture);
}

void Player::update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    // Horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
    }

    // Vertical movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= speed * deltaTime;
        row = 1; // Use a different row for moving up
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += speed * deltaTime;
        row = 3; // Use a different row for moving down
    }
    else {
        // If not moving vertically, use the default row for horizontal movement
        row = 2;
    }

    // Update the direction based on horizontal movement
    if (movement.x >= 0) {
        faceRight = false;
    }
    else {
        faceRight = true;
    }

    // Update the animation and position
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}


void Player::draw(sf::RenderWindow& window) {
	window.draw(body);
}