#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "test/TestClearColor.h"
#include "test/TestTriangle.h"
#include "test/TestUniform.h"
#include "test/TestMultipleObjects.h"
#include "test/TestRotate.h"

#include "Debug.h"

#include "algorithms/creditCardValidater/Luhn.h"

#include "algorithms/sorting/Bubblesort.h"
#include "algorithms/sorting/CocktailSort.h"
#include "algorithms/sorting/CombSort.h"
#include "algorithms/sorting/CycleSort.h"
#include "algorithms/sorting/GnomeSort.h"
#include "algorithms/sorting/HeapSort.h"
#include "algorithms/sorting/InsertionSort.h"
#include "algorithms/sorting/MergeSort.h"
#include "algorithms/sorting/OddEvenSort.h"
#include "algorithms/sorting/QuickSort.h"
#include "algorithms/sorting/SelectionSort.h"
#include "algorithms/sorting/ShellSort.h"
#include "algorithms/sorting/StrandSort.h"
#include "algorithms/sorting/TimSort.h"
#include "algorithms/sorting/TreeSort.h"


GLFWwindow* InitWindow()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return nullptr;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(960, 960, "Algorithm Showcase", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return nullptr;
	}

	std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	return window;
}


int main(void)
{
	GLFWwindow* window = InitWindow();
	if (!window)
		return -1;

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();

	int currentSelection = -1;
	int radioSelection = 0;
	test::Test* test = nullptr;
	Luhn luhn;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		ImGui_ImplGlfwGL3_NewFrame();
		{
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::RadioButton("Do Nothing", &radioSelection, 0);
			ImGui::NewLine();
			ImGui::RadioButton("Bubble Sort", &radioSelection, 1);
			ImGui::NewLine();
			ImGui::RadioButton("Cocktail Sort", &radioSelection, 2);
			ImGui::NewLine();
			ImGui::RadioButton("Comb Sort", &radioSelection, 3);
			ImGui::NewLine();
			ImGui::RadioButton("Cycle Sort", &radioSelection, 4);
			ImGui::NewLine();
			ImGui::RadioButton("Gnome Sort", &radioSelection, 5);
			ImGui::NewLine();
			ImGui::RadioButton("Heap Sort", &radioSelection, 6);
			ImGui::NewLine();
			ImGui::RadioButton("Insertion Sort", &radioSelection, 7);
			ImGui::NewLine();
			ImGui::RadioButton("Merge Sort", &radioSelection, 8);
			ImGui::NewLine();
			ImGui::RadioButton("Odd Even Sort", &radioSelection, 9);
			ImGui::NewLine();
			ImGui::RadioButton("Quick Sort", &radioSelection, 10);
			ImGui::NewLine();
			ImGui::RadioButton("Selection Sort", &radioSelection, 11);
			ImGui::NewLine();
			ImGui::RadioButton("Shell Sort", &radioSelection, 12);
			ImGui::NewLine();
			ImGui::RadioButton("Tree Sort", &radioSelection, 13);


			/*ImGui::RadioButton("ClearColor", &radioSelection, 0);
			ImGui::NewLine();
			ImGui::RadioButton("Triangle", &radioSelection, 1);
			ImGui::NewLine();
			ImGui::RadioButton("Uniform", &radioSelection, 2);
			ImGui::NewLine();
			ImGui::RadioButton("MultipleObjects", &radioSelection, 3);
			ImGui::NewLine();
			ImGui::RadioButton("Rotate Object", &radioSelection, 4);
			*/
			if (ImGui::Button("Credit Card Number"))
			{ // Buttons return true when clicked (most widgets return true when edited/activated)

				// Loop until there is a valid card
				while (!luhn.get_is_valid())
				{
					// index to tell user how many cards have been generated until a valid card has been made
					luhn.set_generated_index();

					// set the credit card number(make a credit card number(pass a seed))
					luhn.set_credit_numbers(luhn.generate_card_numbers(luhn.get_genereated_index()));

					// set if the card is valid( validate the card numbers( get the card numbers to validate))
					luhn.set_is_valid(luhn.validate_card(luhn.get_credit_numbers()));

					std::cout << luhn.get_is_valid();

				}
			}

			if (luhn.get_is_valid() == 1) {
				std::string s_card_number = "";
				for (int j = 0; j < 16; j++) {
					// std::cout << luhn.get_credit_numbers()[j] << "\t"; //ptr[i] is equivalent to *(ptr+i)
					s_card_number.append(std::to_string(luhn.get_credit_numbers()[j]));
				}

				ImGui::SameLine();
				ImGui::Text("Card Number = %d", s_card_number);
				ImGui::Text("Number of different cards made %d", luhn.get_genereated_index());
			}
		}


		if (currentSelection != radioSelection)
		{
			switch (radioSelection)

			{
			case 0:
				// Do nothing
				break;
			case 1:
				delete test;
				test = new test::Bubblesort();
				break;
			case 2:
				delete test;
				test = new test::CocktailSort();
				break;
			case 3:
				delete test;
				test = new test::CombSort();
				break;
			case 4:
				delete test;
				test = new test::CycleSort();
				break;
			case 5:
				delete test;
				test = new test::GnomeSort();
				break;
			case 6:
				delete test;
				test = new test::HeapSort();
				break;
			case 7:
				delete test;
				test = new test::InsertionSort();
				break;
			case 8:
				delete test;
				test = new test::MergeSort();
				break;
			case 9:
				delete test;
				test = new test::OddEvenSort();
				break;
			case 10:
				delete test;
				test = new test::QuickSort();
				break;
			case 11:
				delete test;
				test = new test::SelectionSort();
				break;
			case 12:
				delete test;
				test = new test::ShellSort();
				break;
			}

			/*{
			case 0:
				delete test;
				test = new test::TestClearColor();
				break;
			case 1:
				delete test;
				test = new test::TestTriangle();
				break;
			case 2:
				delete test;
				test = new test::TestUniform();
				break;
			case 3:
				delete test;
				test = new test::TestMultipleObjects();
				break;

			case 4:
				delete test;
				test = new test::TestRotate();
				break;
			}*/
			currentSelection = radioSelection;
		}

		test->OnUpdate(0.0f);
		test->OnRender();
		test->OnImGuiRender();

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}