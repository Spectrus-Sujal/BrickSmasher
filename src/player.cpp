
#include "player.h"

/**
 * \brief Constructor for Player using Point from point.h
 * \param c Coordinates x,y
 * \param si Size x,y
 * \param sp Horizontal Speed
 */
Player::Player(const Point& c, const Point& si, double sp) : Paddle{c, si}, speed{sp} {}

/**
 * \brief Constructor for Player using only ints
 * \param cx Coordinate x
 * \param cy Coordinate y
 * \param six Size x
 * \param siy Size y
 * \param sp Horizontal Speed
 */
Player::Player(double cx, double cy, double six, double siy, double sp) : Paddle { cx, cy, six, siy }
{
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

	changeX(speed * direction);

	if (getX() < 0)
	{
		changeX(0 - getX());
	}

	if (getX() + getSizeX() > ofGetWidth())
	{
		changeX(ofGetWidth() - (getX() + getSizeX()));
	}

}

void Player::move(int x)
{
	if ((x + (getSizeX() / 2) <= ofGetWidth()) && x - (getSizeX() / 2) >= 0)
	{
		changeX(x - (getX() + getSizeX() / 2));
	}
}


/**
 * \brief Method used to decrease the player's size by half
 */
void Player::half()
{
	if(!isHalf)
	{
		changeSizeX( -(getSizeX() / 2));
		isHalf = true;
	}
}

/**
 * \brief Draw the player as a rectangle on the canvas using Coordinate and Size
 */
void Player::drawPlayer() const
{
	ofSetColor(playerColor);
	ofDrawRectangle(getX(), getY(), getSizeX(), getSizeY());
}

void Player::checkCollision(Ball& ball)
{
	if (Paddle::checkCollision(ball))
	{
		Paddle::doCollision(ball);
	}
}
