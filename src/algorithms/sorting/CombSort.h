#pragma once

#include "test/Test.h"


#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class CombSort : public Test
	{
	public:
		CombSort();
		~CombSort();

		void comb_sort(int a[], int n);


	private:
		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;

	};
}
