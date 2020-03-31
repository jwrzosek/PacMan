/**
  * @file Player.h
  * @author Jakub Wrzosek
  * @date 30.11.2019
  */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "types.h"
#include "Map.h"

/**
  * Klasa reprezentujaca Pacmana.
  */
class Player
{
public:

    /**
      * Konstruktor.
      *
      * @param sf::Vector2f startPos - wspolrzedne poczatkowe Pacmana
      * @param Map& map - referencja do obiektu reprezentujacego mape, po ktorej porusza sie Pacman
      */
    Player(sf::Vector2f startPos, Map& map);

    ~Player();

    /**
      * Metoda ustawiajaca kierunek poruszania sie Pacmana.
      *
      * @param Direction dir - element enum class reprezentujacy kierunek poruszania Pacmana
      */
    void setDirection(Direction dir);

    /**
      * Metoda zwracajaca aktualny kierunek poruszania sie Pacmana.
      *
      * @retval Direction element enum class reprezentujacy kierunek poruszania Pacmana
      */
    Direction getDirection();

    /**
      * Metoda zwracajaca predkosc Pacmana.
      *
      * @retval int predkosc Pacmana
      */
    int getSpeed();

    /**
      * Metoda zwracajaca ilosc zyc Pacmana.
      *
      * @retval int pozostale zycia
      */
    int getLives();

    /**
      * Metoda zwracajaca punkty zdobyte przez gracz.
      *
      * @retval int liczba punktow
      */
    int getScore();

    sf::Vector2i getCurrentIndex();

    /**
      * Metoda ustawiajaca liczbe zyc Pacmana.
      *
      * @param int lives - nowa liczba zyc
      */
    void setLives(int lives);

    /**
      * Metoda ustawiajaca liczbe punktow Pacmana.
      *
      * @param int lives - nowa liczba punktow
      */
    void setScore(int score);

    /**
      * Metoda zwracajaca ilosc krokow Pacmana w celu przeliczania polozenia na mapie
      * na indeks w tablicy reprezentujacej elementy mapy.
      *
      * @retval sf::Vector2i liczba krokow na obu osiach
      */
    sf::Vector2i getStepsCounter();

    /**
      * Metoda zwiekszajaca liczbe punktow zdobytych przez gracza.
      */
    void increaseScore();

    /**
      * Metoda odpowiedzialna za uaktualnianie polozenia poruszajacego sie Pacmana
      */
    void move();

    /**
      * Metoda odpowiedzialna za aktualizowanie stanu obietow Player w czasie trwanie rozgrywki.
      *
      * @param Map& map - referencja na obiekt reprezentujacy mape, po ktorej porusza sie Pacman.
      */
    void update(Map& map);

    /**
      * Metoda akceptujaca wzorzec Wizytatora.
      */
    void render(sf::RenderWindow& l_window);

    /**
    * Metoda rysujaca PacMana na pozycji startowej
    */
    void renderOnStartPosition(sf::RenderWindow& l_window);

private:

    /**
      * Metoda odpowiedzialna za sprawdzanie kolizji z elementami mapy.
      *
      * @param Map& map - referencja na obiekt reprezentujacy mape, po ktorej porusza sie Pacman.
      */
    void checkCollisionn(Map& map);

    sf::Vector2f start_position;
    sf::Vector2f current_position;
    sf::Vector2i current_index;
    sf::Vector2i steps_counter;

    sf::CircleShape shape_;
    /**
      * Metoda inicjujaca ksztalt Pacmana.
      */
    void initShape();

    const float size_ = 10.f;
    int speed_;
    int lives_;
    int score_;

    Direction dir_;
    Direction nextDir_;
};

#endif
