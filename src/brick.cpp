
#include "brick.h"

Brick::Brick(Point c, Point s, level l) : coordinate{ c }, size{ s }, lvl{ l } {}

Brick::Brick(int cx, int cy, int six, int siy, level l)
{
	coordinate.x = cx;
	coordinate.y = cy;
	size.x = six;
	size.y = siy;
	lvl = l;
}

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

bool Brick::checkCollision(const Ball& ball) const
{
	return ((ball.getX() + ball.getRadius() >= getX()) && (ball.getY() + ball.getRadius() >= getY())) &&
			((ball.getX() - ball.getRadius() <= getX() + getSizeX()) && (ball.getY() - ball.getRadius() <= getY() + getSizeY()));
}

void Brick::doCollision(Ball& ball) const
{
	if (ball.getX() + ball.getRadius() > getX() + getSizeX())
	{
		ball.flipX();
	}
	else if (ball.getX() - ball.getRadius() < getX())
	{
		ball.flipX();
	}

	if (ball.getY() + ball.getRadius() > getY() + getSizeY())
	{
		ball.flipY();
	}
	else if (ball.getY() - ball.getRadius() < getY())
	{
		ball.flipY();
	}
}
