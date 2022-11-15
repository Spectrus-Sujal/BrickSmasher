#pragma once

#include "ball.h"
#include "player.h"
#include "brick.h"
#include "brickWall.h"
#include "ofGraphics.h"

class Rules
{
private:

	bool isPlaying {true};

	bool firstTopBounce{ true };

	int destroyedBricks{ 0 };

	bool firstOrange {true};
	bool firstRed {true};

	int lives{ 3 };

	void checkBall(Ball& ball, Player& player);
	void checkBricks(BrickWall& bw, Ball& ball);
	void checkState();

	void loseGame();
	void winGame();

public:

	Rules();

	bool getIsPlaying() const;

	void update(BrickWall& bw, Ball& ball, Player& player);

};