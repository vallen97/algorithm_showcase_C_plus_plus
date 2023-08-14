#include "Sort.h"

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
	OddEvenSort::OddEvenSort()
	{
		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		matplot::figure()->title("Odd Even Sort");

		matplot::bar(y);
		matplot::hold(matplot::off);

		odd_even_sort(arr, arr_size);

		;

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


	OddEvenSort::~OddEvenSort() {}

}