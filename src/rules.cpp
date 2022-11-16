
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
	endStatus = "Lost\n";
	isPlaying = false;
}

void Rules::winGame()
{
	endStatus = "Won\n";
	isPlaying = false;
}

void Rules::increasePoints(int delta)
{
	points += delta;
}

void Rules::showStats() const
{
	ofDrawBitmapString("Scores: " + std::to_string(points), 0, ofGetHeight() * 0.90);
	ofDrawBitmapString("Lives: " + std::to_string(lives), 0, ofGetHeight() * 0.95);
}

void Rules::displayScreen() const
{
	ofDrawBitmapString("You have " + endStatus, ofGetWidth() * 0.45, ofGetHeight() * 0.40);
	ofDrawBitmapString("Press S to start the game", ofGetWidth() * 0.25, ofGetHeight() * 0.70);
	ofDrawBitmapString("Press I to see Instructions", ofGetWidth() * 0.55, ofGetHeight() * 0.70);	
}

void Rules::startGame()
{
	isPlaying = true;
	points = 0;
	lives = 3;
	destroyedBricks = 0;
	firstTopBounce = true;
	firstOrange = true;
	firstRed = true;
}

