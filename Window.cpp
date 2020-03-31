#include "Window.h"

Window::Window()
{
	setup("Window", sf::Vector2u(800, 600)); 
}
Window::Window(const std::string& title, const sf::Vector2u& size) 
{ 
	setup(title, size); 
}
Window::~Window()
{
	destroy();
}

void Window::setup(const std::string title, const sf::Vector2u& size) 
{
	window_title = title;
	window_size = size;
	is_done = false;
	window_.setFramerateLimit(60);
	create();
}

void Window::create() 
{
	window_.create({ window_size.x, window_size.y, 32 }, window_title, sf::Style::Default);
}

void Window::destroy() 
{
	window_.close();
}

void Window::beginDraw()
{ 
	window_.clear(sf::Color::Black);
}
void Window::endDraw() 
{
	window_.display();
}

bool Window::isDone() { return is_done; }

sf::RenderWindow* Window::getRenderWindow()
{
	return &window_;
}

void Window::draw(sf::Drawable& l_drawable) 
{
	window_.draw(l_drawable);
}

sf::Vector2u Window::getWindowSize() { return window_size; }

void Window::setIsDone(bool isDone)
{
	this->is_done = isDone;
}

void Window::update() 
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) 
		{
			is_done = true; 
		}
	}
}
