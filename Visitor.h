/**
  * @file Visitor.h
  * @author Jakub Wrzosek
  * @date 03.01.2020
  */

#ifndef VISITOR_H
#define VISITOR_H

#include "Element.h"

class Wall;
class Pill;
class Ball;
class Gate;
class Portal;

/**
  * Klasa abstrakcyjna bazowego Wizytatora. 
  */
class Visitor 
{
public:
	virtual ~Visitor() {}
	virtual void visit(Wall&) = 0;
	virtual void visit(Pill&) = 0;
	virtual void visit(Ball&) = 0;
	virtual void visit(Gate&) = 0;
	virtual void visit(Portal&) = 0;
};

#endif // VISITOR_H

