#pragma once

enum GAMESTATE {
	INITALISING,
	RUNNING,
	ENDING
};

extern int Gamestate;

extern const float RECIPE_LEMON; // 2.5 lemons per jug of lemonade.
extern const float RECIPE_SUGAR; // 3 cups of sugar per jug.
extern const float RECIPE_ICE;	 // 3 cups ice per jug.

extern const float COST_LEMON; // 50 cents per lemon.
extern const float COST_SUGAR; // 2 dollars 20 per bag. ( 8 cups )
extern const float COST_ICE;   // 2 Dollars per bag. ( 20 cups )

const int MAX_CUPS = 10; // Maximum cups the consumer purchases.
const int MIN_CUPS = 1;  // Minimum cups the consumer purchases.

extern float LemonStock;  // How many lemons we have.
extern float CupsOfSugar; // How many sugar cups we have.
extern float CupsOfIce;	  // How many ice cups we have.
extern int CupOfLemonadeStock; // How many cups of lemonade we have available.
extern float Money;		// How much money we have.

extern int TotalCupSold;	  // How many cups we have sold.	
extern float ValueOfCupSold;  // How much money we've made from selling lemonade.
extern float MoneySpentStock; // How much money we've spent on stock.
extern const float LemonadeCupPrice; // Price of each lemonade cup.
