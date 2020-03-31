#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../PacMan/Pill.h"

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