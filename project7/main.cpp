#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Bunco.h"


void clearScreen();



int main()
{
	using namespace cs31;
	using namespace std;

	clearScreen();

	// test code
	Die d;
	for (int i = 1; i <= 100; i++)
	{
		d.roll();
		int value = d.getValue();
		assert(value >= 1 && value <= 6);
	}


	Player p;
	assert(p.getScore() == 0);
	p.setRound(1);
	assert(p.getScore() == 0);
	assert(p.roll(6) == 6);
	assert(p.getScore() == 0);
	assert(p.roll(5) == 5);
	assert(p.getScore() == 0);
	assert(p.roll(1) == 1);
	assert(p.getScore() == 1);
	p.setRound(6);
	assert(p.getScore() == 0);
	assert(p.roll(6) == 6);
	assert(p.getScore() == 1);



	Bunco b;
	b.setRound(1);
	assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
	b.computerPlay(5);
	b.humanPlay(5);
	assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
	b.computerPlay(1);
	b.humanPlay(1);
	assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
	b.computerPlay(1);
	b.humanPlay(2);
	assert(b.determineRoundOutcome() == Bunco::COMPUTERWON);


	cout << "all tests passed!" << endl;

	Bunco game;
	int human, computer;
	int round = 1;
	game.setRound(round);
	std::string action, message = "(r)oll (q)uit: ";
	cout << game.display(message) << endl;


	do
	{
		getline(cin, action);
		while (action.size() == 0)
		{
			getline(cin, action);  // no blank entries allowed....
		}
		switch (action[0])
		{
		default:   // if bad move, nobody moves
			cout << '\a' << endl;  // beep
			continue;
		case 'Q':
		case 'q':
			return 0;
		case 'r':
		case 'R':
			human = game.humanPlay();
			computer = game.computerPlay();
			cout << "human rolled:" << human;
			cout << "\tcomputer rolled:" << computer << endl;


			if (game.determineRoundOutcome() != Bunco::NOTDECIDED)
			{
				round = round + 1;
				game.setRound(round);
				cout << game.display(message) << endl;
			}
			if (game.gameIsOver())
			{
				cout << game.display() << endl;
			}
			break;
		}

	} while (!game.gameIsOver());

	return(0);
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

#endif

