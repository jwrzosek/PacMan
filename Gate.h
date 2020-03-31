/**
  * @file Gate.h
  * @author Jakub Wrzosek
  * @date 05.01.2020
  */
#ifndef GATE_H
#define GATE_H

#include "Element.h"
#include "Visitor.h"

/**
  * Klasa reprezentujaca obiekty wchodzace w sklad bramy do miejsca,
  * z ktorego odradzaja sie duchy. Dla Pac-Mana stanowi taka sama 
  * przeszkode jak zwykla sciana.
  */
class Gate : public Element
{
public:

	Gate();

	/**
	  * Konstruktor.
	  *
	  * @param sf::Vector2f shapePos - wektor zawierajacy wspolrzedne, w ktorych rysowany bedzie ksztalt obiektu na mapie
	  */
	Gate(sf::Vector2f shapePos);

	~Gate();

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu obietow Gate w czasie trwanie rozgrywki.
	  */
	virtual void update();

	/**
	  * Metoda odpowiedzialna za renderowanie obiektow Gate w oknie rozgrywki.
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
	  * Metoda inicjalizujaca ksztalt obiektu Gate.
	  *
	  * @param sf::Vector2f shapePos - wspolrzedne ksztaltu w oknie rozgrywki
	  */
	void initShape(sf::Vector2f shapePos);
};

#endif // GATE_H