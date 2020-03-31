#include "Player.h"
#include "CollisionVisitor.h"
#include <iostream>

Player::Player(sf::Vector2f startPos, Map& map)
{
	this->start_position = startPos;
	this->current_position = start_position;
	this->speed_ = 100;
	this->score_ = 0;
	this->lives_ = 3;
	this->current_index = {
		(static_cast<int>((current_position.x / 20) - map.getMapStartPosition().x)),
		(static_cast<int>((current_position.y / 20) - map.getMapStartPosition().y)) };
	this->dir_ = Direction::None;
	this->nextDir_ = Direction::None;
	this->steps_counter = { 0, 0 };
	this->initShape();
}

Player::~Player() { }

void Player::setDirection(Direction dir)
{
	//this->dir_ = dir;
	this->nextDir_ = dir;
}

Direction Player::getDirection()
{
	return this->dir_;
}

int Player::getSpeed()
{
	return this->speed_;
}

int Player::getLives()
{
	return this->lives_;
}

int Player::getScore()
{
	return this->score_;
}

sf::Vector2i Player::getCurrentIndex()
{
    return this->current_index;
}

void Player::setLives(int lives)
{
	this->lives_ = lives;
}

void Player::setScore(int score)
{
	this->score_ = score;
}

sf::Vector2i Player::getStepsCounter()
{
	return this->steps_counter;
}

void Player::increaseScore()
{
	this->score_ += 10;
}

void Player::move()
{
	if (dir_ == Direction::Left) {
		--this->current_position.x;
	}
	else if (dir_ == Direction::Right) {
		++this->current_position.x;
	}
	else if (dir_ == Direction::Up) {
		--this->current_position.y;
	}
	else if (dir_ == Direction::Down) {
		++this->current_position.y;
	}
}

void Player::update(Map& map)
{
	this->current_index.x = static_cast<int>((current_position.x - map.getMapStartPosition().x) / 20);
	this->current_index.y = static_cast<int>((current_position.y - map.getMapStartPosition().y) / 20);

	if (this->steps_counter.x % 20 == 0 && this->steps_counter.y % 20 == 0) {
		if (dir_ != nextDir_)
			dir_ = nextDir_;
		this->checkCollisionn(map);
	}

	if (this->dir_ == Direction::None)
		return;
	else if (steps_counter.x < 20 && (this->dir_ == Direction::Left || this->dir_ == Direction::Right)) {
		this->move();
		steps_counter.x++;
	}
	else if (steps_counter.y < 20 && (this->dir_ == Direction::Up || this->dir_ == Direction::Down)) {
		this->move();
		steps_counter.y++;
	}
	else {
		steps_counter = {0, 0};
		//this->dir_ = Direction::None;
	}
}

void Player::render(sf::RenderWindow& l_window)
{
	this->shape_.setPosition(this->current_position);
	//std::cout << "pos: " << currentPosition_.x << " " << currentPosition_.y << std::endl;
	//std::cout << "x: " << currentIndex_.x << " y:" << currentIndex_.y << std::endl;
	l_window.draw(this->shape_);
}

void Player::renderOnStartPosition(sf::RenderWindow& l_window)
{
    this->setDirection(Direction::None);
    this->shape_.setFillColor(sf::Color::Black);
	this->current_position.x=this->start_position.x;
	this->current_position.y=this->start_position.y;
	this->current_index.x = static_cast<int>((current_position.x - 120.f) / 20);
	this->current_index.y = static_cast<int>((current_position.y - 40.f) / 20);
	this->shape_.setPosition(this->start_position);
	this->shape_.setFillColor(sf::Color::Yellow);
	l_window.draw(this->shape_);
}

// stara wersja
//void Player::checkCollision(Map& map)
//{
//	if (dir_ == Direction::Left && map.getFieldOnIndex(currentIndex_.x - 1, currentIndex_.y) == W) {
//		this->dir_ = Direction::None;
//		this->nextDir_ = Direction::None;
//	}
//	else if (dir_ == Direction::Right && map.getFieldOnIndex(currentIndex_.x + 1, currentIndex_.y) == W) {
//		this->dir_ = Direction::None;
//		this->nextDir_ = Direction::None;
//	}
//	else if (dir_ == Direction::Up && map.getFieldOnIndex(currentIndex_.x, currentIndex_.y - 1) == W) {
//		this->dir_ = Direction::None;
//		this->nextDir_ = Direction::None;
//	}
//	else if (dir_ == Direction::Down && map.getFieldOnIndex(currentIndex_.x, currentIndex_.y + 1) == W) {
//		this->dir_ = Direction::None;
//		this->nextDir_ = Direction::None;
//	}
//}

void Player::checkCollisionn(Map& map)
{
	CollisionVisitor collision_visitor(dir_);
	sf::Vector2i next_index = this->current_index;

	if (dir_ == Direction::Left)
		next_index.x--;
	else if (dir_ == Direction::Right)
		next_index.x++;
	else if (dir_ == Direction::Up)
		next_index.y--;
	else if (dir_ == Direction::Down)
		next_index.y++;

	//std::cout << "current x: " << currentIndex_.x << " y:" << currentIndex_.y << std::endl;
	//std::cout << "next    x: " << next_index.x << " y:" << next_index.y << std::endl;
	if(map.getObjectOnIndex(next_index.x, next_index.y) != NULL)
		map.getObjectOnIndex(next_index.x, next_index.y)->accept(collision_visitor);

	this->dir_ = collision_visitor.getDirection();
	this->nextDir_ = collision_visitor.getDirection();

	if (collision_visitor.isPill()) {
		this->score_++;
		//std::cout << "score++\n";
	}
	else if (collision_visitor.isPortal()) {
		if (this->current_index.x > 3)
			this->current_position.x -= collision_visitor.getPortalPositionChange();
		else
			this->current_position.x += collision_visitor.getPortalPositionChange();
	}
	else if (collision_visitor.isBall()) {
		this->lives_--;
		//std::cout << "lives--\n";
		this->current_position = map.getPlayerStartPosition();
		this->nextDir_ = Direction::None;
	}
}


void Player::initShape()
{
	this->shape_.setFillColor(sf::Color::Yellow);
	this->shape_.setRadius(this->size_);
	this->shape_.setPosition(this->start_position);
}
