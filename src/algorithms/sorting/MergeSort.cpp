#pragma once

// https://www.geeksforgeeks.org/merge-sort/
#include "MergeSort.h"

namespace test
{

	// Merges two subarrays of array[].
	// First subarray is arr[begin..mid]
	// Second subarray is arr[mid+1..end]
	void merge(int array[], int const left, int const mid,
		int const right)
	{
		int const subArrayOne = mid - left + 1;
		int const subArrayTwo = right - mid;

		// Create temp arrays
		auto* leftArray = new int[subArrayOne],
			* rightArray = new int[subArrayTwo];

		// Copy data to temp arrays leftArray[] and rightArray[]
		for (auto i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];
		for (auto j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];

		auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
		int indexOfMergedArray = left;

		// Merge the temp arrays back into array[left..right]
		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				array[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				array[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}

		// Copy the remaining elements of
		// left[], if there are any
		while (indexOfSubArrayOne < subArrayOne) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}

		// Copy the remaining elements of
		// right[], if there are any
		while (indexOfSubArrayTwo < subArrayTwo) {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}

	// begin is for left index and end is right index
	// of the sub-array of arr to be sorted
	void MergeSort::merge_sort(int array[], int const begin, int const end)
	{
		if (begin >= end)
			return;

		int mid = begin + (end - begin) / 2;
		merge_sort(array, begin, mid);
		merge_sort(array, mid + 1, end);
		merge(array, begin, mid, end);

		std::vector<double> y = sort.arrayToVector(array, 1000 / sizeof(array[0]));

		sleep_for(.05s);
		sleep_until(system_clock::now() + .05s);

		matplot::bar(y);
	}

	MergeSort::MergeSort()
	{

		int* arr = sort.generate_numbers(100);

		int arr_size = 1000 / sizeof(arr[0]);

		std::cout << "Given array is \n";
		sort.printArray(arr, arr_size);


		// make a instance for differnet graphs
		std::vector<double> y = sort.arrayToVector(arr, arr_size);

		matplot::figure()->title("Merge Sort");

		matplot::bar(y);
		matplot::hold(matplot::off);

		merge_sort(arr, 0, arr_size - 1);

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

	MergeSort::~MergeSort() {
		//Memory Management
	}
}