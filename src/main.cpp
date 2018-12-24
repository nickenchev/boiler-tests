#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <boiler.h>

TEST_CASE("Size initialization", "[Size]")
{
	Size size(50, 90);

	REQUIRE(size.width == 50);
	REQUIRE(size.height == 90);
}

TEST_CASE("Rect initialization and min/max methods", "[Rect]")
{
	Rect rect(10, 20, Size(25, 45));

	SECTION("Initiailize Rect and ensure members are set correctly")
	{
		REQUIRE(rect.position.x == 10);
		REQUIRE(rect.position.y == 20);
		REQUIRE(rect.size.width == 25);
		REQUIRE(rect.size.height == 45);
	}

	SECTION("Min/max computation")
	{
		REQUIRE(rect.getMinX() == 10);
		REQUIRE(rect.getMinY() == 20);
		REQUIRE(rect.getMaxX() == 35);
		REQUIRE(rect.getMaxY() == 65);

		rect.position.y = 43;
		REQUIRE(rect.getMaxY() == 88);
	}
}
