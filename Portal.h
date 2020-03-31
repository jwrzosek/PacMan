/**
  * @file Portal.h
  * @author Jakub Wrzosek
  * @date 05.01.2020
  */


#ifndef PORTAL_H
#define PORTAL_H

#include "Element.h"
#include "Visitor.h"

/**
  * Klasa reprezentujaca portal. Na mapie rozgrywki wystepuja dwa obiekty
  * typu Portal. Kolizja, z ktorymkolwiek znich przenosi Pacmana w miejsce 
  * drugiego.
  */
class Portal : public Element
{
public:

	Portal();

	Portal(sf::Vector2f shapePos);

	~Portal();

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

private:
	const sf::Vector2f size_ = { 18.f, 18.f };
	const float outline_thickness_size = 1.f;

	sf::RectangleShape shape_;
	/**
	  * Metoda inicjalizujaca ksztalt obiektu Portal.
	  *
	  * @param sf::Vector2f shapePos - wspolrzedne ksztaltu w oknie rozgrywki
	  */
	void initShape(sf::Vector2f shapePos);
};

#endif // PORTAL_H