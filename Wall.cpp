#include "Wall.h"

Wall::Wall()
{
	this->initShape({0.f, 0.f});
}

Wall::Wall(sf::Vector2f shapePos)
{
	this->initShape(shapePos);
}

Wall::~Wall()
{
}

//const Fields Wall::getField() const
//{
//	return this->field_;
//}

void Wall::update()
{
}

void Wall::render(sf::RenderTarget& target)
{
	target.draw(this->shape_);
}

void Wall::initShape(sf::Vector2f shapePos)
{
	this->shape_.setFillColor(sf::Color::Black);
	this->shape_.setOutlineThickness(this->outline_thickness_size);
	this->shape_.setOutlineColor(sf::Color::Blue);
	this->shape_.setSize(this->size_);
	this->shape_.setPosition(shapePos);
}
