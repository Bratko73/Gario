#pragma once
#include "SFML/include/SFML/Graphics.hpp"
#include <vector>
class background
{
private:
	std::vector<std::string> ImageNames;
	std::vector<sf::Sprite>ImageObj;
	std::vector<sf::Texture> textures;
	std::vector<sf::Text> TextObj;
	sf::Font StandartFont;
	sf::Color BgColor;
	float offset;
public:
	background();
	background(std::string PathToFont);
	void SetBgColor(sf::Color color);
	void SetFont(std::string PathToFont);
	void addTextObj(int kernel, std::string text, sf::Font font);
	void addTextObj(int kernel, std::string text);
	void addTexture(std::string name, std::string PathToFile);
	void addImageObj(std::string name);
	void clearBg();
	void ImageObjSetPosition(int index, sf::Vector2f Pos);
	void TextObjSetPosition(int index, sf::Vector2f Pos);
	void drawBackground(sf::RenderWindow& window, float offsetX);
};
