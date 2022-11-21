
#include "brickWall.h"

BrickWall::BrickWall(std::vector<Brick> &w) : wall{ w } {}

void BrickWall::drawBricks()
{
	// Go through each Brick in wall
	for each (Brick b in wall)
	{
		// Get the color
		ofSetColor(b.getBrickColor());
		// Draw a rectangle from the top left
		ofDrawRectangle(b.getX(), b.getY(), b.getSizeX(), b.getSizeY());
	}
}

void BrickWall::checkCollision(Ball &ball)
{
	// Loop through every Brick
	for (auto b{ 0 }; b < wall.size(); ++b)
	{
		// Check if the ball is colliding with anything
		if (wall[b].checkCollision(ball))
		{
			// Bounce the ball using doCollision in paddle.h
			wall[b].doCollision(ball);

			// Increment the amount of Bricks Destroyed
			bricksDestroyed++;

			// Update lastBrickDestroyed
			lastBrickDestroyed = wall[b];

			// Remove the Brick
			wall.erase(wall.begin() + b);

			// top the loop
			break;
		}
	}
}

Brick BrickWall::getLastDestroyedBrick() const
{
	return lastBrickDestroyed;
}

bool BrickWall::allBricksDestroyed() const
{
	return wall.size() <= 0;
}

void BrickWall::resizeWalls(const std::vector<Brick>& w)
{
	// Assign w to wall
	wall = w;
}

int BrickWall::getBricksDestroyed() const
{
	return bricksDestroyed;
}