#include "luhn.h"
#include <iostream>


Luhn::Luhn() {

	// set default values when class is made
	isValid = false;
	generatedIndex = 0;
	//credit_card_numbers = { 5,1,8,6,9,8,0,1,4,4,1,9,0,6,8,9 };
	credit_card_numbers = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

}

Luhn::~Luhn()
{
	// remove some stuff from memory
}

std::vector<int>  Luhn::generate_card_numbers(int index)
{
	// set seed(current time and how many card have been made)
	srand((unsigned)time(NULL) + index);
	// generate 16 numbers
	for (int i = 0; i < 16; i++)
		credit_card_numbers[i] = 1 + (rand() % 8) + 1;

	return credit_card_numbers;
}

int Luhn::validate_card(std::vector<int> cc_number) {

	// loop through the card numbers backwards
	for (int i = cc_number.size() - 2; i >= 0; i = i - 1) {
		// temp cvalue of current index and multiply by 2
		int tempValue = credit_card_numbers[i];
		tempValue = tempValue * 2;

		if (tempValue > 9)
			tempValue = tempValue % 10 + 1;

		credit_card_numbers[i] = tempValue;
	}

	int total = 0;
	for (int i = 0; i < (int)credit_card_numbers.size(); i++)
		total += credit_card_numbers[i];

	if (total % 10 == 0)
		return true;

	else
		return false;
}

