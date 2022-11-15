#pragma once

#include "brick.h"
#include "ball.h"
#include "brick.h"
#include "player.h"
#include "ofGraphics.h"

class BrickWall
{
private:

	std::vector<Brick> wall;
	int bricksDestroyed = 0;
	bool firstOrange {true};
	bool firstRed{ true };

	Brick lastBrickDestroyed {0, 0, 0, 0, Brick::level::Yellow};

public:

	BrickWall(std::vector<Brick>& w);

	void drawBricks();

	int getBricksDestroyed() const;
	Brick getLastDestroyedBrick() const;

	void resizeWalls(const std::vector<Brick>& w);

	void checkCollision(Ball& ball, Player& player);
};
