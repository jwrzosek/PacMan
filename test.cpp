#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include "nlohmann/json.hpp"
#include "AbstractGhost.h"
#include "AbstractGhost.cpp"
#include "ClydeGhost.h"
#include "ClydeGhost.cpp"
#include "Configuration.h"
#include "Configuration.cpp"
#include "CollisionVisitor.h"
#include "CollisionVisitor.cpp"
#include "Display.h"
#include "Display.cpp"
#include "Ball.h"
#include "Ball.cpp"
#include "Pill.h"
#include "Pill.cpp"
#include "Gate.h"
#include "Gate.cpp"
#include "Portal.h"
#include "Portal.cpp"
#include "PinkyGhost.h"
#include "PinkyGhost.cpp"
#include "BlinkyGhost.h"
#include "BlinkyGhost.cpp"
#include "BFS.h"
#include "BFS.cpp"
#include "Map.h"
#include "Map.cpp"
#include "Element.h"
#include "Element.cpp"
#include "Game.h"
#include "Game.cpp"
#include "Player.h"
#include "Player.cpp"
#include "types.h"
#include  "Wall.h"
#include "Wall.cpp"
#include "Window.h"
#include "Window.cpp"
#include "Visitor.h"
#include "Visitor.cpp"

//Testy Mapy
BOOST_AUTO_TEST_SUITE( MapTest )
BOOST_AUTO_TEST_CASE( testField )
{
    Map map;
    BOOST_CHECK( map.getFieldOnIndex( 0, 0 ) == W );
    BOOST_CHECK( map.getFieldOnIndex( 1, 1 ) == o );
    BOOST_CHECK( map.getFieldOnIndex( 1, 3 ) == O );
    BOOST_CHECK( map.getFieldOnIndex( 0,14 ) == P);
    BOOST_CHECK( map.getFieldOnIndex( 3, 3 ) == n );
    BOOST_CHECK( map.getFieldOnIndex( 13,12 ) == G );
}

BOOST_AUTO_TEST_SUITE_END()

//Testy BFS
BOOST_AUTO_TEST_SUITE( BFSTest )
BOOST_AUTO_TEST_CASE( ALtest1 )
{
    BFS bfs;
    BOOST_CHECK( bfs.matrix[0][0] == 0 );
    bfs.findShortestPath(1,1,1,2);
    BOOST_CHECK(bfs.end_distance==1);
}
BOOST_AUTO_TEST_CASE( ALtest2 )
{
    BFS bfs;
    bfs.findShortestPath(0,1,0,2);
    BOOST_CHECK(bfs.end_distance==-1);
}
BOOST_AUTO_TEST_CASE( ALtest3 )
{
    BFS bfs;
    bfs.findShortestPath(1,1,3,6);
    BOOST_CHECK(bfs.end_distance==7);
}

BOOST_AUTO_TEST_CASE( ALtest4 )
{
    BFS bfs;
    bfs.findShortestPath(1,1,5,5);
    BOOST_CHECK(bfs.end_distance==8);
}
BOOST_AUTO_TEST_CASE( ALtest5 )
{
    BFS bfs;
    bfs.findShortestPath(1,1,2,26);
    BOOST_CHECK(bfs.end_distance==44);
}
BOOST_AUTO_TEST_SUITE_END()

//Testy Playera
BOOST_AUTO_TEST_SUITE(PlayerTest )
BOOST_AUTO_TEST_CASE(GetLivesTest)
{
	Map m;
	sf::Vector2f start_pos = { 0.f, 0.f };
	Player p(start_pos, m);
	BOOST_CHECK_EQUAL(p.getLives(), 3);
}

BOOST_AUTO_TEST_CASE(GetScoreTest)
{
	Map m;
	sf::Vector2f start_pos = { 0.f, 0.f };
	Player p(start_pos, m);
	BOOST_CHECK_EQUAL(p.getScore(), 0);
}

BOOST_AUTO_TEST_CASE(SetLivesTest)
{
	Map m;
	sf::Vector2f start_pos = { 0.f, 0.f };
	Player p(start_pos, m);

	p.setLives(3);
	BOOST_CHECK_EQUAL(p.getLives(), 3);

	p.setLives(5);
	BOOST_CHECK_EQUAL(p.getLives(), 5);

	p.setLives(0);
	BOOST_CHECK_EQUAL(p.getLives(), 0);
}

BOOST_AUTO_TEST_CASE(SetScoreTest)
{
	Map m;
	sf::Vector2f start_pos = { 0.f, 0.f };
	Player p(start_pos, m);

	p.setScore(20);
	BOOST_CHECK_EQUAL(p.getScore(), 20);

	p.setScore(10);
	BOOST_CHECK_EQUAL(p.getScore(), 10);

}

BOOST_AUTO_TEST_CASE(IncreaseScoreTest)
{
	Map m;
	sf::Vector2f start_pos = { 0.f, 0.f };
	Player p(start_pos, m);
	BOOST_CHECK_EQUAL(p.getScore(), 0);

	p.increaseScore();
	BOOST_CHECK_EQUAL(p.getScore(), 10);

}

BOOST_AUTO_TEST_SUITE_END()

//Testy Pill
BOOST_AUTO_TEST_SUITE(PillTest)
BOOST_AUTO_TEST_CASE(PillGetVisitedTest)
{
	Pill p;
	BOOST_TEST(false == p.getVisited());
}

BOOST_AUTO_TEST_CASE(PillSetVisitedTest)
{
	Pill p;
	p.setVisited();
	BOOST_TEST(true == p.getVisited());
}

BOOST_AUTO_TEST_SUITE_END()

//Testy Configuration
BOOST_AUTO_TEST_SUITE(ConfigurationTest)
BOOST_AUTO_TEST_CASE(GetFieldOnIndexTest)
{
	Configuration c;
	c.initFieldsMap();
	BOOST_TEST(c.getFieldOnIndex(0, 0) == n);
	BOOST_TEST(c.getFieldOnIndex(2, 10) == n);
}


BOOST_AUTO_TEST_CASE(InitFieldsMapTest)
{
	Configuration c;
	c.initFieldsMap();
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(0,0), n);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(27, 30), n);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(2, 5), n);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(10, 15), n);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(20, 25), n);
}

BOOST_AUTO_TEST_CASE(DeserializeJsonTest)
{
	Configuration c;
	std::string filepath = "map_config.json";
	c.deserialize_json(filepath);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(0, 0), W);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(1, 0), W);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(1, 1), o);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(27, 30), W);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(1, 3), O);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(26, 3), O);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(0, 14), P);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(27, 14), P);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(14, 12), G);
	BOOST_CHECK_EQUAL(c.getFieldOnIndex(13, 12), G);
}

BOOST_AUTO_TEST_SUITE_END()

//Testy Ball
BOOST_AUTO_TEST_SUITE(BallTests)
BOOST_AUTO_TEST_CASE(BallGetVisitedTest)
{
	Ball b;
	BOOST_TEST(false == b.getVisited());
}

BOOST_AUTO_TEST_CASE(BallSetVisitedTest)
{
	Ball b;
	b.setVisited();
	BOOST_TEST(true == b.getVisited());
}

BOOST_AUTO_TEST_SUITE_END()



