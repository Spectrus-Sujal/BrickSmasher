#pragma once

#include "brick.h"
#include "ball.h"
#include "player.h"
#include "ofGraphics.h"

class BrickWall
{
private:

	std::vector<Brick> wall;

public:

	BrickWall();

	BrickWall(std::vector<Brick>& w);

	void drawBricks();

	void resizeWalls(const std::vector<Brick>& w);

	void checkCollision(Ball& ball, Player& player);
};
