/**
  * @file CollisionVisitor.h
  * @author Jakub Wrzosek
  * @date 03.01.2020
  */

#ifndef COLLISIONVISITOR_H
#define COLLISIONVISITOR_H

#include "Visitor.h"
#include "Element.h"
#include "Wall.h"
#include "Pill.h"
#include "Ball.h"
#include "types.h"
#include <iostream>


/**
  * Klasa konkretnego wizytatora, ktorej zadaniem jest sprawdzanie kolizji pomiedzy PacMan-em,
  * a obiektami tworzacymi mape.
  */
class CollisionVisitor : public Visitor
{
public:
	/**
	  * Konstruktor CollisionVisitor-a.
	  *
	  * @param Direction dir element enum class Direction reprezentujacy kierunek PacMana w momencie sprawdzania kolizjii
      */
	CollisionVisitor(Direction dir) : dir_after_collision(dir) {}

	virtual void visit(Wall& w) { 
		dir_after_collision = Direction::None; 
	}

	/**
	  * Zadaniem metody jest reagowanie na kolizje z obiektem klasy Pill.
      */
	virtual void visit(Pill& p) {
		if (!p.getVisited())
		{
			p.setVisited();
			this->is_pill = true;
		}			
	}

	/**
	  * Zadaniem metody jest reagowanie na kolizje z obiektem klasy Ball.
	  */
	virtual void visit(Ball& b) { 
		if (!b.getVisited())
		{
			b.setVisited();
			this->is_ball = true;
		}
	}

	/**
	  * Zadaniem metody jest reagowanie na kolizje z obiektem klasy Gate.
	  */
	virtual void visit(Gate& g) { 
		dir_after_collision = Direction::None;
	}

	/**
	  * Zadaniem metody jest reagowanie na kolizje z obiektem klasy Portal.
	  */
	virtual void visit(Portal& b) { 
		this->is_portal = true; 
	}

	/**
	  * Metoda zwracajaca kierunek poruszania sie PacMana. Jej wartosc zalezy od rodzaju obiektu 
	  * z ktorym nastapila kolizja.
	  *
	  * @retval Direction kierunek ruchu PacMana po sprawdzanej kolizji.
	  */
	Direction getDirection() { 
		return this->dir_after_collision; 
	}

	/**
	  * Metoda zwracajaca zmiane wspolrzednych PacMana w wypadku kolizji z obiektem Portal.
	  *
	  * @retval const float wartosc, o ktora zmienia sie pozycja PacMana na osi X po kolizji z obiektem Portal.
	  */
	const float getPortalPositionChange() { 
		this->is_portal = false; 
		return this->portal_position_change; 
	}

	/**
	  * Metoda zwracajaca flage synalizujaca kolizje z obiektem Portal, w celu przedsiewziecia
	  * odpowiednich modyfikacji stanu rozgrywki (zmiana wspolrzednych na osi X).
	  *
	  * @retval bool flaga zawierajaca informacje czy nastapila kolizja z obiektem Portal.
	  */
	bool isPortal() { 
		return this->is_portal; 
	}

	/**
	  * Metoda zwracajaca flage synalizujaca kolizje z obiektem Pill, w celu przedsiewziecia
	  * odpowiednich modyfikacji stanu rozgrywki (dodanie punktow).
	  *
	  * @retval bool flaga zawierajaca informacje czy nastapila kolizja z obiektem Pill.
	  */
	bool isPill() {
		if (is_pill) {
			is_pill = false;
			return true;
		}
		else {
			return false;
		}			
	}

	/**
	  * Metoda zwracajaca flage synalizujaca kolizje z obiektem Ball, w celu przedsiewziecia
	  * odpowiednich modyfikacji stanu rozgrywki (zmiana zachowania duchow).
	  *
	  * @retval bool flaga zawierajaca informacje czy nastapila kolizja z obiektem Ball.
	  */
	bool isBall() {
		if (is_ball) {
			is_ball = false;
			return true;
		}
		else {
			return false;
		}
	}


private:
	Direction dir_after_collision;
	bool is_portal = false;
	bool is_pill = false;
	bool is_ball = false;
	const float portal_position_change = 520.f;
};

#endif // COLLISIONVISITOR_H

