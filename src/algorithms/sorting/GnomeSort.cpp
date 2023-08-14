// A C++ Program to implement Gnome Sort
#include "GnomeSort.h"

namespace test
{

	// A function to sort the algorithm using gnome sort
	void GnomeSort::gnome_sort(int arr[], int n)
	{
		int index = 0;

		while (index < n) {
			if (index == 0)
				index++;
			if (arr[index] >= arr[index - 1])
				index++;
			else {
				std::swap(arr[index], arr[index - 1]);

				std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

				sleep_for(.05s);
				sleep_until(system_clock::now() + .05s);

				matplot::bar(y);

				index--;
			}
		}
		return;
	}



	// Driver program to test above functions.
	GnomeSort::GnomeSort()
	{
		int* arr = sort.generate_numbers(100);
		int arr_size = 1000 / sizeof(arr[0]);

		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		matplot::figure()->title("Gnome Sort");

		matplot::bar(y);
		matplot::hold(matplot::off);

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);

		gnome_sort(arr, arr_size);

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


	GnomeSort::~GnomeSort() {}

}