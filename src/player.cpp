
#include "player.h"

// Call the constructor from Paddle in paddle.h
Player::Player(const Point& c, const Point& si, double sp) : Paddle{c, si}, speed{sp} {}

Player::Player(double cx, double cy, double six, double siy, double sp) : Paddle { cx, cy, six, siy }
{
	speed = sp;
}

void Player::move(bool moveLeft)
{
	int direction = 1;

	// Check if the player is moving left
	if(moveLeft)
	{
		direction = -1;
	}

	// Call changeX in Paddle
	// Change in X being based on direction adn speed
	changeX(speed * direction);

	// Reset the Player X if it is further than the edge
	if (getX() < 0)
	{
		// Change it based on how much left edge exceeds 0
		changeX(0 - getX());
	}

	if (getX() + getSizeX() > ofGetWidth())
	{
		// Change based on how much the right edge exceeds the Width
		changeX(ofGetWidth() - (getX() + getSizeX()));
	}

}

void Player::move(int x)
{
	// Get the center X of the player
	int halfSize = (getSizeX() / 2);

	// Change the X based on the center
	changeX(x - (getX() + halfSize));

	// Check is the new Player X is within the the canvas bounds
	if (x + halfSize >= ofGetWidth()) changeX(ofGetWidth() - (x + halfSize));
	else if (x - halfSize <= 0) changeX(0 - (x - halfSize));

}

void Player::half()
{
	// Check if size was already half before
	if(!isHalf)
	{
		// Call changeSizeX from Paddle
		changeSizeX( -(getSizeX() / 2));
		// Set isHalf to true
		isHalf = true;
	}
}

void Player::drawPlayer() const
{
	// Set the Color of the player
	ofSetColor(playerColor);
	// Draw the player from the top left
	ofDrawRectangle(getX(), getY(), getSizeX(), getSizeY());
}

void Player::checkCollision(Ball& ball) const
{
	// Call checkCollisions from Paddle
	if (Paddle::checkCollision(ball))
	{
		// Call doCollisions in Paddle
		doCollision(ball);
	}
}
