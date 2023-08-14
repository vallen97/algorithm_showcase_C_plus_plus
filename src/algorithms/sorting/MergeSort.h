#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class MergeSort : public Test
	{
	public:
		MergeSort();
		~MergeSort();

		void merge_sort(int array[], int const begin, int const end);

	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};
}

