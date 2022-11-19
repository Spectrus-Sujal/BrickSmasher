#pragma once

#include "point.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

/**
 * \brief The Ball that will be used by the player to destroy the bricks
 * and also the one which the player will have to stop from
 * touching the ground
 */
class Ball
{
private:
	// Variables used to determine the balls default values

	/** \brief X and Y location of the Ball*/
	Point coordinate;

	/** \brief X and Y speed of the Ball*/
	Point speed;

	/**\brief Radius of the Ball */
	double radius;

	//method to check if the ball has hit an edge
	/**
	 * \brief Internal method used to bounce
	 *	the ball off the map's edges
	 */
	void bounce();

public:

	///////////// Constructors/////////////
/// <summary>
/// Constructor using Point from point.h
/// </summary>
/// <param name="c">Center X and Y coordinate for the Ball</param>
/// <param name="s">X and Y speed the Ball moves</param>
/// <param name="r">Radius of the Ball</param>
	Ball(const Point &c, const Point &s, double r);


/// <summary>
/// Constructor using doubles
/// </summary>
/// <param name="cx">Center X for the Ball</param>
/// <param name="cy">Center Y for the Ball</param>
/// <param name="sx">X speed of the Ball</param>
/// <param name="sy">Y speed of the Ball</param>
/// <param name="r">Radius of the Ball</param>
	Ball(double cx, double cy, double sx, double sy, double r);


/**\brief Method used to draw the Ball on the canvas*/
	void drawBall() const;

	////////////Accessors for private values////////////
/**
 * \brief Get the X coordinate of the Ball
 * \return value of type double
 */
	double getX() const;

/**
 * \brief Get the Y coordinate of the Ball
 * \return value of type double
 */
	double getY() const;

/**
 * \brief Get the Radius of the Ball
 * \return value of type double
 */
	double getRadius() const;


	/**
	 *\brief Move the Ball Horizontally by Speed.x and
	 *	vertically by Speed.y
	 */
	void move();

	/**\brief Move the Ball in the opposite vertical direction*/
	void flipY();

	/**\brief Move the Ball in the opposite horizontal direction*/
	void flipX();

	/**\brief Increase the base speed of the Ball by 20% */
	void increaseSpeed();

	/**
	 * \brief Change the coordinates of the Ball
	 * \param x New X coordinate
	 * \param y New Y coordinate
	 */
	void spawnBall(const int x, const int y);
};