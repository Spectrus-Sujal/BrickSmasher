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
	Paddle(double cx, double cy, double six, double siy);

	// Getters
	double getX() const;
	double getY() const;
	double getSizeX() const;
	double getSizeY() const;

	void changeX(int delta);
	void changeSizeX(int delta);

	//Collision
	bool checkCollision(const Ball& ball) const;
	void doCollision(Ball& ball) const;

};