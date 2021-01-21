#include "FileSystem.h"

FileSystem::FileSystem(std::string path)
{
	this->path = path;
}

void FileSystem::changeFile(std::string newPath)
{
	this->path = newPath;
}

void FileSystem::loadLevel(std::vector <Gumba>& gumbas, std::vector <Turtle>& turtle, std::vector <BonusMushroom>& bonus, std::vector <Tile>& tiles, background& bg, std::map <char, Tile>& tileMap, GameMap& map)
{
	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;
	else
	{
		while (!fin.eof())
		{
			std::string tmp;
			fin >> tmp;
			if (tmp == "Gumba")
			{
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int size;
				fin >> size;
				float gravity;
				fin >> gravity;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;  
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					gumbas.push_back(Gumba(pathToSprite, speed, sf::FloatRect(coordX, coordY, size, size), gravity));
					gumbas[i].setAnimationSettings(sf::Vector2i(size, size), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
				}
			}
			if (tmp == "Turtle")
			{
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				float gravity;
				fin >> gravity;
				float jump;
				fin >> jump;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					turtle.push_back(Turtle(pathToSprite, speed, sf::FloatRect(coordX, coordY, sizeX, sizeY), gravity, jump));
					turtle[i].setAnimationSettings(sf::Vector2i(sizeX, sizeY), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
				}
			}
			if (tmp == "Bonus")
			{
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int size;
				fin >> size;
				float gravity;
				fin >> gravity;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					bonus.push_back(BonusMushroom(pathToSprite, speed, sf::FloatRect(coordX, coordY, size, size), gravity));
				    bonus[i].setAnimationSettings(sf::Vector2i(size, size), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
				}
			}
			if (tmp == "Bg")
			{
				fin >> tmp;
				if (tmp == "Textures")
				{
					int kinds;
					fin >> kinds;
					for (int i = 0; i < kinds; i++)
					{
						int count;
						fin >> count;
						std::string pathToTexture;
						fin >> pathToTexture;
						bg.addTexture(std::to_string(i), pathToTexture);
						for (int j = 0; j < count; j++)
						{
							int coordX;
							fin >> coordX;
							int coordY;
							fin >> coordY;
							bg.addImageObj(std::to_string(i), sf::Vector2f(coordX, coordY));
						}

					}
				}
			}
			if (tmp == "tileMap")
			{
				
			}
			if (tmp == "gameMap")
			{
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				std::string path;
				fin >> path;
				map = GameMap(sf::Vector2i(sizeX, sizeY));
				map.loadFromFile(path, tileMap);
			}

		}
	}
}
