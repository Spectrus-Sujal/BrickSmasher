#pragma once

#include "ball.h"
#include "player.h"
#include "brickWall.h"

/**
 * \brief A Class that contains all the rules that dictate the flow of this game.
 *		This includes all the conditions that need to be fulfilled in order for certain
		events to change what happens in the game; This includes the game Starting, Ending, 
		the ball getting faster and the player's size decreasing.
 */
class Rules
{
private:

	/**
	* \brief The first time the ball bounces
			off of this
	*/
	bool firstOrange {true}, firstRed {true}, firstTopBounce{ true };

	/**
	* \brief Current state of the game
	*/
	bool isPlaying {false};

	/**
	* \brief Number of Bricks the player has sestroyed
	*/
	int destroyedBricks{ 0 };

	/**
	* \brief The players points based on number and
		kind of Bricks destroyed
	*/
	int points{ 0 };

	/**
	* \brief Lives left of player
	*/
	int lives{ 3 };

	/**
	* \brief Which state the game ended
	*/
	std::string endStatus{ "Begun" };

	/**
	* \brief Increase the players points
	* \param delta: Change in points
	*/
	void increasePoints(int delta);

	/**
	* \brief Check if any conditions are met
	* \param ball: Object of type Ball from ball.h
	* \param player: Object of type Player from player.h
	*/
	void checkBall(Ball& ball, Player& player);

	/**
	* \brief Check if the Bricks fullfill and conditions
	* \param bw: Object of type BrickWall from brickWall.h
	* \param ball: Object of type Ball from ball.h
	* \param player: Object of type PLayer from player.h
	*/
	void checkBricks(BrickWall& bw, Ball& ball, Player& player);

	/**
	* \brief Check if the game has ended and if so
	*		has the player won or lost
	*/
	void checkState();

	/**
	* \brief Change end and game status
	*/
	void loseGame(), winGame();

public:

////////////////// Constructor //////////////

	/**
	* \brief Default Constructor
	*/
	Rules();

////////////////// Getters //////////////////	

	/**
	* \brief Get whether the game is still going or no
	* \return Value of type bool
	*/
	bool getIsPlaying() const;

	/**
	* \brief Display points and lives on the Canvas
	*/
	void showStats() const;

	/**
	* \brief Display Start Screen
	* \param instructions: Change to instruction screen
	*/
	void displayScreen(bool instructions) const;

	/**
	* \brief Display Instrcution Screen
	*/
	void displayInstructions() const;

	/**
	* \brief Reset all variables and conditions as if the game is restarting
	*/
	void startGame();

	/**
	* \brief Check for changes in the game and whether any game changing conditions have been met
	* \param bw: Object of type BrickWall from brickWall.h
	* \param ball: Object of type Ball from ball.h
	* \param player: Object of type Player from player.h
	*/
	void update(BrickWall& bw, Ball& ball, Player& player);

};