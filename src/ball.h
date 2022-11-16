#pragma once

#include "point.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

/**
 * \brief The Ball that will be used by the player to destroy the bricks
 * and also the one which the player will have to protect
 */
class Ball
{
private:
	// Variables used to determine the balls default values
	Point coordinate;
	Point speed;
	double radius;

	//method to check if the ball has hit an edge
	void bounce();

public:

	// Constructors
	Ball(const Point &c, const Point &s, double r);
	Ball(double cx, double cy, double sx, double sy, double r);

	//Draw the ball on canvas
	void drawBall() const;

	//Accessors for private values
	double getX() const;
	double getY() const;
	double getRadius() const;
	bool getFirstTopBounce() const;

	//move the ball and check if it reaches an edge
	void move();

	void flipY();

	void flipX();

	void increaseSpeed();

	void spawnBall(const int x, const int y);
};