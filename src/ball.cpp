
#include "ball.h"

//Point Constructor
Ball::Ball(const Point &c, const Point &s, double r) : coordinate{ c }, speed{ s }, radius{ r } {}

//Double Constructor
Ball::Ball(double cx, double cy, double sx, double sy, double r)
{
	//Assign individual values
	coordinate = Point{ cx, cy };
	speed = Point{ sx, sy };
	radius = r;
}


void Ball::drawBall() const
{
	// Set the balls color
	ofSetColor(200);
	// Draw a circle using coordinate and radius
	ofDrawCircle(getX(), getY(), getRadius());
}


double Ball::getX() const
{
	return coordinate.x;
}


double Ball::getY() const
{
	return coordinate.y;
}

double Ball::getRadius() const
{
	return radius;
}


void Ball::bounce()
{
	// Check if the ball is near the left or right edge
	if (getX() + getRadius() >= ofGetWidth() || getX() - getRadius() <= 0)
	{
		// Flip Directions
		flipX();

		// Make sure the ball is no longer on the edge
		if(getX() + getRadius() >= ofGetWidth()) coordinate.x = ofGetWidth() - getRadius() - 1;

		if(getX() + getRadius() <= 0) coordinate.x = getRadius() + 1;

	}

	// Check top edge
	if (getY() - getRadius() < 0)
	{
		flipY();

		if(getY() - getRadius() <= 0) coordinate.y = getRadius();
	}
}

void Ball::move()
{
	// Move Ball by speed
	// negative value = going Left
	coordinate.x += speed.x;
	coordinate.y += speed.y;

	// Check edges
	bounce();
}

void Ball::flipY()
{
	speed.y *= -1;
}

void Ball::flipX()
{
	// Make it go opposite direction
	speed.x *= -1;
}

void Ball::increaseSpeed()
{
	speed.x *= 1.2;
}

void Ball::spawnBall(const int x, const int y)
{
	coordinate.x = x;
	coordinate.y = y;
	speed.y *= -1;
}
