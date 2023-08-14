// https://www.geeksforgeeks.org/quick-sort/
// C++ code to implement quicksort
#include "QuickSort.h"


namespace test
{

	// This function takes last element as pivot,
	// places the pivot element at its correct position
	// in sorted array, and places all smaller to left
	// of pivot and all greater elements to right of pivot
	int partition(int arr[], int low, int high) {
		// Choosing the pivot
		int pivot = arr[high];

		// Index of smaller element and indicates
		// the right position of pivot found so far
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++)
			// If current element is smaller than the pivot
			if (arr[j] < pivot) {

				// Increment index of smaller element
				i++;
				std::swap(arr[i], arr[j]);
			}

		std::swap(arr[i + 1], arr[high]);
		return (i + 1);
	}



	// The main function that implements QuickSort
	// arr[] --> Array to be sorted,
	// low --> Starting index,
	// high --> Ending index
	void QuickSort::q_sort(int arr[], int low, int high) {
		if (low < high) {



			// pi is partitioning index, arr[p]
			// is now at right place
			int pi = partition(arr, low, high);

			std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			matplot::bar(y);

			//Separately sort elements before
			//partition and after partition
			q_sort(arr, low, pi - 1);
			q_sort(arr, pi + 1, high);
		}
	}

	// Driver Code
	QuickSort::QuickSort() {

		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		matplot::figure()->title("Quick Sort");

		matplot::bar(y);
		matplot::hold(matplot::off);

		q_sort(arr, 0, arr_size - 1);

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

	QuickSort::~QuickSort() {
		//Memory Management

	}
}