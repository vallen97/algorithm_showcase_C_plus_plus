#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class CycleSort : public Test
	{
	public:
		CycleSort();
		~CycleSort();


		void cycle_sort(int arr[], int n);


	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};

}
