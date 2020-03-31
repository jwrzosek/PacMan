#include "Configuration.h"

Configuration::Configuration()
{
	this->initFieldsMap();
	this->deserialize_json("map_config.json");
}

Configuration::~Configuration()
{
}

void Configuration::initFieldsMap()
{
	for (int i = 0; i < 31; i++)
		for (int j = 0; j < 28; j++)
			this->fields_map[i][j] = n;
}




void Configuration::deserialize_json(std::string filepath)
{
	//elements_list elements;

	std::ifstream ifile(filepath);
	if (ifile.is_open())
	{
		json jdata;
		int x, y;

		try
		{
			ifile >> jdata;

			if (jdata.is_object())
			{
				for (auto& element : jdata.at("walls"))
				{
					x = element.at("startX").get<int>();
					y = element.at("startY").get<int>();

					//elements.push_back(PElement(new Wall(elementPos)));
					this->fields_map[y][x] = W;
				}

				for (auto& element : jdata.at("pills"))
				{
					x = element.at("startX").get<int>();
					y = element.at("startY").get<int>();

					this->fields_map[y][x] = o;
				}

				for (auto& element : jdata.at("balls"))
				{
					x = element.at("startX").get<int>();
					y = element.at("startY").get<int>();

					this->fields_map[y][x] = O;
				}

				for (auto& element : jdata.at("gates"))
				{
					x = element.at("startX").get<int>();
					y = element.at("startY").get<int>();

					this->fields_map[y][x] = G;
				}

				for (auto& element : jdata.at("portals"))
				{
					x = element.at("startX").get<int>();
					y = element.at("startY").get<int>();

					this->fields_map[y][x] = P;
				}
			}
		}
		catch (std::exception const& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	//return elements;
}

Fields Configuration::getFieldOnIndex(int x, int y)
{
	return this->fields_map[y][x];
}

/*
 * Funkcja pomocnicza pozwalaj¹ca sprawdziæ poprawnoœæ wczytanych z pliku konfiguracyjnego danych.
 */
void Configuration::printMap()
{
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 28; j++) {
			if (fields_map[i][j] == W) {
				std::cout << "W";
			}
			else if (fields_map[i][j] == o) {
				std::cout << "o";
			}
			else if (fields_map[i][j] == O) {
				std::cout << "O";
			}
			else if (fields_map[i][j] == G) {
				std::cout << "G";
			}
			else if (fields_map[i][j] == P) {
				std::cout << "P";
			}
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}

}
