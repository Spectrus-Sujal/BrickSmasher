#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// Assign all values
	initialize();
}

void ofApp::resetBricks(std::vector<Brick>& bricks)
{
	// Make sure it's empty
	bricks.clear();

	// Start to assign new values
	for (auto walling{ 0 }; walling < wallLength; ++walling)
	{
		// Assign a level based on the vertical position
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
		default:
			lvl = Brick::level::Yellow;
			break;
		}

		for (auto i{ 0 }; i < wallWidth; ++i)
		{
			// Make a new Brick object
			Point coordiante{ ((ofGetWidth() / wallWidth) * i) + 3, (20.0 * walling) };
			Point size{ (ofGetWidth() / (wallWidth + 1)) , 10.0};

			// Declare and add it to the end of bricks
			bricks.emplace_back(coordiante, size, lvl);
		}
	}

}

//--------------------------------------------------------------
void ofApp::update()
{
	// Game has not ended
	if (gameRules.getIsPlaying())
	{
		// Update all variables
		ball.move();
		brickWall.checkCollision(ball);
		player.checkCollision(ball);
		gameRules.update(brickWall, ball, player);
	}
	else
	{
		gui.setPosition(ofGetWidth() * 0.25, ofGetHeight() * 0.75);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// Game not ended
	if (gameRules.getIsPlaying())
	{
		// Draw the game components
		player.drawPlayer();
		brickWall.drawBricks();
		ball.drawBall();
		gameRules.showStats();
	}
	else
	{
		// Dispaly the Start menu or instructions
			// Based on displayInstruction

		gameRules.displayScreen(displayInstruction);

		// if play is pressed
		if(playGame)
		{
			// Reset all variables
			resetBricks(walls);
			brickWall.resizeWalls(walls);

			gameRules.startGame();

			initialize();

			displayInstruction = false;
			
		}

		// Draw the GUI
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	// Move the player based on user input
	if (key == 'a' || key == 'A')
	{
		player.move(true);
	}

	if (key == 'd' || key == 'D')
	{
		player.move(false);
	}

	// If given the input, Display the instructions if game is not playing
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
	// If game is still playing
	if(gameRules.getIsPlaying())
	{
		// Move the player to Mouse X position
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