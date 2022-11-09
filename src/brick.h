#pragma once

#include "point.h"
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
	
	Brick(Point c, Point s, level l);

	int getX() const;
	int getY() const;
	int getSizeX() const;
	int getSizeY() const;

	level getLvl() const;

	ofColor getBrickColor() const;

};