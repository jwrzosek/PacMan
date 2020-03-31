/**
  * @file ClydeGhost.h
  * @author Maria Skarbek
  * @date 28.12.2019
  */

#ifndef CLYDEGHOST_H_INCLUDED
#define CLYDEGHOST_H_INCLUDED
#include "AbstractGhost.h"

/**
  * Klasa pochodna po klasie AbstractGhost reprezentujaca duszka Clyde
  */

class ClydeGhost : public AbstractGhost
{
public:
ClydeGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color);
~ClydeGhost();
};


#endif // CLYDEGHOST_H_INCLUDED
