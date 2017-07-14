#include "Customer.h"

// Customer timer.
void UpdateCustomerTimer()
{
	int Timer = 0; // Initialize timer
	while (CupOfLemonadeStock > 0 ) // Will loop if the player has lemonade cups in their inventory.
	{
		if (Timer <= 3) // If the timer is less than 3 it counts up to 3.
		{
			Sleep(1000); // Sleeps the program for a second counting upwards.
			Timer++; // Increment the timer.

			// When the timer reaches 3 seconds, a customer buys a random amount of cups and resets timer.
			if (Timer == 3)
			{
				srand(time(0)); // Allows us randomises the amount of cups in AI cups.
				int AiCups = rand() % (MAX_CUPS - MIN_CUPS) + MIN_CUPS; // Sets a random amount of cups to Aicups everytime it's called.

				if (AiCups <= CupOfLemonadeStock) // If we have enough cups to sell then make the customer makes the full purchase.
				{
					CupOfLemonadeStock -= AiCups; // Stock is reduced by the amount of cups we just sold.
					TotalCupSold += AiCups; // We add the cups sold to our total amount of cups sold.
					Money += LemonadeCupPrice * AiCups; // Increase our money based on how many cups we've sold.

					std::cout << "A customer has arrived to purchase " << AiCups << " cups." << std::endl; // Informs player a customer has purchased some lemonade.
					std::cout << "You have sold " << AiCups << " cups of lemonade." << std::endl; // Tells them how much they just sold.
					std::cout << std::endl; // Spacing.
				}

				else if (AiCups > CupOfLemonadeStock) // If we don't have enough cups to sell.
				{
					
					int RemainingCups = AiCups - CupOfLemonadeStock; // Leftover cups variable.
					TotalCupSold += CupOfLemonadeStock; // We add the cups that we can sell to the total amount of cups sold.
					Money += LemonadeCupPrice * CupOfLemonadeStock; // Increase our money based on how many cups we sold.

					std::cout << "A customer has arrived to purchase " << AiCups << " cups." << std::endl; // Informs player a customer has arrived for lemonade.
					std::cout << "You don't have enough cups so you sold " << CupOfLemonadeStock << " cups and missed out on selling " << RemainingCups << " cups." << std::endl; // Tells player how many cups they just sold and how many they missed out on selling.
					std::cout << "You need to make more lemonade." << std::endl; // Tells player they need to make more lemonade.
					std::cout << std::endl; // Spacing.
					CupOfLemonadeStock = 0; // Sets LemonadeCupStock to 0 incase the number goes negative.
				}
				Timer = 0; // Restart timer.
			} // End If
		} // End While
	} // End If	
}