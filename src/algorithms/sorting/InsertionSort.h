#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class InsertionSort : public Test
	{
	public:
		InsertionSort();
		~InsertionSort();

		void insertion_sort(int arr[], int n);

	private:
		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;

	};
}
