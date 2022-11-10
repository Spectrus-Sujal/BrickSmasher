
#include "brick.h"

Brick::Brick(Point c, Point s, level l) : Paddle{c, s}, lvl{l} {}

Brick::Brick(int cx, int cy, int six, int siy, level l) : Paddle{ cx, cy, six, siy }
{
	lvl = l;
}


Brick::level Brick::getLvl() const
{
	return lvl;
}

ofColor Brick::getBrickColor() const
{
	switch(lvl)
	{
		case level::Green:
			return ofColor(51, 255, 51);

		case level::Orange:
			return ofColor(255, 179, 25);

		case level::Red:
			return ofColor(255, 25, 25);

		case level::Yellow:
		default:
			return ofColor(255, 255, 77);
	}
}

int Brick::getPoints() const
{
	switch (lvl)
	{
	case level::Green:
		return 3;

	case level::Orange:
		return 5;

	case level::Red:
		return 7;

	case level::Yellow:
	default:
		return 1;
	}
}
