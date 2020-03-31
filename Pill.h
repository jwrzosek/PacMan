/**
  * @file Pill.h
  * @author Jakub Wrzosek
  * @date 05.01.2020
  */

#ifndef PILL_H
#define PILL_H

#include "Element.h"
#include "Visitor.h"


/**
  * Klasa reprezentujaca kulki, ktorych zjedzenie jest celem Pac-Mana.
  * Za zjedzenie ka¿dej ze znajduj¹cych siê na mapie kulek gracz otrzymuje 
  * punkty.
  */
class Pill : public Element
{
public:
	Pill();
	Pill(sf::Vector2f shapePos);
	~Pill();

	virtual void update();
	virtual void render(sf::RenderTarget& target);
	virtual void accept(Visitor& v) { v.visit(*this); }

	void setVisited();
	bool getVisited();

private:
	const float size_ = 4.f;
	const float shape_shift = 6.f;
	bool visited_;

	sf::CircleShape shape_;
	void initShape(sf::Vector2f shapePos);
};

#endif // PILL_H