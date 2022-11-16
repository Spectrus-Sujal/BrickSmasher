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
	double speed;
	double points = 0;
	bool isHalf = false;
	ofColor playerColor;

public:

	Player(const Point &c, const Point &si, double sp);
	Player(double cx, double cy, double six, double siy, double sp);

	void move(bool moveLeft);

	void move(int x);

	void half();

	void drawPlayer() const;

	void checkCollision(Ball& ball);

};