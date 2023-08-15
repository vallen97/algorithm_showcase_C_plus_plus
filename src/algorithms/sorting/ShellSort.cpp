// C++ implementation of Shell Sort
#include "ShellSort.h"
namespace test
{

	/* function to sort arr using shellSort */
	int ShellSort::shell_sort(int arr[], int n)
	{
		// Start with a big gap, then reduce the gap
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			// Do a gapped insertion sort for this gap size.
			// The first gap elements a[0..gap-1] are already in gapped order
			// keep adding one more element until the entire array is
			// gap sorted
			for (int i = gap; i < n; i += 1)
			{
				// add a[i] to the elements that have been gap sorted
				// save a[i] in temp and make a hole at position i
				int temp = arr[i];

				// shift earlier gap-sorted elements up until the correct
				// location for a[i] is found
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				// put temp (the original a[i]) in its correct location
				arr[j] = temp;


				std::vector<double> y = sort.arrayToVector(arr, 1000 / sizeof(arr[0]));

				sleep_for(.05s);
				sleep_until(system_clock::now() + .05s);

				matplot::bar(y);
			}
		}
		return 0;
	}



	ShellSort::ShellSort()
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

		fig->title("Shell Sort");

		bar = ax->bar(y);
		matplot::hold(matplot::off);

		shell_sort(arr, arr_size);

		std::cout << "\nSorted array is \n";
		sort.printArray(arr, arr_size);

		// sleep for .5 seconds because it is too fast to visualize the sort
		sleep_for(.5s);
		sleep_until(system_clock::now() + 1s);

		bar = ax->bar(y);

		// lock the console, so no code runs until the charts applicatiton is closed

		fig->should_close();
		ax->touch();
		matplot::figure()->should_close();
	}

	ShellSort::~ShellSort() {}

}
