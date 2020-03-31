/**
  * @file Map.h
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <memory>

#include "types.h"
#include "Element.h"
#include "Wall.h"
#include "Pill.h"
#include "Ball.h"
#include "Gate.h"
#include "Portal.h"



typedef std::unique_ptr<Element> PElement;
typedef std::vector<PElement> MapElements;

class Map
{
public:
	Map();

	~Map();

	/**
	  * Metoda inicjalizujaca elementy skladajace sie na mape rozgrywki.
	  * Na podstawie reprezentujego te elementy typu wyliczeniowego
	  * w tablicy PElement tworzone sa odpowiednie obiekty.
	  */
	void initializeMapp();

	/**
	  * Metoda zwracajaca polozenie poczatkowe mapy wzgledem punktu 0,0 okna.
	  *
	  * @retval sf::Vector2f wspolrzedne poczatkowe mapy
	  */
	sf::Vector2f getMapStartPosition();

	/**
	  * Metoda zwracajaca polozenie poczatkowe Pacmana na mapie.
	  *
	  * @retval sf::Vector2f wspolrzedne poczatkowe Pacmana
	  */
	sf::Vector2f getPlayerStartPosition();

	/**
	  * Metoda zwracajaca referencje na obiekt znajdujacy sie w danym miejscu w tablicy
	  * reprezentujacej mape gry.
	  *
	  * @param int x - wspolrzedna x obiektu
	  * @param int y - wspolrzedna y obiektu
	  @ @retval PElement& referencja na obiekt bedacy elementem mapy znajdujacym sie na podanej pozycji
	  */
	PElement& getObjectOnIndex(int x, int y);

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu obietow Ball w czasie trwanie rozgrywki.
	  */
	void update();

	/**
	  * Metoda odpowiedzialna za renderowanie wszystkich obiektow skladajacych sie na mape.
	  */
	void render(sf::RenderTarget& target);
	Fields getFieldOnIndex(int x, int y);
	Fields map[31][28];
		sf::Vector2f getGhostClydeStartPosition();
	sf::Vector2f getGhostPinkyStartPosition();
	sf::Vector2f getGhostBlinkyStartPosition();
private:
	bool is_initialize = false;
	PElement mapp[31][28];

	sf::Vector2f map_start_position;
	sf::Vector2f player_start_position;
    sf::Vector2f ghostClydeStartPosition_;
	sf::Vector2f ghostPinkyStartPosition_;
	sf::Vector2f ghostBlinkyStartPosition_;
	sf::Vector2f element_size;

	MapElements elements_;
};

#endif

