#include "Bunco.h"
#include <iostream>

namespace cs31
{
	Bunco::Bunco() : mRound(0)
	{

	}

	// stringify the game by stringifying the board
	std::string Bunco::display(std::string msg) const
	{
		using namespace std;
		std::string s = mBoard.display();
		s = s + msg;

		if (gameIsOver())
		{
			if (determineGameOutcome() == TIEDGAME)
			{
				s = s + "\n\t\tBunco wound up tied!\n";
			}
			else if (determineGameOutcome() == HUMANWONGAME)
			{
				s = s + "\n\t\tyou won Bunco!\n";
			}
			else
			{
				s = s + "\n\t\tyou lost Bunco!\n";
			}
		}
		return(s);
	}

	// set the current round of play, notifying the board and each
	// player of the current round
	void Bunco::setRound(int round)
	{
		mRound = round;
		mBoard.setCurrentRound(round);
		mHuman.setRound(round);
		mComputer.setRound(round);
	}

	// let the human player play
	// when the amount is zero, the Die should be rolled for random play
	// when the amount is not zero, we are trying to cheat for testing
	// purposes.  in that case, this method should force a specific roll
	// amount.
	int Bunco::humanPlay(int amount)
	{
		int i = mHuman.roll(amount);

		return(i);
	}

	// let the computer player play
	// when the amount is zero, the Die should be rolled for random play
	// when the amount is not zero, we are trying to cheat for testing
	// purposes.  in that case, this method should force a specific roll
	// amount.
	int Bunco::computerPlay(int amount)
	{
		int i = mComputer.roll(amount);

		return(i);
	}

	// considering each player's score, determine the
	// winner of this round of play
	Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome()
	{
		ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
		int human = mHuman.getScore();

		int comp = mComputer.getScore();
		
			if (human == comp) {
				result = NOTDECIDED;
				
			}
			else if (human > comp) {
				result = ROUNDOUTCOME::HUMANWON;
				mBoard.markHumanAsWinner();
			}
			else {
				result = ROUNDOUTCOME::COMPUTERWON;
				mBoard.markComputerAsWinner();
			}
		
		return(result);
	}

	//  count up the number of won rounds by each player to determine
	// the game's outcome
	Bunco::GAMEOUTCOME  Bunco::determineGameOutcome() const
	{
		GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;

		int human = mBoard.countUpHumanRoundWins();
		int comp = mBoard.countUpComputerRoundWins();
		if ((human + comp) == 6) {
			if (human == comp) {
				result = GAMEOUTCOME::TIEDGAME;
			}
			else if (human > comp) {
				result = GAMEOUTCOME::HUMANWONGAME;
			}
			else {
				result = GAMEOUTCOME::COMPUTERWONGAME;
			}
		}
		return(result);
	}

	// is the game over?
	bool Bunco::gameIsOver() const
	{
		GAMEOUTCOME result = determineGameOutcome();
		return(result != GAMENOTOVER);
	}

}