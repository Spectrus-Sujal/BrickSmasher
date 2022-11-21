
#include "rules.h"

Rules::Rules(){}

void Rules::update(BrickWall& bw, Ball& ball, Player& player)
{
	// Check the balls new position
	checkBall(ball, player);

	// Check if a brick was destroyed
	if(destroyedBricks != bw.getBricksDestroyed())
	{
		checkBricks(bw, ball, player);
	}

	// Check if the game has ended
	checkState();
}

// Check if the ball meets any conditions
// If so then update the other objects in the game

void Rules::checkBall(Ball& ball, Player& player)
{
	// Check if this is the first time the ball is bouncing at the top edge
	if (firstTopBounce && ball.getY() - ball.getRadius() <= 0)
	{
		// Half the player size
		player.half();
		// Make sure this condition doesn't trigger again
		firstTopBounce = false;
	}

	// Check if the ball has touched the bottom
	if(ball.getY() + ball.getRadius() >= ofGetHeight())
	{
		// Decrement the lives
		lives--;
		// Respawn the ball
		ball.spawnBall(ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

void Rules::checkBricks(BrickWall& bw, Ball& ball,Player& player)
{
	// Update the amount of destroyed bricks
	destroyedBricks = bw.getBricksDestroyed();

	// Check if a milestone is reached
	if (destroyedBricks < 13)
	{
		switch (destroyedBricks)
		{
			case 4:
			case 12:
				// Update the ball speed every time
				ball.increaseSpeed();
				break;
		}
	}

	// Check if a certain brick is destroyed for the first time
	if (firstOrange && bw.getLastDestroyedBrick().getLvl() == Brick::level::Orange)
	{
		// Increase the ball speed
		ball.increaseSpeed();
		// Make sure it doesn't repeat
		firstOrange = false;
	}
	else if (firstRed && bw.getLastDestroyedBrick().getLvl() == Brick::level::Red)
	{
		ball.increaseSpeed();
		firstRed = false;
	}

	// Increase points based on destroyed brick
	increasePoints(bw.getLastDestroyedBrick().getPoints());
}

bool Rules::getIsPlaying() const
{
	return isPlaying;
}


void Rules::checkState()
{
	// Check if the game is ending
	if(lives <= 0)
	{
		// Call a method based on how it ended
		loseGame();
	}

	if(destroyedBricks >= 112)
	{
		winGame();
	}
}

void Rules::loseGame()
{
	// Change the end Satus and end the game
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
	// Display a tect message stating the Point and Lives
	// In the bottom left corner
	ofDrawBitmapString("Scores: " + std::to_string(points), 0, ofGetHeight() * 0.90);
	ofDrawBitmapString("Lives: " + std::to_string(lives), 0, ofGetHeight() * 0.95);
}

void Rules::displayScreen(bool instructions) const
{
	// Check if instructions are being displayed or not
	if(instructions)
	{
		displayInstructions();
	}
	else
	{
		ofDrawBitmapString("You have " + endStatus, ofGetWidth() * 0.45, ofGetHeight() * 0.40);
		ofDrawBitmapString("Press Play to start the game", ofGetWidth() * 0.25, ofGetHeight() * 0.70);
		ofDrawBitmapString("Press I to see Instructions", ofGetWidth() * 0.65, ofGetHeight() * 0.70);
	}
}

void Rules::displayInstructions() const
{
	// Show the Instructions
	ofDrawBitmapString("Use A and D to move the paddle left and right ", ofGetWidth() * 0.20, ofGetHeight() * 0.10);
	ofDrawBitmapString("You can also move the mouse to move the paddle left and right", ofGetWidth() * 0.20, ofGetHeight() * 0.30);
	ofDrawBitmapString("Try to destroy all the bricks by bouncing the ball off of the paddle", ofGetWidth() * 0.20, ofGetHeight() * 0.50);
	ofDrawBitmapString("Make sure to not let the ball touch the ground as you will lose a life", ofGetWidth() * 0.20, ofGetHeight() * 0.70);
	ofDrawBitmapString("Press Play to start the game", ofGetWidth() * 0.20, ofGetHeight() * 0.90);
}


void Rules::startGame()
{
	// Reset all the values
	isPlaying = true;
	points = 0;
	lives = 3;
	destroyedBricks = 0;
	firstTopBounce = true;
	firstOrange = true;
	firstRed = true;
}

