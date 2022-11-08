#pragma once

#include "brick.h"
#include "ball.h"
#include "ofGraphics.h"

class BrickWall
{
private:

	std::vector<Brick> wall;

public:

	BrickWall(std::vector<Brick>& w);

	void drawBricks();

	void resizeWalls(std::vector<Brick>& w);

	void checkCollision(Ball& ball);
};
