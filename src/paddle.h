#pragma once

#include "point.h"
#include "ball.h"
#include "ofGraphics.h"

class Paddle
{
private:

	Point coordinate;
	Point size;

public:

	//Constructor
	Paddle(Point c, Point s);
	Paddle(int cx, int cy, int six, int siy);

	// Getters
	int getX() const;
	int getY() const;
	int getSizeX() const;
	int getSizeY() const;

	void changeX(int delta);
	void changeSizeX(int delta);

	//Collision
	bool checkCollision(const Ball& ball) const;
	void doCollision(Ball& ball) const;

};