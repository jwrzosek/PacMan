#include "BlinkyGhost.h"

BlinkyGhost::BlinkyGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color) : AbstractGhost(ghostStartPos,map,color)
{
    this->setStartModeFlag(false);
    this->start_route= {{15,15},{15,14},{15,13},{14,13},{13,13},{13,12},{13,11}};
    this->scatter_route= {{13,11},{12,11},{11,11},{10,11},{9,11},{9,12},{9,13},{9,14},{9,15},{9,16},{9,17},{9,18},{9,19},{9,20},{8,20},{7,20},{6,20},{5,20},{4,20},
    {3,20},{2,20},{1,20},{1,21},{1,22},{1,22},{1,23},{2,23},{3,23},{3,24},{3,25},{3,26},{2,26},{1,26},{1,27},{1,28},{1,29},{2,29},{3,29},{4,29},{5,29},{6,29},{7,29},
    {8,29},{9,29},{10,29},{11,29},{12,29},{12,28},{12,27},{12,26},{11,26},{10,26},{9,26},{9,25},{9,24},{9,23},{10,23},{11,23},{12,23},{12,22},{12,21},{12,20},{11,20},
    {10,20},{9,20},{9,19},{9,18},{9,17},{9,16},{9,15},{9,14},{9,13},{9,12},{9,11},{10,11},{11,11},{12,11},{13,11}
    };
}

BlinkyGhost:: ~BlinkyGhost() {}
