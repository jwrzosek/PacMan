/**
  * @file Wall.h
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */

#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "types.h"
#include "Visitor.h"
#include "Element.h"

/**
  * Klasa reprezentujaca sciany w labiryncie, w ktorym porusza sie Pacman.
  * Kolizja Pacmana z obiektem Wall powoduje zatrzymanie Pacmana.
  */
class Wall : public Element
{
public:

	Wall();

	/**
	  * Konstruktor.
	  *
	  * @param sf::Vector2f shapePos - wektor zawierajacy wspolrzedne, w ktorych rysowany bedzie ksztalt obiektu na mapie
	  */
	Wall(sf::Vector2f shapePos);

	~Wall();

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu obietow Wall w czasie trwanie rozgrywki.
	  */
	virtual void update();

	/**
	  * Metoda odpowiedzialna za renderowanie obiektow Wall w oknie rozgrywki.
	  */
	virtual void render(sf::RenderTarget& target);

	/**
	  * Metoda akceptujaca wzorzec Wizytatora.
	  */
	virtual void accept(Visitor& v) { v.visit(*this); }

private:

	const sf::Vector2f size_ = { 18.f, 18.f };
	const float outline_thickness_size = 1.f;

	sf::RectangleShape shape_;
	/**
	  * Metoda inicjalizujaca ksztalt obiektu Wall.
	  *
	  * @param sf::Vector2f shapePos - wspolrzedne ksztaltu w oknie rozgrywki
	  */
	void initShape(sf::Vector2f shapePos);
};
#endif