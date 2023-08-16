// https://www.geeksforgeeks.org/selection-sort/
#include "SelectionSort.h"

namespace test
{
	// Function for Selection sort
	void SelectionSort::selection_sort(int arr[], int n)
	{
		int i, j, min_idx;

		// One by one move boundary of
		// unsorted subarray
		for (i = 0; i < n - 1; i++) {

			// Find the minimum element in
			// unsorted array
			min_idx = i;
			for (j = i + 1; j < n; j++) {
				if (arr[j] < arr[min_idx])
					min_idx = j;
			}

			// Swap the found minimum element
			// with the first element
			if (min_idx != i)
				std::swap(arr[min_idx], arr[i]);

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

			matplot::bar(y);
		}
	}

	SelectionSort::SelectionSort()
	{
		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		// make figure instance and make reactive
		matplot::figure_handle fig = matplot::figure(true);
		fig->ion();

		// get current axes
		auto ax = matplot::gca();

		matplot::bars_handle bar = NULL;

		// draw the graph
		fig->draw();

		// print the unsorted array
		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// turn an array into a vector
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		// set the figure title
		fig->title("Selection Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		selection_sort(arr, arr_size);

		// print the sorted numbers
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

	SelectionSort::~SelectionSort() {}
}