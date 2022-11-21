#pragma once

#include "point.h"
#include "paddle.h"
#include "ofGraphics.h"

/**
 * \brief Player class which is used to contain all of the information of the player
 *		derived from Paddle in paddle.h
 */
class Player : public Paddle
{
private:
	double speed;
	double points = 0;
	bool isHalf = false;
	ofColor playerColor;

public:

	/**
	* \brief Constructor using Point from point.h
	* \param c Coordinates x,y
	* \param si Size x,y
	* \param sp Horizontal Speed
	*/
	Player(const Point &c, const Point &si, double sp);

	/**
	* \brief Constructor using doubles
	* \param cx Coordinate x
	* \param cy Coordinate y
	* \param six Size x
	* \param siy Size y
	* \param sp Horizontal Speed
	*/
	Player(double cx, double cy, double six, double siy, double sp);

	/**
	* \brief Move the player Left and Right on the X axis
	* \param moveLeft know if player is moving left
	*/
	void move(bool moveLeft);

	/**
	 * \brief Move the player to a new X position
	 * \param x New X position of type int
	 */
	void move(int x);

	/**\brief Decrease the player's size by half only Once */
	void half();

	/**
	*\brief Draw the player as a rectangle on
	*		the canvas using Coordinate and Size
	*/
	void drawPlayer() const;

	/**
	 * \brief Check if the ball is colliding with the palyer
	 * \param ball Object of type Ball from ball.h
	 */
	void checkCollision(Ball& ball) const;

};