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

	// Driver program
	SelectionSort::SelectionSort()
	{
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

		fig->title("Selection Sort");
		bar = ax->bar(y);
		matplot::hold(matplot::off);

		selection_sort(arr, arr_size);

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

	SelectionSort::~SelectionSort() {}


}