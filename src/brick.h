#pragma once

#include "paddle.h"

class Brick : public Paddle
{
public:
	enum class level
	{
		Yellow, Green, Orange, Red
	};

private:
	
	level lvl;

public:

	//Constructor
	Brick(Point c, Point s, level l);
	Brick(int cx, int cy, int six, int siy, level l);

	// Getters
	level getLvl() const;
	ofColor getBrickColor() const;	
	int getPoints() const;
	
};