#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	initialize();
}

void ofApp::resetBricks(std::vector<Brick>& bricks)
{
	bricks.clear();

	for (auto walling{ 0 }; walling < 8; ++walling)
	{
		Brick::level lvl;
		switch (walling)
		{
		case 0:
		case 1:
			lvl = Brick::level::Red;
			break;

		case 2:
		case 3:
			lvl = Brick::level::Orange;
			break;

		case 4:
		case 5:
			lvl = Brick::level::Green;
			break;

		case 6:
		case 7:
			lvl = Brick::level::Yellow;
			break;
		}

		for (auto i{ 0 }; i < 14; ++i)
		{
			Point coordiante{ ((ofGetWidth() / 14.0) * i) + 3, (20.0 * walling) };
			Point size{ (ofGetWidth() / 15.0) , 10.0};

			bricks.emplace_back(coordiante, size, lvl);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (gameRules.getIsPlaying())
	{
		ball.move();
		brickWall.checkCollision(ball, player);
		player.checkCollision(ball);
		gameRules.update(brickWall, ball, player);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{

	if (gameRules.getIsPlaying())
	{
		player.drawPlayer();
		brickWall.drawBricks();
		ball.drawBall();
		gameRules.showStats();
	}
	else
	{
		gameRules.displayScreen(displayInstruction);

		if(playGame)
		{
			resetBricks(walls);
			brickWall.resizeWalls(walls);

			gameRules.startGame();

			initialize();

			displayInstruction = false;
			
		}

		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	if (key == 'a' || key == 'A')
	{
		player.move(true);
	}

	if (key == 'd' || key == 'D')
	{
		player.move(false);
	}

	if (!gameRules.getIsPlaying() && (key == 'i' || key == 'I'))
	{
		displayInstruction = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if(gameRules.getIsPlaying())
	{
		player.move(mouseX);
	}	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}