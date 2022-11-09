#pragma once

#include "ofMain.h"
#include "point.h"
#include "brick.h"
#include "ball.h"
#include "brickWall.h"
#include "player.h"


//class player
//{
//	Point coordinate;
//	int size;
//	bool isHalf{ false };
//};


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


	Point co{ 500, 500 };
	Point spe{ 10, -10 };

	Ball ball{ co, spe, 5 };

	//Player player{ 2, 3, 100, 100, 5 };
	
	Point co0{ 0, 0 };
	Point spee{ ofGetWidth() / 14, 20 };
	Brick b1{ co, spe, Brick::level::Green };

	Point cop{ ofGetWidth() / 14 + 2 , 0 };
	Point spep{ ofGetWidth() / 14, 20 };
	Brick b2{ cop, spep, Brick::level::Green };

	Point copp{ (ofGetWidth() / 14) * 2 + 2, 0 };
	Point spepp{ ofGetWidth() / 14, 20 };
	Brick b3{ copp, spepp, Brick::level::Green };

	std::vector<Brick> walls {b1, b2, b3};

	BrickWall brickWall{walls};

};