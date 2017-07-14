#include "Lemonade.h"

// Displays finanical statistics.
void SeeFinances()
{
	CheckStock(); // Calls show stock interface.

	std::cout << "Your money: $" << Money << std::endl;				  // Displays your money.
	std::cout << "Lemonade cups sold: " << TotalCupSold << std::endl; // Displays how many cups sold

	float Profits = ValueOfCupSold - MoneySpentStock;		// Profits Variable.
	std::cout << "Profits Made: $" << Profits << std::endl; // Shows user how much profit they've made.
	std::cout << std::endl; // Spacing
	system("pause"); // A pause for neatness.

	MainGameMenu(); // Returns user to main game menu.
}

// Displays Inventory Items.
void CheckStock()
{
	system("cls"); // Clears screen
	Recipe();
	std::cout << "	Stock	" << std::endl; // Menu title
	std::cout << "------------------------	" << std::endl; // Spacing
	std::cout << "Lemons in stock: " << LemonStock << std::endl;			// Displays amount of lemons in users inventory.
	std::cout << "Cups of sugar in stock: " << CupsOfSugar << std::endl;	// Displays amount of suger cups in users inventory.
	std::cout << "Cups of ice in stock: " << CupsOfIce << std::endl;		// Displays amount of ice cups in users inventory.
	std::cout << "Cups of lemonade in stock: " << CupOfLemonadeStock << std::endl; // Displays amount of lemonade cups available for sale.
	std::cout << "1 jug of lemonade is enough for 6 cups." << std::endl;		   // Displays conversion of lemonade jugs to cups. ( 1 Jug = 6 Cups )
}

// Buy Stock function.
void BuyStock()
{
	int Purchase = 0; // Variable for choosing which item they'd like to buy.
	while (Purchase != EXIT) // Loops until the user exits.
	{
		system("cls");
		Recipe();
		std::cout << "	Your ingredients " << std::endl; // Ingredients title.
		std::cout << "Ice Cups: " << CupsOfIce << " Suger Cups: " << CupsOfSugar << " Lemons: " << LemonStock << std::endl; // Your ingredients.
		std::cout << "Your money: $" << Money << std::endl; // Your money
		std::cout << "Shop:" << std::endl; // Shop title.
		std::cout << "Press 1 to buy bags of ice $" << COST_ICE << " each bag (20 cups)." << std::endl;		// Prompt to buy ice bags.
		std::cout << "press 2 to buy bags of sugar $" << COST_SUGAR << " each bag (8 cups)." << std::endl;  // Prompt to buy sugar bags.
		std::cout << "Press 3 to buy lemons $" << COST_LEMON << " each." << std::endl;						// Prompt to buy lemons.
		std::cout << "Press 4 to leave." << std::endl;	// Exit prompt

		std::cout << "Your choice: "; // Choice prompt.
		std::cin >> Purchase;		  // Users choice.
		switch (Purchase) { // Switch statement to handle stock purchases.
		case ICE:
			PurchaseIce(); // Purchase Ice Function.
			break;
		case SUGAR:
			PurchaseSugar(); // Purchase Sugar Function.
			break;
		case LEMON:
			PurchaseLemon(); // Purchase Lemon Function.
			break;
		case EXIT:
			MainGameMenu(); // Exit function.
			break;
		}
	}
}

void Recipe()
{
	std::cout << "Lemonade Recipe" << std::endl; // Lemonade Recipe text.
	std::cout << "You need " << RECIPE_ICE << " cups of ice per jug." << std::endl;			// Displays how many cups of ice are needed per jug.
	std::cout << "You need " << RECIPE_SUGAR << " cups of sugar per jug." << std::endl;		// Displays how many cups of sugar are needed per jug.
	std::cout << "You need " << RECIPE_LEMON << " lemons per jug of lemonade." << std::endl;// Displays how many lemons are needed per jug.
	std::cout << std::endl;	// Spacing
}

// Ice purchase handler.
void PurchaseIce()
{
	float HowMany = 0; // Variable to hold how much ice they would like to buy.
	std::cout << "How many bags of ice would you like to purchase?" << std::endl; // Prompt asking them how much ice they'd like to buy.
	std::cout << "Bags: "; // Shows the player where they'll be typing.
	std::cin >> HowMany; // Gets the number of bags the player wants.

	if (Money >= COST_ICE * HowMany) // Test for if the user has enough money to purchase ice.
	{
		Money -= COST_ICE * HowMany; // The price of the ice  multiplied by the amount of ice the player buys will add to their money.
		CupsOfIce += HowMany * 20; // The cups they buy.
		MoneySpentStock += COST_ICE * HowMany; // The money they spent on ice adds to MoneySpentStock
		std::cout << "You have purchased " << HowMany << " bags of ice." << std::endl; // Tells the player how many bags of ice they purchased.
	}

	else // If they don't have enough money this statement fires off.
	{
		std::cout << "You don't have enough money to make this purchase." << std::endl; // Informs user they don't have enough money to buy ice.
	}
	system("pause"); // Pauses so the user can take in the information.
}

// Sugar purchase handler.
void PurchaseSugar()
{
	float HowMany = 0; // Variable for how much sugar they would like to buy.
	std::cout << "How many bags of sugar would you like to purchase?" << std::endl; // Prompt asking them how much sugar they'd like to buy.
	std::cout << "Bags: "; // Shows the player where they'll be typing.
	std::cin >> HowMany; // Gets the number of bags the player wants to purchase.

	if (Money >= COST_SUGAR * HowMany) // Test for if the user has enough money to purchase sugar.
	{
		Money -= COST_SUGAR * HowMany; // The price of the sugar multiplied by the amount of sugar the player buys will be added to their money.
		CupsOfSugar = HowMany * 8; // The cups they buy.
		MoneySpentStock += COST_SUGAR * HowMany; // The money they spent on sugar adds to MoneySpentStock
		std::cout << "You have purchased " << HowMany << " bags of sugar." << std::endl; // Tells the player how much sugar they purchased.
	}
	else // If they don't have enough money this statement fires off.
	{
		std::cout << "You don't have enough money to make this purchase." << std::endl; // Informs the user they don't have enough money to buy sugar.
	}
	system("pause"); // Pauses so the player can take in the information.
}

// Lemon purchase handler.
void PurchaseLemon()
{
	float HowMany = 0; // Variable to hold how many lemons they'd like to buy.
	std::cout << "How many lemons would you like to buy?" << std::endl; // Prompt asking them how many lemons they'd like to buy.
	std::cout << "Lemons: "; // Shows the player where they'll be typing.
	std::cin >> HowMany; // Gets the number of lemons they player would like to buy.

	if (Money >= COST_LEMON * HowMany) // Test for if the user has enough money to purchase lemons.
	{
		Money -= COST_LEMON * HowMany; // the price of the lemons multiplied by the amount of lemons the player buys will be added to their money
		LemonStock += HowMany; // The amount of lemons they buy.
		MoneySpentStock += COST_LEMON * HowMany; // the money they spent on lemons adds to MoneySpentStock
		std::cout << "You have purchased " << HowMany << " lemons." << std::endl; // Tells the player how many lemons they've purchased.
	}
	else // If they don't have enough money this statement fires off.
	{
		std::cout << "You don't have enough money to make this purchase." << std::endl; // Informs the user they don't have enough money to buy lemons.
	}
	system("pause"); // Pauses so the player can take in the information.
}

// Make Lemonade Function.
void MakeLemonade()
{
	char lChoice = 0; // Choice variable
	while (lChoice != 'n') // While choice isn't equal to 'n' ( n = no )
	{ 
		CheckStock(); // Displays players stock.

		std::cout << "Do you want to make lemonade? (y/n)" << std::endl; // Prompts user to make lemonade
		std::cin >> lChoice; // Gets their choice, yes or no.
		fflush(stdin); // Clears the input buffer.

		if (lChoice == 'y') // If the user picks 'y'
		{
			int Jugs = 0; // Variable to hold the amount of jugs they want.
			std::cout << "How many jugs of lemonade would you like to make? (1 Jug = 6 Cups)" << std::endl; // Asks the player how many jugs they want to make and the conversion to cups.
			std::cout << "Jugs: "; // Shows user where to enter input.
			std::cin >> Jugs; // Gets the amount of Jugs the user wants to buy.

				if (CupsOfIce <= RECIPE_ICE * Jugs) // If statement to tell player if they can't make lemonade because of missing Ice.
				{
					float MissingIce = (RECIPE_ICE * Jugs ) - CupsOfIce; // Variable to calculate how much ice the player is missing to make required cups.
					std::cout << "You need " << MissingIce << " more cups of ice to make " << Jugs << " jugs of lemonade." << std::endl; // Informs the player how much ice they missing.
				} 
				if (CupsOfSugar <= RECIPE_SUGAR * Jugs) // If statement to tell player if they can't make lemonade because of missing Sugar.
				{
					float MissingSugar = (RECIPE_SUGAR * Jugs) - CupsOfSugar; // Variable to calculate how much sugar the player is missing to make required cups.
					std::cout << "You need " << MissingSugar << " more cups of sugar to make " << Jugs << " jugs of lemonade." << std::endl; // Informs player how much sugar they're missing..
				}
				if (LemonStock <= RECIPE_LEMON * Jugs) // If statement to tell player if they can't make lemonade because of missing Lemons.
				{
					float MissingLemon = (RECIPE_LEMON * Jugs) - LemonStock; // Variable to calculate how many lemons the player is missing to make required cups.
					std::cout << "You need " << MissingLemon << " lemons to make " << Jugs << " jugs of lemonade." << std::endl; // Informs player how many lemons they're missing.
				}
			else // Otherwise if enough ingredients make the players order.
			{
				CupOfLemonadeStock += 6 * Jugs; // Adds the cups to players inventory.
				CupsOfIce -= RECIPE_ICE * Jugs; // Removes ice from inventory.
				CupsOfSugar -= RECIPE_SUGAR * Jugs; // Removes sugar from inventory.
				LemonStock -= RECIPE_LEMON * Jugs; // Removes lemons from inventory.
				std::cout << "You have made " << Jugs << " jugs of lemonade." << std::endl; // Tells player how many jugs they have made.
				
			}
				system("pause"); // Pauses function so user can take in information.
				fflush(stdin); // Clears input from pause.
		}

		else if (lChoice == 'n') // If the user picks 'n' then he decides to exit the make lemonade function.
		{
			system("cls"); // Clears screen for neatness.
			MainGameMenu(); // Takes the user back.
		}
	}
}