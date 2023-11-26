#include"Animation_123.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime) {
	this->ImageCount = ImageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);

}
void Animation::update(int row, float deltaTime,bool faceRight) {
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= ImageCount.x) {
			currentImage.x = 0;
		}
	}
	
	uvRect.top = currentImage.y * uvRect.height;
	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}