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

		void plot_graph(int generated_array[]) {
			//using namespace /*matplot*/;

			matplot::cla();
			//                      iota(Start, Length, End)
			std::vector<double> x = matplot::iota(0, 1000, 1000);

			std::vector<double> y = arrayToVector(generated_array, 1000);

			//size_t num_bins = 1000;
			//auto h = hist(tempX, num_bins);

			//auto v_it = h->values().begin();
			//auto e_it = h->bin_edges().begin();
			//while (v_it != h->values().end()) {
			//	std::cout << "[" << *e_it << ";" << *std::next(e_it)
			//		<< "] - count: " << *v_it << std::endl;
			//	++v_it;
			//	++e_it;
			//}

			matplot::bar(y);



			matplot::show();
		}

		void plot_sleep(int generated_array[], bool show_plot) {
			matplot::cla();
			//                      iota(Start, Length, End)
			std::vector<double> x = matplot::iota(0, 1000, 1000);

			std::vector<double> y = arrayToVector(generated_array, 1000);

			using namespace std::this_thread;     // sleep_for, sleep_until
			using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
			using std::chrono::system_clock;

			sleep_for(1000ms);
			sleep_until(system_clock::now() + 5000ms);

			matplot::bar(y);


			if (show_plot)
				matplot::show();
		}

	};
}