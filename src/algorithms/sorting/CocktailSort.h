#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"

namespace test
{
	class CocktailSort : public Test
	{
	public:
		CocktailSort();
		~CocktailSort();

		void cocktail_sort(int a[], int n);

	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};
}

