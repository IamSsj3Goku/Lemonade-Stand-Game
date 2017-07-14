#pragma once
#include "Defines.h"
#include "MainGameLoop.h"

enum LemonadeIngredients { // Easier to read code.
	ICE = 1,
	SUGAR,
	LEMON,
	EXIT
};

void SeeFinances();
void CheckStock();
void BuyStock();
void Recipe();
void PurchaseLemon();
void PurchaseSugar();
void PurchaseIce();
void MakeLemonade();