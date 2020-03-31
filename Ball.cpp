#include "Ball.h"

Ball::Ball()
{
	this->initShape({ 0.f, 0.f });
}

Ball::Ball(sf::Vector2f shapePos)
{
	this->initShape(shapePos);
}

Ball::~Ball()
{
}

void Ball::update()
{
}

void Ball::render(sf::RenderTarget& target)
{
	if (!this->visited_) {
		target.draw(this->shape_);
	}
}

void Ball::setVisited()
{
	this->shape_.setFillColor(sf::Color::Black);
	this->visited_ = true;
}

bool Ball::getVisited()
{
	return this->visited_;
}


void Ball::initShape(sf::Vector2f shapePos)
{
	this->visited_ = false;
	sf::Vector2f shifted_shape_pos = { (shapePos.x + this->shape_shift), (shapePos.y + this->shape_shift) };
	this->shape_.setFillColor(sf::Color::Yellow);
	this->shape_.setRadius(this->size_);
	this->shape_.setPosition(shifted_shape_pos);
}
