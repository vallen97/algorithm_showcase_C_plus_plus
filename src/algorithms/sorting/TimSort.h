#pragma once
#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"


namespace test
{
	class TimSort : public Test
	{
	public:
		TimSort();
		~TimSort();



	private:
		const int RUN = 32;
		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;

	};
}
