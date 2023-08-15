// Optimized implementation of Bubble sort
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

		matplot::figure_handle fig = matplot::figure(true);
		fig->ion();

		auto ax = matplot::gca();
		matplot::bars_handle bar = NULL;

		fig->draw();

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		std::vector<double> y = sort.arrayToVector(arr, arr_size);


		fig->title("Bubble Sort");

		bar = ax->bar(y);
		matplot::hold(matplot::off);

		bubble_sort(arr, arr_size);

		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		sleep_for(.5s);
		sleep_until(system_clock::now() + 1s);

		y = sort.arrayToVector(arr, arr_size);

		bar = ax->bar(y);

		// lock the console, so no code runs until the charts applicatiton is closed

		fig->should_close();
		ax->touch();
		matplot::figure()->should_close();
	}
	// This code is contributed by shivanisinghss2110


	Bubblesort::~Bubblesort()
	{}
}