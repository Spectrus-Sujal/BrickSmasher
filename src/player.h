#pragma once

#include "point.h"
#include "paddle.h"
#include "ofGraphics.h"

/**
 * \brief Player class which is used to contain all of the information of the player
 */
class Player : Paddle
{
private:
	int speed;
	int points = 0;
	bool isHalf = false;
	ofColor playerColor;

public:

	Player(const Point &c, const Point &si, int sp);
	Player(int cx, int cy, int six, int siy, int sp);

	void move(bool moveLeft);

	void half();

	void increasePoints(int delta);
	int getPoints() const;

	void drawPlayer() const;

	void checkCollision(Ball& ball);

};