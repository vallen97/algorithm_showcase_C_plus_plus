
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


	// Driver code
	InsertionSort::InsertionSort() {
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

		fig->title("Insrtion Sort");

		bar = ax->bar(y);
		matplot::hold(matplot::off);

		insertion_sort(arr, arr_size);

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

	InsertionSort::~InsertionSort() {
		//Memory Management

	}
}