#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{

	class QuickSort : public Test
	{
	public:
		QuickSort();
		~QuickSort();

		void q_sort(int arr[], int low, int high);


	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};
}
