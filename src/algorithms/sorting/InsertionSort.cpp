
// https://www.geeksforgeeks.org/insertion-sort/
#include "InsertionSort.h"

namespace test
{
	// Function to sort an array using
	// insertion sort
	void InsertionSort::insertion_sort(int arr[], int n)
	{
		int i, key, j;
		for (i = 1; i < n; i++) {
			key = arr[i];
			j = i - 1;

			// Move elements of arr[0..i-1],
			// that are greater than key,
			// to one position ahead of their
			// current position
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;

			std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			matplot::bar(y);
		}
	}

	InsertionSort::InsertionSort() {
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
		fig->title("Insrtion Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		insertion_sort(arr, arr_size);

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

	InsertionSort::~InsertionSort() { }
}