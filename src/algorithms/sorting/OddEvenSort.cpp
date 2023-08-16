// Odd-Even / Brick Sort
// https://www.geeksforgeeks.org/odd-even-sort-brick-sort/
#include "OddEvenSort.h"


namespace test
{
	// A function to sort the algorithm using Odd Even sort
	void OddEvenSort::odd_even_sort(int arr[], int n)
	{
		bool isSorted = false; // Initially array is unsorted

		while (!isSorted)
		{
			isSorted = true;

			// Perform Bubble sort on odd indexed element
			for (int i = 1; i <= n - 2; i = i + 2)
			{
				if (arr[i] > arr[i + 1])
				{
					std::swap(arr[i], arr[i + 1]);

					std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

					sleep_for(.05s);
					sleep_until(system_clock::now() + .05s);

					matplot::bar(y);
					isSorted = false;
				}
			}

			// Perform Bubble sort on even indexed element
			for (int i = 0; i <= n - 2; i = i + 2)
			{
				if (arr[i] > arr[i + 1])
				{
					std::swap(arr[i], arr[i + 1]);

					std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

					sleep_for(.05s);
					sleep_until(system_clock::now() + .05s);

					matplot::bar(y);
					isSorted = false;
				}
			}
		}

		return;
	}

	// Driver program to test above functions.
	OddEvenSort::OddEvenSort() {
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
		fig->title("Odd Even Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		odd_even_sort(arr, arr_size);

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

	OddEvenSort::~OddEvenSort() {}
}