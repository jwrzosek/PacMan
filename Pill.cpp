#include "Pill.h"

Pill::Pill()
{
	this->initShape({ 0.f, 0.f });
}

Pill::Pill(sf::Vector2f shapePos)
{
	this->initShape(shapePos);
}

Pill::~Pill()
{
}

void Pill::update()
{
}

void Pill::render(sf::RenderTarget& target)
{
	if (!this->visited_) {
		target.draw(this->shape_);
	}
		
}

void Pill::setVisited()
{
	this->shape_.setFillColor(sf::Color::Black); 
	this->visited_ = true;
}

bool Pill::getVisited()
{
	return this->visited_;
}

void Pill::initShape(sf::Vector2f shapePos)
{
	this->visited_ = false;
	sf::Vector2f shifted_shape_pos = { (shapePos.x + this->shape_shift), (shapePos.y + this->shape_shift) };
	this->shape_.setFillColor(sf::Color::Yellow);
	this->shape_.setRadius(this->size_);
	this->shape_.setPosition(shifted_shape_pos);
}
