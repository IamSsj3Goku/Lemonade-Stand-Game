#include "MainGameLoop.h"

void PlayGame()
{
	Gamestate = RUNNING;
	if (Gamestate == RUNNING)
	{
		LemonStock = 0;	// How much Lemons we have.
		CupsOfSugar = 0;	// How much Sugar we have.
		CupsOfIce = 0;	// How much Ice/Water we have.
		CupOfLemonadeStock = 0; // How many cups of lemonade we have available.
		Money = 100; // How much money we have. 

		TotalCupSold = 0;	  // How many cups we have sold.	
		ValueOfCupSold = 0;  // How much money we've made from selling lemonade.
		MoneySpentStock = 0; // How much money we've spent on stock.
	}

	MainGameMenu(); // MainGameMenu call.

	while (Gamestate == RUNNING) // The game keeps running until it ends.
	{

		if (Money > 5000) // If the player reaches more than $5000 he wins!
		{
			Gamestate = ENDING; // Change gamestate to ending so the game takes us back to the main menu.
			system("cls"); // Clear screen.
			std::cout << "Congratulations, you have made $5000! You win!" << std::endl; // Text informing the player that they've won.
		}

		if (Money < 1 || Gamestate == ENDING) // Lose conditions
		{
			// Ends game if user runs out of money.
			if (Money < 1) // If the becomes bankrupt they lose.
			{
				std::cout << "You are bankrupt, thanks for playing." << std::endl; // Tells the player that they've lost.
				Gamestate = ENDING; // Will return us to the Main Menu.
			}

			// Exiting game
			else if (Gamestate == ENDING) // If gamestate is ending then end the game.
			{
				std::cout << "The game is now ending, thank you for playing." << std::endl; // Informs player that the game is ending and thanks them for playing.
			}
			system("pause"); // Pause.
			fflush(stdin);	 // Flush input.
		}

		else // If none of the victory/lose conditions are met then continue. 
		{
			UpdateCustomerTimer(); // Calls customer time and customers arrive.

			if (_kbhit()) // Unsure of what this exactly does to be honest.
			{
				HandleInput(); // Call handle input.
			}
		}
	}
}

// Main ingame menu.
void MainGameMenu() 
{
	std::cout << "The Game Menu" << std::endl;	  // Title.
	std::cout << "1 - See Finances" << std::endl; // Player can press 1 to check finances.
	std::cout << "2 - Buy Stock" << std::endl;    // Player can press 2 to buy stock.
	std::cout << "3 - Make Lemonade" << std::endl;// Player can press 3 to make lemonade.
	std::cout << "4 - Exit Game" << std::endl;	  // Player can press 4 to exit the game.
	if (CupOfLemonadeStock == 0) { std::cout << "To open your stall you must first purchase stock and make lemonade." << std::endl; }	 // Informs the user to open their stand they need to purchase stock and make lemonade.
	else if (CupOfLemonadeStock > 0) { std::cout << "Your stall is now open and you are automatically selling lemonade." << std::endl; } // Informs user that their stall is open if they have cups to sell. 
}

// Handle input function.
void HandleInput()
{
	char Input = 'a';   // Variable to handle input
	std::cin >> Input;	// This command will get the input from the user on what they would like to do.
	fflush(stdin);		// Clear input

	switch (Input) { // Switch statement to handle in game menu choices.
	case '1':
		SeeFinances(); // Case 1 shows finances
		break;
	case '2':
		CheckStock(); // Case 2 displays stock and allows us to puchase stock.
		BuyStock();
		break;
	case '3':
		MakeLemonade(); // Case 3 allows us to make lemonade.
		break;
	case '4':
		std::cout << "Exiting" << std::endl; // Case 4 sends us back to Main Menu.
		Gamestate = ENDING;
		break;
	}
}


