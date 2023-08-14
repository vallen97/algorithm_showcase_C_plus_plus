#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class SelectionSort : public Test
	{
	public:
		SelectionSort();
		~SelectionSort();

		void selection_sort(int arr[], int n);


	private:
		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;

	};
}
