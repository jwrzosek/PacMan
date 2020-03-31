#include "Portal.h"

Portal::Portal()
{
	this->initShape({ 0.f, 0.f });
}

Portal::Portal(sf::Vector2f shapePos)
{
	this->initShape(shapePos);
}

Portal::~Portal()
{
}

void Portal::update()
{
}

void Portal::render(sf::RenderTarget& target)
{
	target.draw(this->shape_);
}

void Portal::initShape(sf::Vector2f shapePos)
{
	this->shape_.setFillColor(sf::Color::Black);
	this->shape_.setOutlineThickness(this->outline_thickness_size);
	this->shape_.setOutlineColor(sf::Color::Cyan);
	this->shape_.setSize(this->size_);
	this->shape_.setPosition(shapePos);
}
