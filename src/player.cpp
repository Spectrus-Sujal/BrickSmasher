
#include "player.h"

/**
 * \brief Constructor for Player using Point from point.h
 * \param c Coordinates x,y
 * \param si Size x,y
 * \param sp Horizontal Speed
 */
Player::Player(const Point& c, const Point& si, int sp) : coordinate{c}, size {si}, speed {sp} {}

/**
 * \brief Constructor for Player using only ints
 * \param cx Coordinate x
 * \param cy Coordinate y
 * \param six Size x
 * \param siy Size y
 * \param sp Horizontal Speed
 */
Player::Player(int cx, int cy, int six, int siy, int sp)
{
	coordinate.x = cx;
	coordinate.y = cy;
	size.x = six;
	size.y = siy;
	speed = sp;
}

/**
 * \brief Move the player on the Left and Right on the X axis
 * \param moveLeft is used to know is the player is moving right of left
 */
void Player::move(bool moveLeft)
{
	int direction = 1;

	if(moveLeft)
	{
		direction = -1;
	}

	coordinate.x += speed * direction;
}

/**
 * \brief Method used to decrease the player's size by half
 */
void Player::half()
{
	if(!isHalf)
	{
		size.x /= 2;
		isHalf = true;
	}
}

/**
 * \brief Draw the player as a rectangle on the canvas using Coordinate and Size
 */
void Player::drawPlayer() const
{
	ofSetColor(playerColor);
	ofDrawRectangle(coordinate.x, coordinate.y, size.x, size.y);
}

int Player::getPoints() const
{
	return points;
}

void Player::increasePoints(int delta)
{
	points += delta;
}

