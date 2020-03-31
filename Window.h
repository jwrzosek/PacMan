/**
  * @file Window.h
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */


#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
  * Klasa reprezentujaca okno rozgrywki.
  */
class Window {
public:

	Window();

	/**
	  * Konstruktor.
	  *
	  * @param const std::string& title - referencja na zmienna typu string zawierajaca tytul okna
	  * @param const sf::Vector2u& size - referencja na wektor zawierajacy rozmiar okna
	  */
	Window(const std::string& title, const sf::Vector2u& size);

	~Window();

	/**
	  * Metoda czyszczaca okno przed rysowaniem jego elementow.
	  */
	void beginDraw();

	/**
	  * Metoda wyswietlajaca elementy okna po ich narysowaniu.
	  */
	void endDraw();

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu oiektu Window.
	  */
	void update();

	/**
	  * Metoda zwracajaca flage mowiaca o tym czy nalezy zakmknac okno.
	  *
	  * @retval bool flaga oznaczajaca gotowosc okna do zamkniecia
	  */
	bool isDone();

	/**
	  * Metoda zwracajaca wskaznik na obiekt reprezentujacy miejsce, w ktorym nastepuje
	  * renderowanie elementow.
	  *
	  * @retval sf::RenderWindow* wskaznik okno do renderowania elementow
	  */
	sf::RenderWindow* getRenderWindow();

	/**
	  * Metoda zwracajaca rozmiar okna.
	  *
	  * @retval sf::Vector2u wektor zawierajacy rozmiar okna
	  */
	sf::Vector2u getWindowSize();

	/**
	  * Metoda ustawiajaca flage oznaczajaca gotowosc okna do zamkniecia
	  *
	  * @param bool isDone - wartosc ktora przyjmie skladowa obiektu Window is_done
	  */
	void setIsDone(bool isDone);

	/**
	  * Metoda odpowiedzialna za rysowanie w oknie obiektow Drawable.
	  *
	  * sf::Drawable& l_drawable - referencja na obiekt typu Drawable
	  */
	void draw(sf::Drawable& l_drawable);

private:

	/**
	  * Metoda definiujaca okno.
	  * @param const std::string title - string zawierajacy tytul okna
	  * @param const sf::Vector2u& size - wektor zawierajacy rozmiar okna
	  */
	void setup(const std::string title, const sf::Vector2u& size);
	
	/**
	  * Metoda tworzaca okno.
	  */
	void create();
	
	/**
	  * Metoda zamykajaca okno.
	  */
	void destroy();

	sf::RenderWindow window_;
	sf::Vector2u window_size;
	std::string window_title;
	bool is_done;
};
#endif