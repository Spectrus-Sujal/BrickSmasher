
#include "brickWall.h"

BrickWall::BrickWall(std::vector<Brick> &w) : wall{ w } {}

void BrickWall::drawBricks()
{
	for each (Brick b in wall)
	{
		ofSetColor(b.getBrickColor());
		ofDrawRectangle(b.getX(), b.getY(), b.getSizeX(), b.getSizeY());
	}
}

void BrickWall::checkCollision(Ball &ball, Player& player)
{
	for (auto b{ 0 }; b < wall.size(); ++b)
	{
		if (wall[b].checkCollision(ball))
		{
			wall[b].doCollision(ball);

			player.increasePoints(wall[b].getPoints());

			bricksDestroyed++;

			lastBrickDestroyed = wall[b];

			wall.erase(wall.begin() + b);
			break;
		}
	}
}

Brick BrickWall::getLastDestroyedBrick() const
{
	return lastBrickDestroyed;
}

void BrickWall::resizeWalls(const std::vector<Brick>& w)
{
	wall = w;
	std::cout << "done\n";
}

int BrickWall::getBricksDestroyed() const
{
	return bricksDestroyed;
}