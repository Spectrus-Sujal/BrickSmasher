#pragma once

#include "point.h"
#include "ball.h"

/**
 * \brief A class that contains the X and Y position of an object
 *		as well as its size which can be used to check and
 *		do collisions
 */
class Paddle
{
private:
	/**
	 * \brief X and Y position
	 */
	Point coordinate;

	/**
	 * \brief Width and Height
	 */
	Point size;

public:

////////////// Constructors ///////////////////////
	/**
	 * \brief Constructor using Point from point.h
	 * \param c X and Y position
	 * \param s Width and Height
	 */
	Paddle(Point c, Point s);

	/**
	 * \brief Constructor using doubles
	 * \param cx X position
	 * \param cy Y position
	 * \param six Width
	 * \param siy Height
	 */
	Paddle(double cx, double cy, double six, double siy);

////////////// Getters ///////////////////////
	/**
	 * \brief Get the X position of Paddle
	 * \return Value of type double
	 */
	double getX() const;

	/**
	 * \brief Get the Y position of Paddle
	 * \return Value of type double
	 */
	double getY() const;

	/**
	 * \brief Get the Width of Paddle
	 * \return Value of type double
	 */
	double getSizeX() const;

	/**
	 * \brief Get the Height of Paddle
	 * \return Value of type double
	 */
	double getSizeY() const;

	/**
	 * \brief Move the Paddle horizontally
	 * \param delta Change in X position
	 */
	void changeX(int delta);

	/**
	 * \brief Change the Paddle Width
	 * \param delta Change in Width
	 */
	void changeSizeX(int delta);

////////////// Collision ///////////////////////
	/**
	 * \brief Check whether the ball is colliding with the Paddle
	 * \param ball Object of type Ball from ball.h
	 * \return if Paddle and ball are colliding
	 */
	bool checkCollision(const Ball& ball) const;

	/**
	 * \brief Change the ball speed based on where it
	 *		collided with the Paddle to simulate a bounce
	 * \param ball Object of type Ball from ball.h
	 */
	void doCollision(Ball& ball) const;

};