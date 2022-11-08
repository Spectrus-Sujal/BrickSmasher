
#include "player.h"

Player::Player(const Point& c, const Point& si, int sp) : coordinate{c}, size {si}, speed {sp} {}

Player::Player(int cx, int cy, int six, int siy, int sp)
{
	coordinate.x = cx;
	coordinate.y = cy;
	size.x = six;
	size.y = siy;
	speed = sp;
}

void Player::move(bool moveLeft)
{
	int direction = 1;

	if(moveLeft)
	{
		direction = -1;
	}

	coordinate.x += speed * direction;
}

void Player::half()
{
	if(!isHalf)
	{
		size.x /= 2;
		isHalf = true;
	}
}

void Player::drawPlayer() const
{
	ofDrawRectangle(coordinate.x, coordinate.y, size.x, size.y);
}

