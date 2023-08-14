#pragma once

#include <iostream>
#include <vector>

class Luhn
{
public:
	Luhn();
	~Luhn();

	std::vector<int>  generate_card_numbers(int index);
	int validate_card(std::vector<int> i_cc_number);
	inline void set_generated_index() { generatedIndex++; }
	inline int get_genereated_index() { return generatedIndex; }
	inline bool get_is_valid() { return isValid; }
	inline void set_is_valid(bool valid) { isValid = valid; }
	inline std::vector<int> get_credit_numbers() { return credit_card_numbers; }
	inline void set_credit_numbers(std::vector<int> ccn) { credit_card_numbers = ccn; }

private:
	bool isValid;
	int generatedIndex;
	std::vector<int> credit_card_numbers;
};
