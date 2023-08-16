// https://www.geeksforgeeks.org/comb-sort/
#include "CombSort.h"

namespace test
{
	// To find gap between elements
	int getNextGap(int gap)
	{
		// Shrink gap by Shrink factor
		gap = (gap * 10) / 13;

		if (gap < 1)
			return 1;
		return gap;
	}

	// Function to sort a[0..n-1] using Comb Sort
	void CombSort::comb_sort(int a[], int n)
	{
		// Initialize gap
		int gap = n;

		// Initialize swapped as true to make sure that
		// loop runs
		bool swapped = true;

		// Keep running while gap is more than 1 and last
		// iteration caused a swap
		while (gap != 1 || swapped == true)
		{
			// Find next gap
			gap = getNextGap(gap);

			// Initialize swapped as false so that we can
			// check if swap happened or not
			swapped = false;

			// Compare all elements with current gap
			for (int i = 0; i < n - gap; i++)
			{
				if (a[i] > a[i + gap])
				{
					std::swap(a[i], a[i + gap]);


					std::vector<double> y = sort.arrayToVector(a, 1000 / sizeof(a[0]));

					sleep_for(.05s);
					sleep_until(system_clock::now() + .05s);

					matplot::bar(y);
					swapped = true;
				}
			}
		}
	}

	// Driver program
	CombSort::CombSort() {
		// make random numbers 
		int* arr = sort.generate_numbers(1000);
		int arr_size = 1000 / sizeof(arr[0]);

		// make figure and set reactive
		matplot::figure_handle fig = matplot::figure(true);
		fig->ion();

		// get current axes
		auto ax = matplot::gca();
		matplot::bars_handle bar = NULL;

		// draw plot
		fig->draw();

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);
		fig->title("Comb Sort");

		// plot unsorted numbers
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		comb_sort(arr, arr_size);

		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		// sleep for .5 seconds because it is too fast to visualize the sort
		sleep_for(.5s);
		sleep_until(system_clock::now() + 1s);

		// replot the sorted numbers
		y = sort.arrayToVector(arr, arr_size);
		bar = ax->bar(y);

		// should close the graph
		fig->should_close();
		ax->touch();
		matplot::figure()->should_close();
	}

	CombSort::~CombSort() {}
}