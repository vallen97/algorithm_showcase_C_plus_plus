#pragma once
#include <iostream>
#include <cmath>
#include <matplot/matplot.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

namespace sort
{
	class Sort
	{
	public:
		Sort() {}
		~Sort() {}
		int* generate_numbers(int seed) {
			srand(seed);

			static int generated_numbers[1000]; //array declared as static
			for (int i = 0; i < 1000; i++)
				generated_numbers[i] = 1 + (rand() % 999) + 1;
			return generated_numbers; //address of a returned}
		}

		void printArray(int A[], int size) {
			for (int i = 0; i < size; i++)
				std::cout << A[i] << " ";
			std::cout << std::endl;
		}

		std::vector<double> arrayToVector(int arr[], int array_size) {
			std::vector<double> newVector;
			for (int i = 0; i < array_size; i++) {
				newVector.push_back(arr[i]);
			}

			return newVector;
		}
	};
}