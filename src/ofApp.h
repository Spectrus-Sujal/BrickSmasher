#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "point.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#include "brickWall.h"
#include "player.h"
#include "rules.h"


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

	void resetBricks(std::vector<Brick>& bricks);


	Point coord{ 500, 500 };
	Point speed{ 2, -2 };
	double ballSize{ 5 };

	Ball ball{ coord, speed, ballSize };

	std::vector<Brick> walls;

	BrickWall brickWall{walls};

	double playerStart{500};
	double playerSizeX{100};
	double playerSizeY{20};
	double playerSpeed{ 20 };

	Player player {playerStart, ofGetHeight() - playerSizeY, playerSizeX, playerSizeY, playerSpeed};

	Rules gameRules {};

	ofxButton playGame;
	ofxPanel gui;

	void initialize()
	{
		brickWall = BrickWall{ walls };
		ball = Ball{ coord, speed, ballSize };
		player = Player{ playerStart, ofGetHeight() - playerSizeY, playerSizeX, playerSizeY, playerSpeed };
		gui.setup();
		gui.add(playGame.setup("Play"));
	}

	bool displayInstruction{ false };

};