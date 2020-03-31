/**
  * @file Display.h
  * @author Jakub Wrzosek
  * @date 11.01.2020
  */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <sstream>

/**
  * Klasa odpowiedzialna za wyswietlanie punktow oraz zyc Pacmana.
  */
class Display
{
public:
	Display();
	~Display();

	/**
	  * Metoda odpowiedzialna za aktualizowanie stanu obietow Display w czasie trwanie rozgrywki.
	  *
	  * @param int score - punkty gracza do wyswietlenia w oknie rozgrywki
	  * @param int lives - ¿ycia gracza do wyswietlenia w oknie rozgrywki
	  */
	void update(int score, int lives);

	/**
	  * Metoda odpowiedzialna za renderowanie obiektow Ball w oknie rozgrywki.
	  *
	  * @param sf::RenderWindow& l_window - referencja do skladowej reprezentujacej okno rozgrywki
	  */
	void render(sf::RenderWindow& l_window);

private:
	sf::Font font_;
	sf::Text ui_text;
	sf::CircleShape shape_;
	const sf::Vector2f text_start_pos = { 10, 10 };
	const sf::Vector2f sprites_start_pos[3] = { { 10, 50 }, { 40, 50 }, { 70, 50 } };
	const float shapes_size = 10;
	const int characters_size = 24;

	sf::Texture life_texture;
	sf::Sprite life_sprite[3];
	int lives_left;
	
	/**
	  * Metoda inicjalizujaca teksture potrzebna do wyswietlenia zyc Pacmana.
	  */
	void initTexture();

	/**
	  * Metoda odpowiedzialna za inicjowanie obiektu Sprite zawierajacaego teksture,
	  * który bedzie uzyty do reprezentowania zycia Pacmana.
	  *
	  * @param sf::Sprite& sprite - referencja do skladowej life_sprite
	  * @param sf::Vector2f position - wspolrzedne, w ktorych zostanie wyswietlona tekstura
	  */
	void initSprite(sf::Sprite& sprite, sf::Vector2f position);

	/**
	  * Metoda inicjalizujaca czcionke.
	  */
	void initFonts();

	/**
	  * Metoda inicjalizujaca skladowa ui_text.
	  */
	void initText();
};

#endif // DISPLAY_H