/**
  * @file Configuration.h
  * @author Jakub Wrzosek
  * @date 03.01.2020
  */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <fstream>

#include "nlohmann/json.hpp"
#include "Element.h"
#include "Wall.h"
#include "Player.h"

using json = nlohmann::json;

typedef std::unique_ptr<Element> PElement;
typedef std::vector<PElement> elements_list;

/**
  * Klasa sluzaca do pobierania konfiguracji mapy z pliku z rozszerzeniem json.
  * Wykorzystuje biblioteke nhlomann::json.
  */
class Configuration
{
public:
	Configuration();
	~Configuration();

	/**
	  * Metoda odpowiedzialna za inicjalizacje tablicy typu wyliczeniowego
	  * reprezentujacego obiekty skladajace sie na mape rozgrywki.
	  */
	void initFieldsMap();

	/**
	  * Metoda odpowiedzialna za deserializacje pliku json zawierajacego wsplrzedne
	  * obiektow skladajacych sie na mape rozgrywki.
	  *
	  * @param std::string filepath - sciezka do pliku konfiguracyjnego .json
	  */
	void deserialize_json(std::string filepath);
	
	/**
	  * Metoda umozliwiajaca pobranie elementow typu wyliczeniowego reprezentujacego
	  * elementy skladajce sie na mape rozgrywki w celu inicjalizacji wlasciwych obiektow
	  * w odpowiednich miejcach.
	  *
	  * @param int x - indeks x w tablicy
	  * @param int y - indeks y w tablicy
	  * @retval Fields element typu wyliczeniowego reprezentujacy obiekt na danym miejcu w talblicy 
	  *			reprezentujacej mape
	  */
	Fields getFieldOnIndex(int x, int y);

	/**
	  * Metoda pomocnicza sluzaca to wypisania elementow reprezentujacych mape na standardowe 
	  * wyjscie w celu sprawdzenie poprawdnosci wczytanych danych.
	  */
	void printMap();
private:
	Fields fields_map[31][28];
};

#endif // CONFIGURATION_H