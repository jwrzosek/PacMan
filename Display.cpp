#include "Display.h"

Display::Display()
{
	this->initFonts();
	this->initText();
	this->initTexture();
	this->initSprite(this->life_sprite[0], this->sprites_start_pos[0]);
	this->initSprite(this->life_sprite[1], this->sprites_start_pos[1]);
	this->initSprite(this->life_sprite[2], this->sprites_start_pos[2]);
}

Display::~Display()
{
}

void Display::update(int score, int lives)
{
	this->lives_left = lives;

	std::stringstream text;

	text << "Punkty: " << score << "\n";

	this->ui_text.setString(text.str());
}

void Display::render(sf::RenderWindow& l_window)
{
	l_window.draw(this->ui_text); 
	for (int i = 0; i < this->lives_left; i++) {
		l_window.draw(this->life_sprite[i]);
	}
}

void Display::initTexture()
{
	this->life_texture.loadFromFile("Sprites/1.png");
}

void Display::initSprite(sf::Sprite& sprite, sf::Vector2f position)
{
	
	sprite.setTexture(life_texture);
	sprite.setPosition(position);
	sprite.setOrigin({ sprite.getLocalBounds().width, 0 });
	sprite.setScale({ -0.8f, 0.8f });
}

void Display::initFonts()
{
	if (!this->font_.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::PACMAN::DISPLAY::INITFONTS::Failed to load font!" << std::endl;
	}
}

void Display::initText()
{
	this->ui_text.setFont(this->font_);
	this->ui_text.setPosition(this->text_start_pos);
	this->ui_text.setCharacterSize(this->characters_size);
	this->ui_text.setFillColor(sf::Color::White);
	//this->ui_text.setString("NONE");
}




