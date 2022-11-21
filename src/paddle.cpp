#include "paddle.h"

////////////// Constructors ///////////////////////
Paddle::Paddle(Point c, Point s) : coordinate{ c }, size{ s } {}

Paddle::Paddle(double cx, double cy, double six, double siy) : coordinate{cx, cy}, size{six, siy} {}

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
	// Return if the ball is within the area where the Paddle is drawn
	return ((ball.getX() + ball.getRadius() >= getX()) 
		&& (ball.getY() + ball.getRadius() >= getY()))
		&&((ball.getX() - ball.getRadius() <= getX() + getSizeX()) 
		&& (ball.getY() - ball.getRadius() <= getY() + getSizeY()));
}

void Paddle::doCollision(Ball& ball) const
{
	// Check if the ball is touching either left or right edge

	// Checking if the right edge of the ball is greater than
	// the right edge of the Paddle

	// or

	// if the left edge of the ball is less than
	// the left edge of the Paddle
	if (ball.getX() + ball.getRadius() > getX() + getSizeX() || ball.getX() - ball.getRadius() < getX())
	{
		ball.flipX();
	}

	// Do the same but for the top and bottom the ball
	// and the Paddle
	if ((ball.getY() + ball.getRadius() > getY() + getSizeY()) || (ball.getY() - ball.getRadius() < getY()))
	{
		ball.flipY();
	}
}
