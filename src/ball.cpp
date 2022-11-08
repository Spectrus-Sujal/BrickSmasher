
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
	ofSetColor(200);
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
	return coordinate.y;
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
		flipX();
	}

	//Check top and bottom
	if (getY() - getRadius() <= 0)
	{
		flipY();
		firstTopBounce = false;
	}
}

bool Ball::getFirstTopBounce() const
{
	return firstTopBounce;
}

void Ball::move()
{
	// Move it by it's speed
	// negative value = going backwards
	coordinate.x += speed.x;
	coordinate.y += speed.y;

	//check edges
	bounce();

	if(getY() + getRadius() < 0)
	{
		coordinate.y = 0 + getRadius();
	}

	if (getY() - getRadius() > ofGetHeight())
	{
		coordinate.y = ofGetHeight() - getRadius();
	}

	if (getX() + getRadius() < 0)
	{
		coordinate.x = 0 + getRadius();
	}

	if (getX() - getRadius() > ofGetWidth())
	{
		coordinate.x = ofGetWidth() - getRadius();
	}
}

void Ball::flipY()
{
	speed.y *= -1;
}

void Ball::flipX()
{
	// make it go opposite direction
	speed.x *= -1;
}

void Ball::increaseSpeed()
{
	speed.x *= 1.4;
}

void Ball::spawnBall(const int x, const int y)
{
	coordinate.x = x;
	coordinate.y = y;
	speed.y *= -1;
}
