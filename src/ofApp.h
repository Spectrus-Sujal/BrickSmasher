#pragma once

#include "ofMain.h"
#include "point.h"
#include "brick.h"
#include "ball.h"
//#include "brickWall.h"
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
	Point spe{ 3, 3 };

	//Ball balling{ co, spe, 5 };

	Player player{ 2, 3, 100, 100, 5 };

	//Brick b1{ co, spe, Brick::level::Green };

	//Point cop{ 400, 100 };
	//Point spep{ 80, 10 };
	//Brick b2{ cop, spep, Brick::level::Green };

	//Point copp{ 600, 200 };
	//Point spepp{ 80, 10 };
	//Brick b3{ copp, spepp, Brick::level::Green };

	//std::vector<Brick> wa{ b1, b2, b3 };

	//BrickWall bw{ wa};

};