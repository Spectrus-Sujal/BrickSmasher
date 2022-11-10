#pragma once

#include "brick.h"
#include "ball.h"
#include "player.h"
#include "ofGraphics.h"

class BrickWall
{
private:

	std::vector<Brick> wall;
	int bricksDestroyed = 0;
	bool firstOrange {true};
	bool firstRed{ true };

public:

	BrickWall(std::vector<Brick>& w);

	void drawBricks();

	int getBricksDestroyed() const;

	void resizeWalls(const std::vector<Brick>& w);

	void checkCollision(Ball& ball, Player& player);
};
