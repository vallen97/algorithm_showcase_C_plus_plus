// https://www.geeksforgeeks.org/heap-sort/
#include "HeapSort.h"

namespace test
{
	// To heapify a subtree rooted with node i
	// which is an index in arr[].
	// n is size of heap
	void heapify(int arr[], int N, int i)
	{

		// Initialize largest as root
		int largest = i;

		// left = 2*i + 1
		int l = 2 * i + 1;

		// right = 2*i + 2
		int r = 2 * i + 2;

		// If left child is larger than root
		if (l < N && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest
		// so far
		if (r < N && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			std::swap(arr[i], arr[largest]);


			// Recursively heapify the affected
			// sub-tree
			heapify(arr, N, largest);
		}
	}

	// Main function to do heap sort
	void HeapSort::heap_sort(int arr[], int N)
	{

		// Build heap (rearrange array)
		for (int i = N / 2 - 1; i >= 0; i--)
			heapify(arr, N, i);

		// One by one extract an element
		// from heap
		for (int i = N - 1; i > 0; i--) {

			// Move current root to end
			std::swap(arr[0], arr[i]);

			std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

			sleep_for(.05s);
			sleep_until(system_clock::now() + .05s);

			matplot::bar(y);

			// call max heapify on the reduced heap
			heapify(arr, i, 0);
		}



	}


	HeapSort::HeapSort() {
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
		fig->title("Heap Sort");

		// set data into bar graph
		bar = ax->bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		heap_sort(arr, arr_size);

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

	HeapSort::~HeapSort() {	}
}