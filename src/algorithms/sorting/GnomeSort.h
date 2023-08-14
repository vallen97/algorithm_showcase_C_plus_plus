#pragma once

#include "test/Test.h"


#include <iostream>
#include <vector>
#include "Sort.h"



namespace test
{
	class GnomeSort : public Test
	{
	public:
		GnomeSort();
		~GnomeSort();

		void gnome_sort(int arr[], int n);

	private:

		int* generated_random_numbers[100];
		const int n = 100;
		sort::Sort sort;
	};

}

