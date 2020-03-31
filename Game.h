/**
  * @file Game.h
  * @author Jakub Wrzosek, Maria Skarbek
  * @date 29.11.2019
  */


#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#include "Window.h"
#include "Map.h"
#include "Wall.h"
#include "Player.h"
#include "Display.h"
#include "AbstractGhost.h"
#include "ClydeGhost.h"
#include "PinkyGhost.h"
#include "BlinkyGhost.h"
#include "BFS.h"

/**
  * Klasa odpowiedzialna za scalanie calej rozgrywki. Jej zadaniami jest aktualizacja elementow
  * rozgrywki, wyswietlanie ich oraz reagowanie na syngaly pochadzace z klawiatury.
  */
class Game
{
public:
    Game();
    ~Game();

    /**
      * Metoda przelaczania sie miedzy stanami duszka Clyde
      */
    void handleClydeGameState();

    /**
    * Metoda przelaczania sie miedzy stanami duszka Pinky
    */
    void handlePinkyGameState();

    /**
      * Metoda przelaczania sie miedzy stanami duszka Blinky
      */
    void handleBlinkyGameState();

    /**
    * Metoda odpowiadajaca za sterowanie duszkami
    */
    void handleGhosts();

    /**
      * Metoda odpowiadajaca za reagowanie na sygnaly z klawiatury.
      */
    void handleInput();

    /**
      * Metoda odpowiadajaca za aktualizowanie wszystkich elementow rozgrywki.
      */
    void update();

    /**
      * Metoda odpowiadajaca za renderowanie wszystkich elementow rozgrywki.
      */
    void render();

    /**
     * Metoda odciazajaca na 1ms procesor
     */
    void sleep();

    /**
      * Metoda zwracajaca wskaünik na obiekt reprezentujacy okno rozgrywki w
      * celu umozliwienia rysowania jego obiektow skladowych.
      *
      * @retval Window* wskaznik na okno rozgrywki
      */
    Window* getWindow();

    /**
      * Metoda zwracajaca obiekt reprezentujacy czas.
      *
      * @retval sf::Time obiekt reprezentujacy czas
      */
    sf::Time getElapsed();

    /**
      * Metoda restartujaca zegar.
      */
    void restartClock();

    /**
    * Metoda szukajaca najkrotszej sciezki od indeksu
    * (x1,y1) do (x2,y2)
    *
    * @param int y1,x1 - wspolrzedne indeksu punktu startowego
    * @param int y2,x1 - wspolrzedne indeksu punktu docelowego
    * Odwrocona notacja wspolrzednych wynika z tego, ze
    * w mapie x oznacza nr kolumny w macierzy (czyli y w macierzy)
    */
    void findPath(int y1, int x1, int y2, int x2);

    bool flag_=false;


private:

    Window window_;
    sf::Clock clock_;
    float elapsed_;
    unsigned int counter_;
    Map map_;
    Player player_;
    Display display_;
    ClydeGhost clydeGhost_;
    PinkyGhost pinkyGhost_;
    BlinkyGhost blinkyGhost_;
    BFS bfs_;
};
#endif
