#include "paddle.h"

Paddle::Paddle(Point c, Point s) : coordinate{ c }, size{ s } {}

Paddle::Paddle(int cx, int cy, int six, int siy)
{
	coordinate.x = cx;
	coordinate.y = cy;
	size.x = six;
	size.y = siy;
}

int Paddle::getX() const
{
	return coordinate.x;
}

int Paddle::getY() const
{
	return coordinate.y;
}

int Paddle::getSizeX() const
{
	return size.x;
}
int Paddle::getSizeY() const
{
	return size.y;
}

void Paddle::changeX(int delta)
{
	coordinate.x += delta;
}

void Paddle::changeSizeX(int delta)
{
	size.x += delta;
}


bool Paddle::checkCollision(const Ball& ball) const
{
	return ((ball.getX() + ball.getRadius() >= getX()) && (ball.getY() + ball.getRadius() >= getY())) &&
		((ball.getX() - ball.getRadius() <= getX() + getSizeX()) && (ball.getY() - ball.getRadius() <= getY() + getSizeY()));
}

void Paddle::doCollision(Ball& ball) const
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
