/**
  * @file Ball.h
  * @author Jakub Wrzosek
  * @date 05.01.2020
  */

#ifndef BALL_H
#define BALL_H

#include "Element.h"
#include "Visitor.h"

/**
  * Klasa reprezentujaca bonusowe kule, ktorych zjedzenie pozwala Pac-Manowi wejsc
  * w tryb, w ktorym moze polowac na duchy.
  */
class Ball : public Element
{
public:

	Ball();

	/**
	  * Konstruktor.
	  *
	  * @param sf::Vector2f shapePos - wektor zawierajacy wspolrzedne, w ktorych rysowany bedzie ksztalt obiektu na mapie
	  */
	Ball(sf::Vector2f shapePos);

	~Ball();

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu obietow Ball w czasie trwanie rozgrywki.
	  */
	virtual void update();

	/**
	  * Metoda odpowiedzialna za renderowanie obiektow Ball w oknie rozgrywki.
	  */
	virtual void render(sf::RenderTarget& target);

	/**
	  * Metoda akceptujaca wzorzec Wizytatora.
	  */
	virtual void accept(Visitor& v) { v.visit(*this); }

	/**
	  * Metoda odpowiedzialna za ustawienie flagi oznaczajacej, ze dane pole Ball zostalo juz odwiedzone.
	  */
	void setVisited();

	/**
	  * Metoda umozliwiajaca sprawdzenie czy dane pole Ball zostalo odwiedzone.
	  *
	  * @retval bool flaga zawierajaca informacje czy obiekt reprezentujacy pole na mapie zostal odwiedzony
	  */
	bool getVisited();

private:
	const float size_ = 8.f;
	const float shape_shift = 2.f;
	bool visited_;

	sf::CircleShape shape_;
	/**
	  * Metoda inicjalizujaca ksztalt obiektu Ball.
	  *
	  * @param sf::Vector2f shapePos - wspolrzedne ksztaltu w oknie rozgrywki
	  */
	void initShape(sf::Vector2f shapePos);
};

#endif //BALL_H