// https://www.geeksforgeeks.org/cycle-sort/
#include "CycleSort.h"

namespace test
{
	// Function sort the array using Cycle sort
	void CycleSort::cycle_sort(int arr[], int n)
	{
		// count number of memory writes
		int writes = 0;

		// traverse array elements and put it to on
		// the right place
		for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
			// initialize item as starting point
			int item = arr[cycle_start];

			// Find position where we put the item. We basically
			// count all smaller elements on right side of item.
			int pos = cycle_start;
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos++;

			// If item is already in correct position
			if (pos == cycle_start)
				continue;

			// ignore all duplicate elements
			while (item == arr[pos])
				pos += 1;

			// put the item to it's right position
			if (pos != cycle_start) {
				std::swap(item, arr[pos]);
				writes++;
			}

			// Rotate rest of the cycle
			while (pos != cycle_start) {
				pos = cycle_start;

				// Find position where we put the element
				for (int i = cycle_start + 1; i < n; i++)
					if (arr[i] < item)
						pos += 1;

				// ignore all duplicate elements
				while (item == arr[pos])
					pos += 1;

				// put the item to it's right position
				if (item != arr[pos]) {
					std::swap(item, arr[pos]);
					writes++;
				}

				std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

				sleep_for(.05s);
				sleep_until(system_clock::now() + .05s);

				matplot::bar(y);
			}

		}

		// Number of memory writes or swaps
		// cout << writes << endl ;
	}

	// Driver program to test above function
	CycleSort::CycleSort() {
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
		fig->title("Cycle Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		cycle_sort(arr, arr_size);

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

	CycleSort::~CycleSort() {}


}