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

			std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			matplot::bar(y);
		}
	}

	// Driver program
	SelectionSort::SelectionSort()
	{
		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		matplot::figure()->title("Selection Sort");

		matplot::bar(y);
		matplot::hold(matplot::off);

		selection_sort(arr, arr_size);

		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		// sleep for .5 seconds because it is too fast to visualize the sort
		sleep_for(.5s);
		sleep_until(system_clock::now() + 1s);

		y = sort.arrayToVector(arr, arr_size);

		// plott the sorted numbers
		matplot::bar(y);
		// lock the console, so no code runs until the charts applicatiton is closed
		matplot::show();
	}

	SelectionSort::~SelectionSort() {}


}