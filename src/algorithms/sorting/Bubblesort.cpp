// https://www.geeksforgeeks.org/bubble-sort/
#include "Bubblesort.h"

namespace test 
{
	// An optimized version of Bubble Sort
	void Bubblesort::bubble_sort(int arr[], int n)
	{
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++) {
			swapped = false;
			for (j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
					swapped = true;

					sleep_for(.05s);
					sleep_until(system_clock::now() + .05s);

					std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

					matplot::bar(y);
				}
			}

			// If no two elements were swapped
			// by inner loop, then break
			if (swapped == false)
				break;
		}
	}

	// Driver program to test above functions
	Bubblesort::Bubblesort(){
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
		fig->title("Bubble Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		bubble_sort(arr, arr_size);

		// print the sorted numbers
		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		// sleep for .5 seconds
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
	
	Bubblesort::~Bubblesort() { }
}