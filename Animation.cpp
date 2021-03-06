#include "Animation.h"
#include<SFML/Graphics/Image.hpp>

Animation::Animation()
{
	this->speed = 0.1f;
	this->currentFrame = 0;
	this->firstFrameCoordinates.x = 0;
	this->firstFrameCoordinates.y = 0;
	this->countOfFrames = 0;
	this->frameSize.x = 0;
	this->frameSize.y = 0;
	this->rangeBetweenFrames = 0;
}

Animation::Animation(std::string pathToFile)
{
	this->texture.loadFromFile(pathToFile);
	this->sprite.setTexture(texture);
	this->speed = 0.1f;
	this->currentFrame = 0;
	this->firstFrameCoordinates.x = 0;
	this->firstFrameCoordinates.y = 0;
	this->countOfFrames = 0;
	this->frameSize.x = 0;
	this->frameSize.y = 0;
	this->rangeBetweenFrames = 0;
}

void Animation::setSpriteSheet(std::string pathToFile)
{
	this->texture.loadFromFile(pathToFile);
	this->sprite.setTexture(texture);
}

void Animation::setAnimationParametres(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	this->frameSize = size;
	this->firstFrameCoordinates = firstFrameCoordinates;
	this->countOfFrames = countOfFrames - 1;
	this->speed = speed;
	this->rangeBetweenFrames = rangeBetweenFrames;
	update(0);
}

sf::Sprite Animation::update(float time)
{
	currentFrame += speed * time;// speed * time;
	if (currentFrame > countOfFrames) 
		currentFrame -= countOfFrames;
	sprite.setTextureRect(sf::IntRect(firstFrameCoordinates.x + (rangeBetweenFrames + frameSize.x) * int(currentFrame), firstFrameCoordinates.y , frameSize.x, frameSize.y));
	return sprite;
}

sf::Sprite Animation::mirrorUpdate(float time)
{
	currentFrame += speed * time;
	if (currentFrame > countOfFrames)
		currentFrame -= countOfFrames;
	sprite.setTextureRect(sf::IntRect(firstFrameCoordinates.x + (rangeBetweenFrames + frameSize.x) * int(currentFrame)+frameSize.x, firstFrameCoordinates.y, -frameSize.x, frameSize.y));
	return sprite;
}

void Animation::startOver()
{
	currentFrame = 0;
	sprite.setTextureRect(sf::IntRect(firstFrameCoordinates,frameSize));
}

void Animation::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Animation::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

sf::Sprite Animation::getSprite()
{
	return sprite;
}

void Animation::makeInvisible()
{
	sprite.setColor(sf::Color(0, 0, 0, 0));
}

Animation::~Animation()
{

}
