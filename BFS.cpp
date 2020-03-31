#include "BFS.h"
#define ROW 31
#define COL 28
using namespace std;

BFS::BFS()
{

}

BFS::~BFS()
{

}

void BFS::setSourcePointCoordinates(int x, int y)
{
    this->source_.x=x;
    this->source_.y=y;
}

void BFS::setDestinationPointCoordinates(int x, int y)
{
    this->destination_.x=x;
    this->destination_.y=y;
}

bool BFS::isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

bool BFS::isDistance(AbstractGhost ag,Player player)
{
    double distance=std::sqrt(std::pow((ag.getGhostCurrentIndex().y-player.getCurrentIndex().y),2)+std::pow((ag.getGhostCurrentIndex().x-player.getCurrentIndex().x),2));
    if(distance<=5)
    {
        //std::cout<<"Chase mode"<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

std::vector <std::pair<int, int>> BFS::getChaseRoute()
{
    return this->chase_route;
}

void BFS::setChaseRouteClear()
{
    this->chase_route.clear();
}

/*
void BFS::printPath()
{
    if(!this->chase_route_backward.empty())
    {
        for(auto v=chase_route_backward.rbegin(); v!=chase_route_backward.rend(); v++)
        {
            std::cout<<v->point_.x<<","<<v->point_.y<<std::endl;
        }
        std::cout<<chase_route_backward.size()<<std::endl;
        chase_route_backward.clear();
    }
    else
    {
        std::cout<<"Wektor jest pusty";
    }
}*/

void BFS::printPath()
{
    if(!this->chase_route.empty())
    {
        for(std::vector <std::pair<int, int>>::iterator v=chase_route.begin(); v!=chase_route.end(); v++)
        {
            std::cout<<v->first<<","<<v->second<<std::endl;
        }
    }
    else
    {
        std::cout<<"Wektor jest pusty";
    }
}

void BFS::fillChaseRoute()
{
    if(!this->chase_route_backward.empty())
    {
        for(auto v=chase_route_backward.rbegin(); v!=chase_route_backward.rend(); v++)
        {
            this->chase_route.push_back(std::make_pair(v->point_.x,v->point_.y));
        }
        chase_route_backward.clear();
    }
}

int BFS::BFSAL()
{
    /**
      * Sprawdzenie, czy punkt startu i celu maja wartosc 1
      */
    if (!this->matrix[this->source_.x][this->source_.y] || !this->matrix[this->destination_.x][this->destination_.y])
        return -1;

    /**
      * Tablica wartosci typu bool, w ktorej odznacza sie odwiedzone wezly
      */
    bool visited[ROW][COL];

    memset(visited, false, sizeof visited);

    /**
      * Odznaczanie odwiedzonych wierzcholkow
      */
    visited[this->source_.x][this->source_.y] = true;

    /**
      * Utworzenie kolejki dla algorytmu i kolejek pomocniczych
      */
    queue<queueNode> q;
    queue<queueNode> p;
    vector<queueNode> v;

    /**
      * Wezel startowy
      */
    queueNode s ;
    queueNode temp;

    s.point_ =this->source_;

    /**
      * Ustawienie dystansu punktu startowego na 0
      */
    s.distance_= 0;
    s.parent_= {-1,-1};

    /**
      * Dolaczanie do kolejki
      */
    q.push(s);

    /**
      * Start algorytmu
      */
    while (!q.empty())
    {
        this->current_node = q.front();
        v.push_back(q.front());
        Point pt = this->current_node.point_;

        /**
          * Jesli osiagnelismy cel, to wyznaczamy sciezke od startu do celu
          */
        if (pt.x == this->destination_.x && pt.y == this->destination_.y)
        {
            temp=v.back();
            this->chase_route_backward.push_back(v.back());
            v.pop_back();

            /**
            * Aby wyznaczyc sciezke, trzeba przjesc od punktu celu kolejno po wezlach-rodzicach
            */
            while(!v.empty())
            {
                if(temp.parent_.x==v.back().point_.x && temp.parent_.y==v.back().point_.y)
                {
                    this->chase_route_backward.push_back(v.back());
                    temp=v.back();
                    v.pop_back();
                }
                else
                {
                    v.pop_back();
                }
            }
            cout<<endl;

            return this->current_node.distance_;
        }

        /**
          * Usuwamy ostatni wezel i dolaczamy do kolejki sasiadow tego wezla
          * Sasiedzi tylko w mozliwych kierunkach,osiagalnych z danego punktu
          */
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col) && this->matrix[row][col] && !visited[row][col])
            {
                visited[row][col] = true;
                queueNode neighbour_ = { {row, col},
                    this->current_node.distance_ + 1,{pt.x,pt.y}
                };

                q.push(neighbour_);
            }
        }
    }

    return -1;
}


void BFS::findShortestPath(int x1,int y1,int x2, int y2)
{

    this->setSourcePointCoordinates(x1,y1);
    this->setDestinationPointCoordinates(x2,y2);
    this->end_distance=this->BFSAL();
    if(end_distance!=INT_MAX);
    //std::cout<<"Najkrotsza sciezka to :"<<end_distance<<std::endl;
    else
    {
        //std::cout<<"Najkrotsza sciezka nie istnieje !"<<std::endl;
    };
}
