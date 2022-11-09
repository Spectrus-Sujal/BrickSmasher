#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	walls.clear();

	for(auto walling {0}; walling < 8; ++walling)
	{
		for (auto i{ 0 }; i < 14; ++i)
		{
			Point coordiante{ ((ofGetWidth() / 14) * i) + 10, (20 * walling)};
			Point size{ 50, 10 };
			walls.emplace_back(coordiante, size, Brick::level::Red);
		}
	}

	brickWall.resizeWalls(walls);
}

//--------------------------------------------------------------
void ofApp::update()
{
	ball.move();
	brickWall.checkCollision(ball);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//player.drawPlayer();
	brickWall.drawBricks();
	ball.drawBall();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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