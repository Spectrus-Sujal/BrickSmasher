
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

void BrickWall::checkCollision(Ball &ball)
{
	for (auto b{ 0 }; b < wall.size(); ++b)
	{
		bool first = (ball.getX() + ball.getRadius() >= wall[b].getX()) && (ball.getY() + ball.getRadius() >= wall[b].getY());
		bool second = (ball.getX() - ball.getRadius() <= wall[b].getX() + wall[b].getSizeX()) && (ball.getY() - ball.getRadius() <= wall[b].getY() + wall[b].getSizeY());

		if (first && second)
		{
			if(ball.getX() + ball.getRadius() > wall[b].getX() + wall[b].getSizeX())
			{
				ball.flipX();
			}
			else if (ball.getX() - ball.getRadius() < wall[b].getX())
			{
				ball.flipX();
			}

			if (ball.getY() + ball.getRadius() > wall[b].getY() + wall[b].getSizeY())
			{
				ball.flipY();
			}
			else if (ball.getY() - ball.getRadius() < wall[b].getY())
			{
				ball.flipY();
			}

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
