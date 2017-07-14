//////////////////////////////////////////
// Author:	Daniel						//
// Date:	2/13/2017					//
// File:	LemonadeStand.cpp			//
// Purpose: Lemonade Stand video game   //
//////////////////////////////////////////
#include "Main.h"

int main(int argc, const char* argv[]) // Main function
{
	MainMenu();
	MainMenuPrompt(); // MainMenuPrompt has been taken out of the MainMenu because the program doesn't exit correctly if I have it inside MainMenu() 

	system("pause"); // Pauses so the game doesn't end abruptly.
	return 0; // Ends the game.
}

void MainMenu()
{
	system("cls");
	Gamestate = INITALISING;
	std::cout << "Welcome to the Lemonade Stand the Game!" << std::endl; // Welcoming the user to the game.
	std::cout << std::endl;									   // To space out the menu.

	std::cout << "1.   Play Game" << std::endl;			// Start the game.
	std::cout << "2.   View Instructions" << std::endl;	// View Instructions.
	std::cout << "3.   View Credits" << std::endl;		// View Credits.
	std::cout << "4.   Exit Game" << std::endl;			// Exits the game.

	std::cout << "Please enter your choice: "; // Tells the user to input their choice on what they want to see or do.
}

void Instructions()
{
	system("cls"); // Clears screen for neatness.
	std::cout << "Instructions are not available at the moment." << std::endl;						// Informs the user that there are no instructions in the game yet.
	std::cout << "Please check in later on in development. Thank you for your time." << std::endl;	// Informs the user to check again in the future.
	std::cout << std::endl; // Spacing.
}

void Credits()
{
	const int YearMade = 2017;	// Variable for year of development
	float GameVersion = 0.1;	// Variable for the game version.
	system("cls");
	std::cout << "		Credits" << std::endl; // Title of credits.
	std::cout << std::endl;			  // Spacing.
	std::cout << "Game Developer - Daniel" << std::endl;	// Shows user who the game developer is.
	std::cout << std::endl;			  // Spacing.
	std::cout << "Company of development - Daniels Gaming House" << std::endl;		// Shows the user what company made the game.
	std::cout << "What's something interesting about the developer?" << std::endl;	// Question about the game developer.
	std::cout << std::endl;			 // Spacing.
	std::cout << "I own a large Dragon ball Z collection with many figures and collectables." << std::endl; // Answers the question above.
	std::cout << std::endl;			 // Spacing.
	std::cout << "Year of development " << YearMade << std::endl; // Shows user what year the game was made.
	std::cout << std::endl;			 // Spacing.
	std::cout << "Game Version " << GameVersion << std::endl;	  // Shows the user what version the game is in.
	std::cout << std::endl;			 // Spacing.
}

int MainMenuPrompt()
{
	int iChoice = 0;	// iChoice variable
	std::cin >> iChoice;	// This command will get the input from the user on what they would like to do.
	fflush(stdin); // Clears the input buffer.
	system("cls"); // Clears the screen keeping things tidy.
	
	while (iChoice < 4) // Will loop unless choice is greater than 4
	{
		switch (iChoice) {
		case 1:
			PlayGame(); // Case 1 begins the game.
			break;

		case 2:
			Instructions(); // Case 2 displays instructions.
			break;

		case 3:
			Credits(); // Case 3 displays credits.
			break;
	}

		MainMenu(); // Calls mainmenu incase the user enters invalid input.
		std::cin >> iChoice;	// This command will get the input from the user on what they would like to do.
								
		fflush(stdin); // Clears the input buffer.
	}
	return 0; // Ends program.
}