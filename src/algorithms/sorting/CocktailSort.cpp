#include "CocktailSort.h"


namespace test
{

	// Sorts array a[0..n-1] using Cocktail sort
	void CocktailSort::cocktail_sort(int a[], int n)
	{
		bool swapped = true;
		int start = 0;
		int end = n - 1;

		while (swapped) {
			// reset the swapped flag on entering
			// the loop, because it might be true from
			// a previous iteration.
			swapped = false;

			// loop from left to right same as
			// the bubble sort
			for (int i = start; i < end; ++i) {
				if (a[i] > a[i + 1]) {
					std::swap(a[i], a[i + 1]);
					swapped = true;
				}
			}

			// if nothing moved, then array is sorted.
			if (!swapped)
				break;

			// otherwise, reset the swapped flag so that it
			// can be used in the next stage
			swapped = false;

			// move the end point back by one, because
			// item at the end is in its rightful spot
			--end;

			// from right to left, doing the
			// same comparison as in the previous stage
			for (int i = end - 1; i >= start; --i) {
				if (a[i] > a[i + 1]) {
					std::swap(a[i], a[i + 1]);
					swapped = true;
				}
			}

			// increase the starting point, because
			// the last stage would have moved the next
			// smallest number to its rightful spot.
			++start;

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			std::vector<double> y = sort.arrayToVector(a, 1000 / sizeof(a[0]));
			matplot::bar(y);
		
		}
	}

	CocktailSort::CocktailSort() {
		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		matplot::figure_handle fig = matplot::figure(true);
		fig->ion();

		auto ax = matplot::gca();
		matplot::bars_handle bar = NULL;

		fig->draw();

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		fig->title("CockTail Sort");
		
		bar = ax->bar(y);
		matplot::hold(matplot::off);

		cocktail_sort(arr, arr_size);

		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		// sleep for .5 seconds because it is too fast to visualize the sort
		sleep_for(.5s);
		sleep_until(system_clock::now() + 1s);

		y = sort.arrayToVector(arr, arr_size);

		bar = ax->bar(y);

		// lock the console, so no code runs until the charts applicatiton is closed

		fig->should_close();
		ax->touch();
		matplot::figure()->should_close();
	}
	CocktailSort::~CocktailSort() {}
}

