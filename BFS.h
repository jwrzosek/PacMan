/**
  * @file BFS.h
  * @author Maria Skarbek
  * @date 31.12.2019
  */


#ifndef BFS_H
#define BFS_H
#define ROW 31
#define COL 28
#include "AbstractGhost.h"
#include "Player.h"
#include <bits/stdc++.h>
#include <queue>
#include <vector>
class AbstractGhost;

/**
  * Klasa reprezentujaca algorytm BFS-Breadth First Search
  * Przeszukiwanie wszerz w labiryncie, aby znalezc najkrotsza sciezke
  * z jednego miejsca na mapie do drugiego
  */

class BFS
{
public:

    /**
      * Konstruktor.
      */
    BFS();
    ~BFS();

    /**
      * Macierz reprezentujaca macierz pola gry w wartosciach 0-1
      * Duszek moze poruszac sie tylko po polach z wartoscia 1
      */
    int matrix[ROW][COL]=
    {
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0 },
        { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0 },
        { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0 },
        { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0 },
        { 0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0 },
        { 0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0 },
        { 0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0 },
        { 0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0 },
        { 1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0 },
        { 0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0 },
        { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0 },
        { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0 },
        { 0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0 },
        { 0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0 },
        { 0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0 },
        { 0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0 },
        { 0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0 },
        { 0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0 },
        { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
    };

    /**
      * Struktura przechowujaca wspolrzedne komorki macierzy
      */
    struct Point
    {
        int x;
        int y;
    };

    /**
      * Metoda ustawiajaca wspolrzedne x i y punktu startowego
      *
      * @param int x, int y - wspolrzedne startowe algorytmu (czyli wspolrzedne duszka)
      */
    void setSourcePointCoordinates(int x, int y);

    /**
      * Metoda ustawiajaca wspolrzedne x i y punktu docelowego
      *
      * @param int x, int y - wspolrzedne celu algorytmu (czyli wspolrzedne PacMana badz innego miejsca na mapie)
      */
    void setDestinationPointCoordinates(int x, int y);

    /**
      * Struktura reprezentujaca wezel w kolejce w algorytmie BFS
      *
      * Point point_ - wspolrzedne wezla
      * int distance_ - odleglosc komorki od punktu startowego
      * Point parent_ - poprzednik wezla na sciezce
      */
    struct queueNode
    {
        Point point_;
        int distance_;
        Point parent_;
    };

    /**
      * Aktualny wezel algorytmu
      */
    queueNode current_node;

    /**
      * Punkt startowy algorytmu
      */
    Point source_;

    /**
      * Punkt celu algorytmu
      */
    Point destination_;

    /**
    * Wektor przechowujacy wezly sciezki , ale w odwrotnej kolejnosci (od punktu celu do punktu startu)
    */
    std::vector<queueNode> chase_route_backward;

    /**
    * Wektor par typu int zawierajacy sciezke od punktu startowego do docelowego
    */
    std::vector <std::pair<int, int>> chase_route;

    /**
    * Metoda zwracajaca wektor par typu int przechowujacy sciezke od punktu startowego do punktu docelowego
    *
    * @retval std::vector <std::pair<int, int>> chase_route
    */
    std::vector <std::pair<int, int>> getChaseRoute();

    //void printPath();

    /**
    * Metoda wyswietlajaca kolejne punkty sciezki chase_route
    */
    void printPath();

    /**
    * Metoda wypelniajaca wektor chase_route wartosciami wspolrzednych sciezki
    */
    void fillChaseRoute();

    /**
    * Metoda czyszczaca wektor (przydatne przy wielokrotnym wywolaniu algorytmu BFS)
    */
    void setChaseRouteClear();

    /**
    * Metoda sprawdza, czy wiersz i kolumna macierzy jest w zakresie
    *
    * @retval bool wartosc logiczna wyrazenia
    */
    bool isValid(int row, int col);

    /**
    * Metoda sprawdza odleglosc miedzy duszkiem, a PacManem po przekatnej
    *
    * @retval bool wartosc logiczna wyrazenia
    */
    bool isDistance(AbstractGhost ag,Player player);

    /**
    * Tablica typu int przechowujaca wartosci wierszy sasiadow komorki (potrzebne do algorytmu BFS)
    */
    int rowNum[4] = {-1, 0, 0, 1};

    /**
    * Tablica typu int przechowujaca wartosci kolumn sasiadow komorki (potrzebne do algorytmu BFS)
    */
    int colNum[4] = {0, -1, 1, 0};


    /**
    * Metoda wykonujaca algorytm BFS
    *
    * @retval int curr.dist - dystans od punktu docelowego do punktu startowego algorytmu
    * badz -1 jesli dana sciezka nie istnieje (co zdarza sie, jesli sa podane zle wartosci punktu startu i celu)
    */
    int BFSAL();

    /**
    * Metoda szukajaca najkrotszej sciezki dla podanych wspolrzednych wejsciowych
    * Metoda najpierw ustawia wartosci punktow startu i docelowego, a potem wywoluje metode BFSAL
    *
    * @param int x1, int y1 - wspolrzedne startowe algorytmu
    * @param int x2, int y2 - wspolrzedne docelowe algorytmu
    */
    void findShortestPath(int x1,int y1,int x2, int y2);

    int end_distance;

};

#endif // BFS_H
