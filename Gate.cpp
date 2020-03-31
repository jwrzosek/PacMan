#include "Gate.h"

Gate::Gate()
{
	this->initShape({ 0.f, 0.f });
}

Gate::Gate(sf::Vector2f shapePos)
{
	this->initShape(shapePos);
}

Gate::~Gate()
{
}

void Gate::update()
{
}

void Gate::render(sf::RenderTarget& target)
{
	target.draw(this->shape_);
}

void Gate::initShape(sf::Vector2f shapePos)
{
	this->shape_.setFillColor(sf::Color::Black);
	this->shape_.setOutlineThickness(this->outline_thickness_size);
	this->shape_.setOutlineColor(sf::Color::Magenta);
	this->shape_.setSize(this->size_);
	this->shape_.setPosition(shapePos);
}
