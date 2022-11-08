#pragma once

#include "brick.h"
#include "ball.h"
#include "ofApp.h"

class BrickWall
{
private:

	std::vector<Brick> wall;

public:

	BrickWall(std::vector<Brick>& w);

	void drawBricks();

	void checkCollision(Ball& ball);
};
