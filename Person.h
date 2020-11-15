#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	float speed;
	sf::Vector2f offset;
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	Animation animation;
	float gravitation;
	float heightOfJump;
public:
	Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect rect);

	void move();
	void update(float time, Person& p);
	void isEdgeOfMap(const int screenWidth);

	float& getX();
	float& getY();
	float& getOffsetX();
	float& getOffsetY();
	float getRectLeft();
	float getRectTop();
	float getRectHeight();
	float getRectWidth();
	sf::Sprite getSprite();
	sf::FloatRect getRect();

	void setOnGround(bool val);
	void setRectLeft(float left);
	void setRectTop(float top);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
};

