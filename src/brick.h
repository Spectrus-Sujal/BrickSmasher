#pragma once

#include "point.h"
#include "ball.h"
#include "ofGraphics.h"

class Brick
{
public:
	enum class level
	{
		Yellow, Green, Orange, Red
	};
private:
	
	Point coordinate;
	Point size;
	level lvl;

public:

	//Constructor
	Brick(Point c, Point s, level l);
	Brick(int cx, int cy, int six, int siy, level l);

	// Getters
	int getX() const;
	int getY() const;
	int getSizeX() const;
	int getSizeY() const;
	int getPoints() const;
	level getLvl() const;
	ofColor getBrickColor() const;	

	//Collision
	bool checkCollision(const Ball& ball) const;
	void doCollision(Ball& ball) const;
	
};