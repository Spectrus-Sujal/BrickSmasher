#pragma once

#include "paddle.h"

/**
 * \brief The rectangular Brick that the player will try to destroy
 *		and earn points from
 *		Derives behavior from class Paddle in paddle.h
 */
class Brick : public Paddle
{
public:
	/**
	 * \brief An Enum which defines the color and importance of the Brick,
	 * Yellow being the lowest and Red being the highest
	 */
	enum class level
	{
		Yellow, Green, Orange, Red
	};

private:
	/**\brief The level of this Brick*/
	level lvl;

public:

//////////////////// Constructor //////////////////////////
	/**
	 * \brief Constructor for Brick using Point from point.h
	 * \param c Top left coordinate
	 * \param s Size
	 * \param l Level
	 */
	Brick(Point c, Point s, level l);

	/**
	 * \brief Constructor for Brick using doubles
	 * \param cx X coordinate
	 * \param cy Y coordinate
	 * \param six Width
	 * \param siy Length
	 * \param l Level
	 */
	Brick(double cx, double cy, double six, double siy, level l);

////////////////////Accessors///////////////////////////////

	/**
	 * \brief Access the level of this Brick
	 * \return Value of type level
	 */
	level getLvl() const;

	/**
	 * \brief Color based on the Brick Level
	 * \return Value of type ofColor
	 */
	ofColor getBrickColor() const;

	/**
	 * \brief Points based on the Brick Level
	 * \return Value of type int
	 */
	int getPoints() const;
	
};