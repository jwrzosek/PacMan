/**
  * @file AbstractGhost.h
  * @author Maria Skarbek
  * @date 28.12.2019
  */

#ifndef ABSTRACTGHOST_H_INCLUDED
#define ABSTRACTGHOST_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Map.h"
#include "types.h"
#include "Window.h"
#include "BFS.h"
#include "CollisionVisitor.h"

/**
  * Klasa bazowa reprezentujaca abstrakcyjnego duszka
  * KLasy reprentujce duszki : ClydeGhost, PinkyGhost oraz BlinkyGhost to klasy
  * pochodne po tej klasie
  */

class AbstractGhost
{
public:
    /**
      * Konstruktor.
      *
      * @param sf::Vector2f ghostStartPos - wspolrzedne poczatkowe duszka
      * @param Map& map - referencja do obiektu reprezentujacego mape, po ktorej porusza sie duszek
      */
    AbstractGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color);

    /**
    * Destruktor wirtualny
    */
    virtual ~AbstractGhost ();

    /**
      * Metoda ustawiajaca kierunek poruszania sie duszka
      *
      * @param Direction dir - element enum class reprezentujacy kierunek poruszania duszka
      */
    void setDirection(Direction dir);

    /**
    * Metoda zwracajaca aktualny kierunek poruszania sie duszka
    *
    * @retval Direction element enum class reprezentujacy kierunek poruszania duszka
    */
    Direction getDirection();

    /**
    * Metoda w zaleznosci gdzie znajduje sie dany indeks,
    * zmienia kierunek na taki, ktory skieruje nas do danego indeksu
    * @param int x, int y - wspolrzedne indeksu,
    * do ktorego przemiescic sie ma duszek
    */
    void transferPointToDirection(int x, int y);

    /**
    * Metoda zwracajaca wielkosc duszka
    *
    * @retval float size
    */
    float getSize();

    /**
    * Metoda zwracajaca licznik czasu gonienia PacMana przez duszka
    *
    * @retval float chase_mode_time
    */
    float getChaseTime();

    /**
    * Metoda zwracajaca flage trybu startMode
    *
    * @retval bool start_mode
    */
    bool getStartModeFlag();

    /**
    * Metoda zwracajaca flage trybu scatterMode
    *
    * @retval bool scatter_mode
    */
    bool getScatterModeFlag();

    /**
    * Metoda zwracajaca flage trybu chaseMode
    *
    * @retval bool chase_mode
    */
    bool getChaseModeFlag();

    /**
    * Metoda zwracajaca flage trybu inBetweenMode
    *
    * @retval bool in_between_mode
    */
    bool getInBetweenFlag();

    /**
    * Metoda zwracajaca flage sciezki, po ktorej porusza sie duszek
    *
    * @retval bool route_flag
    */
    bool getRouteFlag();

    /**
    * Flaga gonienia PacMana
    */
    bool stopChasing_=true;

    /**
    * Flaga stopu
    */
    bool stop_=false;

    /**
      * Metoda ustawiajaca czas gonienia przez duszka
      *
      * @param float time - czas
      */
    void setChaseModeTime(float time);

    /**
    * Metoda do odmierzania czasu gonienia gonienia przez duszka
    */
    void substractChaseModeTime();

    /**
      * Metoda ustawiajaca flage trybu startu duszka
      *
      * @param bool flag - flaga trybu startu duszka
      */
    void setStartModeFlag(bool flag);

    /**
    * Metoda ustawiajaca flage rozproszenia po planszy duszka
    *
    * @param bool flag - flaga trybu rozproszenia duszka
    */
    void setScatterModeFlag(bool flag);

    /**
    * Metoda ustawiajaca flage trybu gonienia PacMana przez duszka po planszy
    *
    * @param bool flag - flaga trybu gonienia PacMana przez duszka
    */
    void setChaseModeFlag(bool flag);

    /**
    * Metoda ustawiajaca flage trybu pomiedzy innymi trybami
    *
    * @param bool flag - flaga trybu pomiedzy duszka
    */
    void setInBetweenFlag(bool flag);

    /**
    * Metoda ustawiajaca flage sciezki, po ktorej porusza sie duszek
    *
    * @param bool flag - flaga sciezki, po ktorej porusza sie duszek
    */
    void setRouteFlag(bool flag);

    /**
    * Tryb startu z miejsca startowego duszka
    */
    void startMode();

    /**
    * Tryb rozproszenia duszka
    */
    void scatterMode();

    /**
    * Tryb gonienia PacMana przez duszka
    *
    * @param std::vector <std::pair<int, int>> chaseRoute_ - wektor par
    * liczb typu int zawierajacy wspolrzedne y i x mapy kolejnych indeksow sciezki
    * po ktorej duszek ma sie kierowac, aby dotrzec do PacMana
    */
    void chaseMode(std::vector <std::pair<int, int>> chaseRoute_);

    /**
    * Tryb powracania do trybu rozproszenia tzw. tryb pomiedzy
    *
    * @param std::vector <std::pair<int, int>> chaseRoute_ - wektor par
    * liczb typu int zawierajacy wspolrzedne y i x mapy kolejnych indeksow sciezki
    * po ktorej duszek ma sie kierowac, aby dotrzec do poczatku sciezki trybu rozproszenia
    */
    void inBetweenMode(std::vector <std::pair<int, int>> chaseRoute_);

    /**
    * Wektor par typu int ze sciezka startowa duszka
    * Kazdy duszek ma inna trase wyjscia z pozycji startowej na plansze
    */
    std::vector< std::pair<int, int>> start_route;

    /**
    * Wektor par typu int ze sciezka rozproszenia duszka
    * Kazdy duszek ma inna trase rozproszenia po mapie
    */
    std::vector <std::pair<int, int>> scatter_route;

    /**
    * Iterator po wektorze par typu int
    * przechowuje pare wspolrzednych x i y
    * indeksu na ktorym znajduje sie duszek
    */
    std::vector <std::pair<int, int>>::iterator item_;

    /**
    * Metoda zwracajaca wektor licznika krokow duszka
    *
    * @retval sf::Vector2i ghost_steps_counter
    */
    sf::Vector2i getGhostStepsCounter();

    /**
    * Metoda zwracajaca wektor z pozycja startowa duszka
    *
    * @retval sf::Vector2f start_position
    */
    sf::Vector2f getGhostStartPosition();

    /**
    * Metoda zwracajaca wektor aktualnej pozycji duszka
    *
    * @retval sf::Vector2f current_position
    */
    sf::Vector2f getGhostCurrentPosition();

    /**
    * Metoda zwracajaca wektor aktualnego indeksu duszka
    *
    * @retval sf::Vector2i current_index
    */
    sf::Vector2i getGhostCurrentIndex();

    /**
    * Metoda zwracajaca ksztalt obiektu sf::CircleShape
    *
    * @retval sf::CircleShape shape
    */
    sf::CircleShape getShape();

    /**
    * Metoda odpowiedzialna za uaktualnianie polozenia poruszajacego sie duszka
    */
    void move();

    /**
    * Metoda wywolujaca funkcje transferPointToDirection
    *
    * @param int x, int y - wspoldzedne indeksu,
    * do ktorego przemiescic sie ma duszek
    */
    void changePosition(int x,int y);

    /**
    * Metoda odpowiedzialna za aktualizowanie stanu obietow duszkow w czasie trwanie rozgrywki.
    *
    * @param sf::RenderWindow& l_window - referencja na obiekt reprezentujacy okno, po ktorym porusza sie duszek
    */
    void update(Map& map);

    /**
    * Metoda renderujaca duszka w oknie gry
    */
    void render(sf::RenderWindow& l_window);

    /**
    * Metoda renderujaca duszka w oknie gry na pozycji startowej
    * po dogonieniu przez niego PacMana
    * @param sf::RenderWindow& l_window - referencja na obiekt reprezentujacy okno, po ktorym porusza sie duszek
    */
    void renderOnStartPosition(sf::RenderWindow& l_window);

    /**
    * Zmienna przechowujaca licznik wektora sciezki, po ktorej aktualnie porusza sie duszek
    */
    unsigned int route_counter;

private:
    void checkCollision(Map& map);

    sf::Vector2f ghost_start_position;
    sf::Vector2f ghost_current_position;
    sf::Vector2i ghost_current_index;
    sf::Vector2i ghost_steps_counter;

    sf::CircleShape shape;
    void initShape(sf::Color color);

    bool scatter_mode;
    bool start_mode;
    bool chase_mode;
    bool in_between_mode;
    bool route_flag;
    float chase_mode_time;
    const float size = 10.f;

    Direction dir_;
    Direction nextDir_;
};


#endif // ABSTRACTGHOST_H_INCLUDED
