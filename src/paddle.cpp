#include "paddle.h"

Paddle::Paddle(Point c, Point s) : coordinate{ c }, size{ s } {}

Paddle::Paddle(double cx, double cy, double six, double siy)
{
	coordinate = Point{ cx, cy };
	size = Point{ six, siy };
}

double Paddle::getX() const
{
	return coordinate.x;
}

double Paddle::getY() const
{
	return coordinate.y;
}

double Paddle::getSizeX() const
{
	return size.x;
}

double Paddle::getSizeY() const
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
