#pragma once

#include "ofMain.h"
#include "point.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#include "brickWall.h"
#include "player.h"


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
	Point spe{ 2, -2 };

	Ball ball{ co, spe, 5 };

	std::vector<Brick> walls;

	BrickWall brickWall{walls};

	Player player {500, ofGetHeight() - 20, 100, 20, 20};

};