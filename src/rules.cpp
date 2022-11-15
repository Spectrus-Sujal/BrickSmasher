
#include "rules.h"

Rules::Rules(){}

void Rules::update(BrickWall& bw, Ball& ball, Player& player)
{
	checkBall(ball, player);

	if(destroyedBricks != bw.getBricksDestroyed())
	{
		checkBricks(bw, ball, player);
	}

	checkState();
}

void Rules::checkBall(Ball& ball, Player& player)
{
	if (firstTopBounce && ball.getY() - ball.getRadius() <= 0)
	{
		player.half();
		firstTopBounce = false;
	}

	if(ball.getY() + ball.getRadius() >= ofGetHeight())
	{
		lives--;
		ball.spawnBall(ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

void Rules::checkBricks(BrickWall& bw, Ball& ball,Player& player)
{
	destroyedBricks = bw.getBricksDestroyed();

	if (destroyedBricks < 13)
	{
		switch (destroyedBricks)
		{
			case 4:
			case 12:
				ball.increaseSpeed();
				break;
		}
	}

	if (firstOrange && bw.getLastDestroyedBrick().getLvl() == Brick::level::Orange)
	{
		ball.increaseSpeed();
		firstOrange = false;
	}
	else if (firstRed && bw.getLastDestroyedBrick().getLvl() == Brick::level::Red)
	{
		ball.increaseSpeed();
		firstRed = false;
	}

	increasePoints(bw.getLastDestroyedBrick().getPoints());
}

bool Rules::getIsPlaying() const
{
	return isPlaying;
}


void Rules::checkState()
{
	if(lives <= 0)
	{
		loseGame();
	}

	if(destroyedBricks >= 112)
	{
		winGame();
	}
}

void Rules::loseGame()
{
	std::cout << "Game Lost \n";
	isPlaying = false;
}

void Rules::winGame()
{
	std::cout << "Game Won\n";
	isPlaying = false;
}

void Rules::increasePoints(int delta)
{
	points += delta;
}
