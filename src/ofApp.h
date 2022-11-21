/*
* 
*	A recreation of the classic Brick Breaker game made using Open FrameWorks
*	with custom rules added to make the game feel more challenging
* 
*	- by Sujal Naroia
*
*/

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

	// Assign new values to bricks
	void resetBricks(std::vector<Brick>& bricks);

/////////////// Declare all variables //////////////
	// Assigned valus for Ball
	Point ballCoord{ 500, 500 };
	Point ballSpeed{ 2, -2 };
	double ballSize{ 5 };

	// Create the Ball
	Ball ball{ ballCoord, ballSpeed, ballSize };

	// Vector of type Brick used for BrickWall
	std::vector<Brick> walls;

	// BrickWall with walls as constructor
	BrickWall brickWall{walls};

	// Values for Player
	double playerStart{500};
	double playerSizeX{100};
	double playerSizeY{20};
	double playerSpeed{ 20 };

	// Make Player
	Player player {playerStart, ofGetHeight() - playerSizeY, playerSizeX, playerSizeY, playerSpeed};

	// Make Rules
	Rules gameRules {};

	// Create the GUI elements
	ofxButton playGame;
	ofxPanel gui;

	// Reassign values for all game variable
	void initialize()
	{
		brickWall = BrickWall{ walls };
		ball = Ball{ ballCoord, ballSpeed, ballSize };
		player = Player{ playerStart, ofGetHeight() - playerSizeY, playerSizeX, playerSizeY, playerSpeed };
		gui.setup();
		gui.add(playGame.setup("Play"));
	}

	// Keep track of Instructions
	bool displayInstruction{ false };

};