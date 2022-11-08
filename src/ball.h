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
	int radius;

	//method to check if the ball has hit an edge
	void bounce();

public:

	// Constructors
	Ball(const Point &c, const Point &s, int r);
	Ball(int cx, int cy, int sx, int sy, int r);

	//Draw the ball on canvas
	void drawBall() const;

	//Accessors for private values
	int getX() const;
	int getY() const;
	int getRadius() const;

	//move the ball and check if it reaches an edge
	void move();
};