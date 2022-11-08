#pragma once

#include "Point.h"
#include "ofApp.h"

class Player
{
private:
	Point coordinate;
	Point size;
	int speed;
	bool isHalf = false;

public:
	bool lose = false;

	Player(const Point &c, const Point &si, int sp);
	Player(int cx, int cy, int six, int siy, int sp);

	void move(bool moveLeft);

	void half();

	void drawPlayer() const;
};