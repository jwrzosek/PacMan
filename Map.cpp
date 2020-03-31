#include "Map.h"
#include "Configuration.h"

Map::Map(): map
{
	{ W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
	{ W,o,o,o,o,o,o,o,o,o,o,o,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,W },
	{ W,o,W,W,W,W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,o,W },
	{ W,O,W,n,n,W,o,W,n,n,n,W,o,W,W,o,W,n,n,n,W,o,W,n,n,W,O,W },
	{ W,o,W,W,W,W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,o,W },
	{ W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W },
	{ W,o,W,W,W,W,o,W,W,o,W,W,W,W,W,W,W,W,o,W,W,o,W,W,W,W,o,W },
	{ W,o,W,W,W,W,o,W,W,o,W,W,W,W,W,W,W,W,o,W,W,o,W,W,W,W,o,W },
	{ W,o,o,o,o,o,o,W,W,o,o,o,o,W,W,o,o,o,o,W,W,o,o,o,o,o,o,W },
	{ W,W,W,W,W,W,o,W,W,W,W,W,n,W,W,n,W,W,W,W,W,o,W,W,W,W,W,W },
	{ n,n,n,n,n,W,o,W,W,W,W,W,n,W,W,n,W,W,W,W,W,o,W,n,n,n,n,n },
	{ n,n,n,n,n,W,o,W,W,n,n,n,n,n,n,n,n,n,n,W,W,o,W,n,n,n,n,n },
	{ n,n,n,n,n,W,o,W,W,n,W,W,W,G,G,W,W,W,n,W,W,o,W,n,n,n,n,n },
	{ W,W,W,W,W,W,o,W,W,n,W,n,n,n,n,n,n,W,n,W,W,o,W,W,W,W,W,W },
	{ P,n,n,n,n,n,o,n,n,n,W,n,n,n,n,n,n,W,n,n,n,o,n,n,n,n,n,P },
	{ W,W,W,W,W,W,o,W,W,n,W,n,n,n,n,n,n,W,n,W,W,o,W,W,W,W,W,W },
	{ n,n,n,n,n,W,o,W,W,n,W,W,W,W,W,W,W,W,n,W,W,o,W,n,n,n,n,n },
	{ n,n,n,n,n,W,o,W,W,n,n,n,n,n,n,n,n,n,n,W,W,o,W,n,n,n,n,n },
	{ n,n,n,n,n,W,o,W,W,n,W,W,W,W,W,W,W,W,n,W,W,o,W,n,n,n,n,n },
	{ W,W,W,W,W,W,o,W,W,n,W,W,W,W,W,W,W,W,n,W,W,o,W,W,W,W,W,W },
	{ W,o,o,o,o,o,o,o,o,o,o,o,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,W },
	{ W,o,W,W,W,W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,o,W },
	{ W,o,W,W,W,W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,o,W },
	{ W,O,o,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W,W,o,o,O,W },
	{ W,W,W,o,W,W,o,W,W,o,W,W,W,W,W,W,W,W,o,W,W,o,W,W,o,W,W,W },
	{ W,W,W,o,W,W,o,W,W,o,W,W,W,W,W,W,W,W,o,W,W,o,W,W,o,W,W,W },
	{ W,o,o,o,o,o,o,W,W,o,o,o,o,W,W,o,o,o,o,W,W,o,o,o,o,o,o,W },
	{ W,o,W,W,W,W,W,W,W,W,W,W,o,W,W,o,W,W,W,W,W,W,W,W,W,W,o,W },
	{ W,o,W,W,W,W,W,W,W,W,W,W,o,W,W,o,W,W,W,W,W,W,W,W,W,W,o,W },
	{ W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W },
	{ W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W }
}
{
	this->map_start_position = { 120.f, 40.f };
	this->element_size = { 20.f, 20.f };
	this->player_start_position = { (map_start_position.x + (element_size.x * 14)),
		(map_start_position.y + (element_size.y * 23)) };
    this->ghostClydeStartPosition_ = { (map_start_position.x + (element_size.x * 11)), (map_start_position.y + (element_size.y * 15)) };
	this->ghostPinkyStartPosition_ = { (map_start_position.x + (element_size.x * 13)), (map_start_position.y + (element_size.y * 15)) };
	this->ghostBlinkyStartPosition_ = { (map_start_position.x + (element_size.x * 15)), (map_start_position.y + (element_size.y * 15)) };
}

Map::~Map()
{

}

void Map::initializeMapp()
{
	Configuration config;
	//config.deserialize_json("map_config.json");

	sf::Vector2f currentPos = map_start_position;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 28; j++) {
			if (config.getFieldOnIndex(j, i) == W)
				mapp[i][j] = PElement(new Wall(currentPos));
			else if (config.getFieldOnIndex(j, i) == o)
				mapp[i][j] = PElement(new Pill(currentPos));
			else if (config.getFieldOnIndex(j, i) == O)
				mapp[i][j] = PElement(new Ball(currentPos));
			else if (config.getFieldOnIndex(j, i) == G)
				mapp[i][j] = PElement(new Gate(currentPos));
			else if (config.getFieldOnIndex(j, i) == P)
				mapp[i][j] = PElement(new Portal(currentPos));
			currentPos.x += element_size.x;
		}
		currentPos.x = map_start_position.x;
		currentPos.y += element_size.y;
	}
	config.printMap();
}


sf::Vector2f Map::getMapStartPosition()
{
	return this->map_start_position;
}

sf::Vector2f Map::getPlayerStartPosition()
{
	return this->player_start_position;
}

sf::Vector2f Map::getGhostClydeStartPosition()
{
	return this->ghostClydeStartPosition_;
}

sf::Vector2f Map::getGhostPinkyStartPosition()
{
	return this->ghostPinkyStartPosition_;
}

sf::Vector2f Map::getGhostBlinkyStartPosition()
{
	return this->ghostBlinkyStartPosition_;
}

Fields Map::getFieldOnIndex(int x, int y)
{
	return this->map[y][x];
}

PElement& Map::getObjectOnIndex(int x, int y)
{
	return mapp[y][x];
}

void Map::update()
{
	if (!is_initialize)
	{
		//this->initializeMap();
		this->initializeMapp();
		is_initialize = true;
	}
}

void Map::render(sf::RenderTarget& target)
{
	//for (auto const & element : this->elements_)
	//	element->render(target);
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 28; j++)
			if(mapp[i][j] != NULL)
				mapp[i][j]->render(target);
	}
}
