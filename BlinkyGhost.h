/**
  * @file BlinkyGhost.h
  * @author Maria Skarbek
  * @date 28.12.2019
  */

#ifndef BLINKYGHOST_H_INCLUDED
#define BLINKYGHOST_H_INCLUDED
#include "AbstractGhost.h"

/**
  * Klasa pochodna po klasie AbstractGhost reprezentujaca duszka Blinky
  */

class BlinkyGhost : public AbstractGhost
{
public:
BlinkyGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color);
~BlinkyGhost();
};


#endif // BLINKYGHOST_H_INCLUDED
