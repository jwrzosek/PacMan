/**
  * @file Element.h
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Visitor;

/**
  * Klasa bazowa dla obiektow wchodzacych w sklad mapy rozgrywki.
  */
class Element 
{
public:
	virtual ~Element() {}
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	virtual void accept(Visitor& v) = 0;
private:

};

#endif
