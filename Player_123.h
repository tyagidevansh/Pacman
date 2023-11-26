#pragma once
#include<SFML/Graphics.hpp>
#include"Animation_123.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime,float speed);
	//~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
private:
	sf::CircleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

