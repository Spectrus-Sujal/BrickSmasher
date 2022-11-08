
#include "ball.h"

//Constructor 1
Ball::Ball(const Point &c, const Point &s, int r) : coordinate{ c }, speed{ s }, radius{ r } {}

//Constructor 2
Ball::Ball(int cx, int cy, int sx, int sy, int r)
{
	//Assign individual values
	coordinate.x = cx;
	coordinate.y = cy;
	speed.x = sx;
	speed.y = sy;
	radius = r;
}

//Draw the ball
void Ball::drawBall() const
{
	// Circle at the ball's position with the radius
	ofDrawCircle(getX(), getY(), getRadius());
}

// Accessors
///////////////////
int Ball::getX() const
{
	return coordinate.x;
}

int Ball::getY() const
{
	return coordinate.x;
}

int Ball::getRadius() const
{
	return radius;
}
//////////////////

// Bounce the ball off of the ends of canvas
void Ball::bounce()
{
	//Check if the ball is near the left or right edge
	if (getX() + getRadius() >= ofGetWidth() || getX() - getRadius() <= 0)
	{
		// make it go opposite direction
		speed.x *= -1;
	}

	//Check top
	if (getY() + getRadius() >= ofGetHeight())
	{
		speed.y *= -1;
	}

	if(getY() <= 0)
	{
		//player.lose = true;
	}
}

void Ball::move()
{
	// Move it by it's speed
	// negative value = going backwards
	coordinate.x += speed.x;
	coordinate.y += speed.y;

	//check edges
	bounce();
}