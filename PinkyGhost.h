/**
  * @file PinkyGhost.h
  * @author Maria Skarbek
  * @date 28.12.2019
  */

#ifndef PINKYGHOST_H_INCLUDED
#define PINKYGHOST_H_INCLUDED
#include "AbstractGhost.h"

/**
  * Klasa pochodna po klasie AbstractGhost reprezentujaca duszka Pinky
  */

class PinkyGhost : public AbstractGhost
{
public:
PinkyGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color);
~PinkyGhost();
};

#endif // PINKYGHOST_H_INCLUDED
