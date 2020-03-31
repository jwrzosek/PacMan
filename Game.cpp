#include "Game.h"

Game::Game() : window_("PacMan", sf::Vector2u(800, 700)), player_(map_.getPlayerStartPosition(), map_),
    clydeGhost_(map_.getGhostClydeStartPosition(),map_,sf::Color(255,165,0,255)), pinkyGhost_(map_.getGhostPinkyStartPosition(),map_,sf::Color::Magenta),
    blinkyGhost_(map_.getGhostBlinkyStartPosition(),map_,sf::Color::Red), bfs_()
{
    restartClock();
    srand(time(NULL));

    // Setting up class members.
}

Game::~Game() { }

sf::Time Game::getElapsed()
{
    return clock_.getElapsedTime();
}
void Game::restartClock()
{
    elapsed_ += clock_.restart().asSeconds();
}
Window* Game::getWindow()
{
    return &window_;
}

void Game::handleClydeGameState()
{
    bool chase_flag=bfs_.isDistance(clydeGhost_,player_);

    if(chase_flag==true && clydeGhost_.getRouteFlag()==false)
    {
        clydeGhost_.substractChaseModeTime();
        //std::cout<<"chase time"<<chaseModeTime_<<std::endl;
        if(clydeGhost_.getChaseTime()>0.0f)
        {
            //std::cout<<"chasee"<<std::endl;
            this->findPath(clydeGhost_.getGhostCurrentIndex().y,clydeGhost_.getGhostCurrentIndex().x,player_.getCurrentIndex().y,player_.getCurrentIndex().x);
            clydeGhost_.setChaseModeFlag(true);
            clydeGhost_.setScatterModeFlag(false);
            clydeGhost_.chaseMode(bfs_.getChaseRoute());
            bfs_.setChaseRouteClear();
        }
        else
        {
            clydeGhost_.setChaseModeTime(30.0f);
            clydeGhost_.setChaseModeFlag(false);
            clydeGhost_.setInBetweenFlag(true);
            clydeGhost_.setRouteFlag(true);
        }
    }

    if(clydeGhost_.getChaseModeFlag()==false && clydeGhost_.getInBetweenFlag()==true && clydeGhost_.getRouteFlag()==true && clydeGhost_.stop_==true)
    {
        //std::cout<<"backmode"<<std::endl;
        this->findPath(clydeGhost_.getGhostCurrentIndex().y,clydeGhost_.getGhostCurrentIndex().x,11,15);
        clydeGhost_.inBetweenMode(bfs_.getChaseRoute());
        bfs_.setChaseRouteClear();
    }

    if(clydeGhost_.getStartModeFlag()==true)
    {
        clydeGhost_.startMode();
    }

    if(clydeGhost_.getScatterModeFlag()==true)
    {
        clydeGhost_.scatterMode();
        if(pinkyGhost_.getStartModeFlag()==false && pinkyGhost_.getScatterModeFlag()==false)
        {
            pinkyGhost_.startMode();
            pinkyGhost_.setStartModeFlag(true);
        }
        else if(pinkyGhost_.getStartModeFlag()==true)
        {
            pinkyGhost_.startMode();
        }
    }
}

void Game::handlePinkyGameState()
{
    bool chase_flag=bfs_.isDistance(pinkyGhost_,player_);

    if(chase_flag==true && pinkyGhost_.getRouteFlag()==false)
    {
        pinkyGhost_.substractChaseModeTime();
        //std::cout<<"chase time"<<chaseModeTime_<<std::endl;
        if(pinkyGhost_.getChaseTime()>0.0f)
        {
            //std::cout<<"chasee"<<std::endl;
            this->findPath(pinkyGhost_.getGhostCurrentIndex().y,pinkyGhost_.getGhostCurrentIndex().x,player_.getCurrentIndex().y,player_.getCurrentIndex().x);
            pinkyGhost_.setChaseModeFlag(true);
            pinkyGhost_.setScatterModeFlag(false);
            pinkyGhost_.chaseMode(bfs_.getChaseRoute());
            bfs_.setChaseRouteClear();
        }
        else
        {
            pinkyGhost_.setChaseModeTime(30.0f);
            pinkyGhost_.setChaseModeFlag(false);
            pinkyGhost_.setInBetweenFlag(true);
            pinkyGhost_.setRouteFlag(true);
        }
    }

    if(pinkyGhost_.getChaseModeFlag()==false && pinkyGhost_.getInBetweenFlag()==true && pinkyGhost_.getRouteFlag()==true && pinkyGhost_.stop_==true)
    {
        //std::cout<<"backmode"<<std::endl;
        this->findPath(pinkyGhost_.getGhostCurrentIndex().y,pinkyGhost_.getGhostCurrentIndex().x,11,12);
        pinkyGhost_.inBetweenMode(bfs_.getChaseRoute());
        bfs_.setChaseRouteClear();
    }


    if(pinkyGhost_.getScatterModeFlag()==true)
    {
        pinkyGhost_.scatterMode();
        if(blinkyGhost_.getStartModeFlag()==false && blinkyGhost_.getScatterModeFlag()==false)
        {
            blinkyGhost_.startMode();
            blinkyGhost_.setStartModeFlag(true);
        }
        else if(blinkyGhost_.getStartModeFlag()==true)
        {
            blinkyGhost_.startMode();
        }
    }
}
void Game::handleBlinkyGameState()
{
    bool chase_flag=bfs_.isDistance(blinkyGhost_,player_);

    if(chase_flag==true && blinkyGhost_.getRouteFlag()==false)
    {
        blinkyGhost_.substractChaseModeTime();
        //std::cout<<"chase time"<<chaseModeTime_<<std::endl;
        if(blinkyGhost_.getChaseTime()>0.0f)
        {
            //std::cout<<"chasee"<<std::endl;
            this->findPath(blinkyGhost_.getGhostCurrentIndex().y,blinkyGhost_.getGhostCurrentIndex().x,player_.getCurrentIndex().y,player_.getCurrentIndex().x);
            blinkyGhost_.setChaseModeFlag(true);
            blinkyGhost_.setScatterModeFlag(false);
            blinkyGhost_.chaseMode(bfs_.getChaseRoute());
            bfs_.setChaseRouteClear();
        }
        else
        {
            blinkyGhost_.setChaseModeTime(30.0f);
            blinkyGhost_.setChaseModeFlag(false);
            blinkyGhost_.setInBetweenFlag(true);
            blinkyGhost_.setRouteFlag(true);
        }
    }

    if(blinkyGhost_.getChaseModeFlag()==false && blinkyGhost_.getInBetweenFlag()==true && blinkyGhost_.getRouteFlag()==true && blinkyGhost_.stop_==true)
    {
        //std::cout<<"backmode"<<std::endl;
        this->findPath(blinkyGhost_.getGhostCurrentIndex().y,blinkyGhost_.getGhostCurrentIndex().x,11,12);
        blinkyGhost_.inBetweenMode(bfs_.getChaseRoute());
        bfs_.setChaseRouteClear();
    }

    if(blinkyGhost_.getScatterModeFlag()==true)
    {
        blinkyGhost_.scatterMode();
    }
}

void Game::handleGhosts()
{
    this->handleClydeGameState();
    this->handlePinkyGameState();
    this->handleBlinkyGameState();
}

void Game::handleInput()
{
    // Input handling.

    if (player_.getStepsCounter().x % 20 == 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player_.setDirection(Direction::Up);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player_.setDirection(Direction::Down);
    }

    if (player_.getStepsCounter().y % 20 == 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player_.setDirection(Direction::Left);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player_.setDirection(Direction::Right);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->window_.setIsDone(true);

}

void Game::update()
{
    window_.update();

    float timestep = 1.0f / player_.getSpeed();
    if (elapsed_ >= timestep)
    {
        player_.update(map_);
        map_.update();
        display_.update(player_.getScore(), player_.getLives());
        clydeGhost_.update(map_);
        pinkyGhost_.update(map_);
        blinkyGhost_.update(map_);

        if (player_.getLives() == 0)
        {
            player_.setLives(3);
            player_.setScore(0);
            map_.initializeMapp();
        }

        elapsed_ -= timestep;
    }


}

void Game::render()
{
    window_.beginDraw(); // Clear.
    // render other stuff
    map_.render(*window_.getRenderWindow());

    if(clydeGhost_.getInBetweenFlag()==true && clydeGhost_.stopChasing_==true)
    {
        if(clydeGhost_.getChaseTime()==30.0f )
        {
            std::cout<<"clyde1"<<std::endl;
            player_.render(*window_.getRenderWindow());
            clydeGhost_.render(*window_.getRenderWindow());
        }

        else
        {
            std::cout<<"clyde2"<<std::endl;
            player_.renderOnStartPosition(*window_.getRenderWindow());
            player_.setLives(player_.getLives()-1);
            clydeGhost_.renderOnStartPosition(*window_.getRenderWindow());
        }
        clydeGhost_.stopChasing_=false;
        clydeGhost_.stop_=true;
        sf::sleep(sf::seconds(0.001));
        //clydeGhost_.setRouteFlag(false);
    }

        else
    {
        player_.render(*window_.getRenderWindow());
        clydeGhost_.render(*window_.getRenderWindow());
        pinkyGhost_.render(*window_.getRenderWindow());
        blinkyGhost_.render(*window_.getRenderWindow());
    }

    if(pinkyGhost_.getInBetweenFlag()==true && pinkyGhost_.stopChasing_==true)
    {
        if(pinkyGhost_.getChaseTime()==30.0f)
        {
            std::cout<<"pink1"<<std::endl;
            player_.render(*window_.getRenderWindow());
            pinkyGhost_.render(*window_.getRenderWindow());
        }

        else
        {
            std::cout<<"pink"<<std::endl;
            player_.renderOnStartPosition(*window_.getRenderWindow());
            player_.setLives(player_.getLives()-1);
            pinkyGhost_.renderOnStartPosition(*window_.getRenderWindow());
        }
        pinkyGhost_.stopChasing_=false;
        pinkyGhost_.stop_=true;
        sf::sleep(sf::seconds(0.001));
        //clydeGhost_.setRouteFlag(false);
    }

    else
    {
        player_.render(*window_.getRenderWindow());
        clydeGhost_.render(*window_.getRenderWindow());
        pinkyGhost_.render(*window_.getRenderWindow());
        blinkyGhost_.render(*window_.getRenderWindow());
    }

    if(blinkyGhost_.getInBetweenFlag()==true && blinkyGhost_.stopChasing_==true)
    {
        if(blinkyGhost_.getChaseTime()==30.0f)
        {
            std::cout<<"blinky1"<<std::endl;
            player_.render(*window_.getRenderWindow());
            blinkyGhost_.render(*window_.getRenderWindow());
        }

        else
        {
            std::cout<<"blink2"<<std::endl;
            player_.renderOnStartPosition(*window_.getRenderWindow());
            player_.setLives(player_.getLives()-1);
            blinkyGhost_.renderOnStartPosition(*window_.getRenderWindow());
        }
        blinkyGhost_.stopChasing_=false;
        blinkyGhost_.stop_=true;
        sf::sleep(sf::seconds(0.001));
        //clydeGhost_.setRouteFlag(false);
    }


    else
    {
        player_.render(*window_.getRenderWindow());
        clydeGhost_.render(*window_.getRenderWindow());
        pinkyGhost_.render(*window_.getRenderWindow());
        blinkyGhost_.render(*window_.getRenderWindow());
    }
    display_.render(*window_.getRenderWindow());

    window_.endDraw(); // Display.
}

void Game::sleep()
{
    sf::sleep(sf::milliseconds(1));
}

void Game::findPath(int y1, int x1, int y2, int x2)
{
    bfs_.findShortestPath(y1,x1,y2,x2);
    bfs_.fillChaseRoute();
}
