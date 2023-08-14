#pragma once

#include "test/Test.h"


#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class HeapSort : public Test
	{
	public:
		HeapSort();
		~HeapSort();

		void heap_sort(int arr[], int N);

	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};
}
