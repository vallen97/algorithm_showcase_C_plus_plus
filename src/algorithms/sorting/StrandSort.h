#pragma once

#include "test/Test.h"

#include <iostream>
#include <vector>
#include "Sort.h"


namespace test
{
	class StrandSort : public Test
	{
	public:
		StrandSort();
		~StrandSort();



	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};
}