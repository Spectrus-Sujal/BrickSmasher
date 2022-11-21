#pragma once

#include "brick.h"
#include "ball.h"

/**
 * \brief Varrying size array of Bricks from brick.h
 */
class BrickWall
{
private:
	/**\brief Collection of Bricks*/
	std::vector<Brick> wall;
	/**\brief Amount of Bricks removed from wall */
	int bricksDestroyed = 0;

	/**\brief Value of the last Brick removed from wall */
	Brick lastBrickDestroyed {0, 0, 0, 0, Brick::level::Yellow};

public:

///////////////// Constructors ///////////////////////

	/**
	 * \brief Constructor for BrickWall
	 * \param w Vector of type Brick from brick.h
	 */
	BrickWall(std::vector<Brick>& w);

	/**\brief Draw Bricks in wall onto the canvas */
	void drawBricks();

	/**
	 * \brief Access the amount of Bricks missing from wall
	 * \return Value of type int
	 */
	int getBricksDestroyed() const;

	/**
	 * \brief Access the last Brick removed from wall
	 * \return Value of type Brick
	 */
	Brick getLastDestroyedBrick() const;

	/**
	 * \brief Replace wall with a new vector
	 * \param w vector of type Brick
	 */
	void resizeWalls(const std::vector<Brick>& w);

	/**
	 * \brief Check if the ball is colliding with any Bricks present in wall
	 * \param ball Variable of type Ball from ball.h
	 */
	void checkCollision(Ball& ball);
};
