#include "Defines.h"

	int Gamestate = INITALISING;

	const float RECIPE_LEMON = 2.5f; // 2.5 lemons per jug of lemonade.
	const float RECIPE_SUGAR = 3.0f; // 3 cups of sugar per jug.
	const float RECIPE_ICE = 3.0f;   // 3 cups ice per jug.

	const float COST_LEMON = 0.50f; // 50 cents per lemon.
	const float COST_SUGAR = 2.20f; // 2 dollars 20 per bag. ( 8 cups )
	const float COST_ICE = 2.0f;   // 2 Dollars per bag. ( 20 cups )

	float LemonStock = 0;	// How much Lemons we have.
	float CupsOfSugar = 0;	// How much Sugar we have.
	float CupsOfIce = 0;	// How much Ice/Water we have.
	int CupOfLemonadeStock = 0; // How many cups of lemonade we have available.
	float Money = 0;		// How much money we have.

	int TotalCupSold = 0;	  // How many cups we have sold.	
	float ValueOfCupSold = 0;  // How much money we've made from selling lemonade.
	float MoneySpentStock = 0; // How much money we've spent on stock.
	const float LemonadeCupPrice = 1.05; // Price of each lemonade cup.

	





