
#include "brick.h"

Brick::Brick(Point c, Point s, level l) : coordinate{ c }, size{ s }, lvl{ l } {}

int Brick::getX() const
{
	return coordinate.x;
}

int Brick::getY() const
{
	return coordinate.y;
}

int Brick::getSizeX() const
{
	return size.x;
}
int Brick::getSizeY() const
{
	return size.y;
}

Brick::level Brick::getLvl() const
{
	return lvl;
}

std::string Brick::getBrickColor() const
{
	switch(lvl)
	{
		case level::Green:
			return "green";

		case level::Orange:
			return "orange";

		case level::Red:
			return "Red";

		case level::Yellow:
		default:
			return "yellow";
	}
}