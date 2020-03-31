#include "AbstractGhost.h"
#include <iostream>


AbstractGhost::AbstractGhost(sf::Vector2f ghostStartPos, Map& map,sf::Color color)
{
    this->ghost_start_position= ghostStartPos;
    this->ghost_current_position= ghost_start_position;
    this->chase_mode_time=30.0f;
    this->scatter_mode=false;
    this->chase_mode=false;
    this->in_between_mode=false;
    this->route_counter=0;
    this->route_flag=false;
    this->ghost_current_index=
    {
        (static_cast<int>((ghost_current_position.x - map.getMapStartPosition().x) / 20) ),
        (static_cast<int>((ghost_current_position.y - map.getMapStartPosition().y) / 20) )
    };

    this->dir_ = Direction::None;
    this->nextDir_ = Direction::None;

    this->ghost_steps_counter = { 0, 0 };
    this->initShape(color);
}

AbstractGhost::~AbstractGhost() {}

void AbstractGhost::setDirection(Direction dir)
{
    this->nextDir_ = dir;
}

void AbstractGhost::setChaseModeTime(float time)
{
    this->chase_mode_time=time;
}

void AbstractGhost::substractChaseModeTime()
{
    this->chase_mode_time=this->chase_mode_time-0.05;
}

Direction AbstractGhost::getDirection()
{
    return this->dir_;
}

bool AbstractGhost::getStartModeFlag()
{
    return this->start_mode;
}

bool AbstractGhost::getScatterModeFlag()
{
    return this->scatter_mode;
}

bool AbstractGhost::getChaseModeFlag()
{
    return this->chase_mode;
}

bool AbstractGhost::getInBetweenFlag()
{
    return this->in_between_mode;
}

bool AbstractGhost::getRouteFlag()
{
    return this->route_flag;
}

void AbstractGhost::setStartModeFlag(bool flag)
{
    this->start_mode=flag;
}

void AbstractGhost::setScatterModeFlag(bool flag)
{
    this->scatter_mode=flag;
}

void AbstractGhost::setChaseModeFlag(bool flag)
{
    this->chase_mode=flag;
    this->route_counter=0;
}

void AbstractGhost::setInBetweenFlag(bool flag)
{
    this->in_between_mode=flag;
}

void AbstractGhost::setRouteFlag(bool flag)
{
    this->route_flag=flag;
}

void AbstractGhost::startMode()
{
    if(this->getRouteFlag()==false)
    {
        this->item_=(this->start_route.begin()+this->route_counter);
    }

    if(this->getGhostCurrentIndex().x==this->item_->first && this->getGhostCurrentIndex().y==this->item_->second)
    {
        if(this->getGhostStepsCounter().x % 20 == 0 || this->getGhostStepsCounter().y % 20 == 0)
        {
            if(this->getRouteFlag()==false)
            {
                this->changePosition(this->start_route[this->route_counter+1].first,this->start_route[this->route_counter+1].second);
            }
            this->route_counter++;
            if(this->route_counter==this->start_route.size())
            {
                if(this->item_==this->start_route.end()-1)
                {
                    this->setStartModeFlag(false);
                    this->route_counter=0;
                    this->setScatterModeFlag(true);
                }
            }
        }
    }
}

void AbstractGhost::scatterMode()
{
    if(this->getRouteFlag()==false)
    {
        this->item_=(this->scatter_route.begin()+this->route_counter);
    }

    if(this->getGhostCurrentIndex().x==this->item_->first && this->getGhostCurrentIndex().y==this->item_->second)
    {
        if(this->getGhostStepsCounter().x % 20 == 0 || this->getGhostStepsCounter().y % 20 == 0)
        {
            if(this->getRouteFlag()==false)
            {
                this->changePosition(this->scatter_route[this->route_counter+1].first,this->scatter_route[this->route_counter+1].second);
            }
            else if(this->getRouteFlag()==true)
            {
                //clydeGhost_.changePosition(r_[counter_+1].first,r_[counter_+1].second);
            }
            this->route_counter++;
            if(this->route_counter==this->scatter_route.size() )
            {
                if(this->item_==this->scatter_route.end()-1)
                {
                    this->route_counter=0;
                    this->item_=(this->scatter_route.begin()+this->route_counter);
                }

            }
        }
    }
}

void AbstractGhost::chaseMode(std::vector <std::pair<int, int>> chaseRoute_)
{
    if(this->getRouteFlag()==false )
    {
        this->item_=(chaseRoute_.begin()+this->route_counter);
    }
    /*else if(this->getRouteFlag()==true)
     {
         this->item_=(chaseRoute_.begin()+this->route_counter);
     }*/
    //std::cout<<"item :"<<item_->first<<", "<<item_->second<<std::endl;
    //td::cout<<"index :"<<this->getGhostCurrentIndex().x<<", "<<this->getGhostCurrentIndex().y<<std::endl;
    if(this->getGhostCurrentIndex().x==this->item_->second && this->getGhostCurrentIndex().y==this->item_->first)
    {
        if(this->getGhostStepsCounter().x % 20 == 0 || this->getGhostStepsCounter().y % 20 == 0)
        {
            if(this->getRouteFlag()==false)
            {
                this->changePosition(chaseRoute_[this->route_counter+1].second,chaseRoute_[this->route_counter+1].first);
            }
            /*else if(this->getRouteFlag()==true)
            {
                std::cout<<"change"<<std::endl;
                this->changePosition(chaseRoute_[this->route_counter+1].second,chaseRoute_[this->route_counter+1].first);
            }*/
            this->route_counter++;
            if(this->item_==chaseRoute_.end()-1)
            {
                //std::cout<<"koniec!"<<std::endl;

                this->setDirection(Direction::None);
                item_->first=this->getGhostCurrentIndex().y;
                item_->second=this->getGhostCurrentIndex().x;
                this->route_counter=0;
                this->setRouteFlag(true);
                this->setInBetweenFlag(true);
                this->setChaseModeFlag(false);
                //this->setChaseModeFlag(false);
                //this->route_counter=0;
                //this->setScatterModeFlag(true);
            }

        }
    }
    // else
    // {
    //     this->route_counter--;
    // }
}

void AbstractGhost::inBetweenMode(std::vector <std::pair<int, int>> chaseRoute_)
{
    if(this->getRouteFlag()==true)
    {
        this->item_=(chaseRoute_.begin()+this->route_counter);
    }
    //std::cout<<"item :"<<item_->first<<", "<<item_->second<<std::endl;
    //std::cout<<"index :"<<this->getGhostCurrentIndex().x<<", "<<this->getGhostCurrentIndex().y<<std::endl;
    if(this->getGhostCurrentIndex().x==this->item_->second && this->getGhostCurrentIndex().y==this->item_->first)
    {
        if(this->getGhostStepsCounter().x % 20 == 0 || this->getGhostStepsCounter().y % 20 == 0)
        {
            if(this->getRouteFlag()==true)
            {
                //std::cout<<"change"<<std::endl;
                this->changePosition(chaseRoute_[this->route_counter+1].second,chaseRoute_[this->route_counter+1].first);
            }
            this->route_counter++;
            if(this->item_==chaseRoute_.end()-1)
            {
                //std::cout<<"koniec powracania!"<<std::endl;
                this->setDirection(Direction::None);
                item_->first=this->getGhostCurrentIndex().y;
                item_->second=this->getGhostCurrentIndex().x;
                this->route_counter=0;
                this->setRouteFlag(false);
                //this->setChaseModeFlag(false);
                //this->route_counter=0;
                this->setInBetweenFlag(false);
                this->setScatterModeFlag(true);
                this->stopChasing_=true;
            }

        }
    }
    else
    {
        this->route_counter--;
    }

}

void AbstractGhost::changePosition(int x,int y)
{
    this->transferPointToDirection(x,y);
}

void AbstractGhost::transferPointToDirection(int x, int y)
{
    if (x==this->getGhostCurrentIndex().x && y>this->getGhostCurrentIndex().y)
    {
        this->setDirection(Direction::Down);
    }
    else if (x==this->getGhostCurrentIndex().x && y<this->getGhostCurrentIndex().y)
    {
        this->setDirection(Direction::Up);
    }
    else if (y==this->getGhostCurrentIndex().y && x>this->getGhostCurrentIndex().x)
    {
        this->setDirection(Direction::Right);
    }
    else if (y==this->getGhostCurrentIndex().y && x<this->getGhostCurrentIndex().x)
    {
        this->setDirection(Direction::Left);
    }
    else if(y==this->getGhostCurrentIndex().y && x==this->getGhostCurrentIndex().x)
    {
        this->setDirection(Direction::None);
    }
}

float AbstractGhost::getSize()
{
    return this->size;
}

float AbstractGhost::getChaseTime()
{
    return this->chase_mode_time;
}

sf::CircleShape AbstractGhost::getShape()
{
    return this->shape;
}

sf::Vector2i AbstractGhost::getGhostStepsCounter()
{
    return this->ghost_steps_counter;
}

sf::Vector2f AbstractGhost::getGhostStartPosition()
{
    return this->ghost_start_position;
}

sf::Vector2f AbstractGhost::getGhostCurrentPosition()
{
    return this->ghost_current_position;
}
sf::Vector2i AbstractGhost::getGhostCurrentIndex()
{
    return this->ghost_current_index;
}

void AbstractGhost::move()
{
    if (dir_ == Direction::Left)
    {
        --this->ghost_current_position.x;
    }
    else if (dir_ == Direction::Right)
    {
        ++this->ghost_current_position.x;
    }
    else if (dir_ == Direction::Up)
    {
        --this->ghost_current_position.y;
    }
    else if (dir_ == Direction::Down)
    {
        ++this->ghost_current_position.y;
    }
    else if(dir_==Direction::None)
    {
        //this->ghostCurrentPosition_.y = this->ghostCurrentPosition_.y;
        //this->ghostCurrentPosition_.x = this->ghostCurrentPosition_.x;
        //  this->ghostCurrentIndex_.y =this->ghostCurrentIndex_.y ;
        // this->ghostCurrentIndex_.x = this->ghostCurrentIndex_.x;
    }

}

void AbstractGhost::initShape(sf::Color color)
{
    this->shape.setFillColor(color);
    this->shape.setRadius(this->getSize());
    this->shape.setPosition(this->ghost_start_position);

}

void AbstractGhost::render(sf::RenderWindow& l_window)
{
    shape.setPosition(this->getGhostCurrentPosition());
    l_window.draw(shape);
}

void AbstractGhost::renderOnStartPosition(sf::RenderWindow& l_window)
{
    this->setDirection(Direction::None);
    this->ghost_current_position.x=this->ghost_start_position.x;
    this->ghost_current_position.y=this->ghost_start_position.y;
    this->ghost_current_index.x = static_cast<int>((ghost_current_index.x - 120.f) / 20);
    this->ghost_current_index.y = static_cast<int>((ghost_current_index.y - 40.f) / 20);
    this->shape.setPosition(this->ghost_start_position);
    l_window.draw(this->shape);
    this->setChaseModeFlag(false);
    this->setInBetweenFlag(false);
    this->setScatterModeFlag(false);
    this->setRouteFlag(false);
    this->setStartModeFlag(true);
}

void AbstractGhost::update(Map& map)
{
    this->ghost_current_index.x = static_cast<int>((ghost_current_position.x - map.getMapStartPosition().x) / 20);
    this->ghost_current_index.y = static_cast<int>((ghost_current_position.y - map.getMapStartPosition().y) / 20);
    //std::cout<<"ghost indexx :"<<this->getGhostCurrentIndex().x<<", "<<this->getGhostCurrentIndex().y<<std::endl;

    if (this->ghost_steps_counter.x % 20 == 0 && this->ghost_steps_counter.y % 20 == 0)
    {
        if (dir_ != nextDir_)
            dir_ = nextDir_;
        this->checkCollision(map);
    }

    if (this->dir_ == Direction::None)
        return;
    else if (ghost_steps_counter.x < 20 && (this->dir_ == Direction::Left || this->dir_ == Direction::Right))
    {
        this->move();
        ghost_steps_counter.x++;
    }
    else if (ghost_steps_counter.y < 20 && (this->dir_ == Direction::Up || this->dir_ == Direction::Down))
    {
        this->move();
        ghost_steps_counter.y++;
    }
    else
    {
        ghost_steps_counter = {0, 0};
    }

}

void AbstractGhost::checkCollision(Map& map)
{
    if (dir_ == Direction::Left && map.getFieldOnIndex(ghost_current_index.x - 1, ghost_current_index.y) == W)
    {
        this->dir_ = Direction::None;
        this->nextDir_ = Direction::None;
    }
    else if (dir_ == Direction::Right && map.getFieldOnIndex(ghost_current_index.x + 1, ghost_current_index.y) == W)
    {
        this->dir_ = Direction::None;
        this->nextDir_ = Direction::None;
    }
    else if (dir_ == Direction::Up && map.getFieldOnIndex(ghost_current_index.x, ghost_current_index.y - 1) == W)
    {
        this->dir_ = Direction::None;
        this->nextDir_ = Direction::None;
    }
    else if (dir_ == Direction::Down && map.getFieldOnIndex(ghost_current_index.x, ghost_current_index.y + 1) == W)
    {
        this->dir_ = Direction::None;
        this->nextDir_ = Direction::None;
    }
}





