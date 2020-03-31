/**
  * @file types.h
  * @author Jakub Wrzosek
  * @date 29.11.2019
  */


#ifndef TYPES_H
#define TYPES_H


/**
  * Typy zostaly zdefiniowane w celu reprezentowania odpowiednich 
  * elementow planszy.
  * Determinuja one zachowanie Pac-Mana.
  */
typedef enum  
{
	W,	/*!< W: obiekt Wall							*/
	G,	/*!< G: obiekt Gate							*/
	P,	/*!< P: obiekt Portal						*/
	n,	/*!< n: Non-Filled Path						*/
	o,	/*!< o: obiekt Pill							*/
	e,	/*!< e: odwiedzony obiekt Pill				*/
	O,	/*!< O: obiekt Ball							*/
	E,	/*!< E: odwiedzony obiekt Ball				*/
	F	/*!< F: obiekt Fruit (niezaimplementowany)	*/
} Fields;

/**
  * Typy zostaly zdefiniowane w celu reprezentowania odpowiednich
  * kierunkow ruchu Pacmana.
  */
enum class Direction 
{
	None,	/*!< value 1 - Pacman stoi w miejscu							*/
	Up,		/*!< value 2 - Pacman porusza sie w gore planszy po osi Y		*/
	Down,	/*!< value 3 - Pacman porusza sie w dol planszy po osi Y		*/
	Left,	/*!< value 4 - Pacman porusza sie w lewo po osi X				*/
	Right	/*!< value 5 - Pacman porusza sie w prawo po osi X				*/
};

#endif