
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