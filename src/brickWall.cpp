
#include "brickWall.h"

BrickWall::BrickWall(std::vector<Brick> &w) : wall{ w } {}

void BrickWall::drawBricks()
{
	for each (Brick b in wall)
	{
		ofDrawRectangle(b.getX(), b.getY(), b.getSizeX(), b.getSizeY());
	}
}

void BrickWall::checkCollision(Ball &ball)
{
	for (auto b{ 0 }; b < wall.size(); ++b)
	{
		bool first = (ball.getX() >= wall[b].getX()) && (ball.getY() >= wall[b].getY());
		bool second = (ball.getX() <= wall[b].getX() + wall[b].getSizeX()) && (ball.getY() <= wall[b].getY() + wall[b].getSizeY());

		if (first && second)
		{
			wall.erase(wall.begin() + b);
			break;
		}
	}
}

void BrickWall::resizeWalls(const std::vector<Brick>& w)
{
	wall = w;
	std::cout << "done\n";
}
