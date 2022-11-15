#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	resetBricks(walls);

	brickWall.resizeWalls(walls);
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
			Point coordiante{ ((ofGetWidth() / 14) * i) + 3, (20 * walling) };
			Point size{ (ofGetWidth() / 15) , 10 };

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
	player.drawPlayer();
	brickWall.drawBricks();
	ball.drawBall();
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
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

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