#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../PacMan/CollisionVisitor.h"

BOOST_AUTO_TEST_SUITE(CollisionVisitorTest)

BOOST_AUTO_TEST_CASE(GetDirectionTest)
{
	CollisionVisitor v(Direction::None);
	BOOST_CHECK_EQUAL(v.getDirection(), Direction::None);
}

BOOST_AUTO_TEST_CASE(IsPortalTest)
{
	CollisionVisitor v(Direction::None);
	BOOST_TEST(v.isPortal() == false);
}

BOOST_AUTO_TEST_CASE(IsPillTest)
{
	CollisionVisitor v(Direction::None);
	BOOST_TEST(v.isPill() == false);
}

BOOST_AUTO_TEST_CASE(IsBallTest)
{
	CollisionVisitor v(Direction::None);
	BOOST_CHECK_EQUAL(v.isBall(), Direction::None);
}

BOOST_AUTO_TEST_SUITE_END()