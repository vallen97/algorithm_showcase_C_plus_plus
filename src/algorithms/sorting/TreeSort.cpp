// https://www.geeksforgeeks.org/tree-sort/
#include "TreeSort.h"

namespace test
{
	struct Node
	{
		int key;
		struct Node* left, * right;
	};

	// A utility function to create a new BST Node
	struct Node* newNode(int item)
	{
		struct Node* temp = new Node;
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}

	// Stores inorder traversal of the BST
	// in arr[]
	void storeSorted(Node* root, int arr[], int& i)
	{
		if (root != NULL)
		{
			storeSorted(root->left, arr, i);
			arr[i++] = root->key;
			storeSorted(root->right, arr, i);
		}
	}

	/* A utility function to insert a new
	Node with given key in BST */
	Node* insert(Node* node, int key)
	{
		/* If the tree is empty, return a new Node */
		if (node == NULL) return newNode(key);

		/* Otherwise, recur down the tree */
		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);

		/* return the (unchanged) Node pointer */
		return node;
	}

	// This function sorts arr[0..n-1] using Tree Sort
	void TreeSort::tree_sort(int arr[], int n)
	{
		struct Node* root = NULL;

		// Construct the BST
		root = insert(root, arr[0]);

		for (int i = 1; i < n; i++)
			root = insert(root, arr[i]);

		// Store inorder traversal of the BST
		// in arr[]
		int i = 0;
		storeSorted(root, arr, i);
	}

	// Driver Program to test above functions
	TreeSort::TreeSort()
	{
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
		matplot::figure()->title("Tree Sort");

		// set data into bar graph
		matplot::bar(y);
		// do not replace the next plot
		matplot::hold(matplot::off);

		// do the sorting
		tree_sort(arr, arr_size);

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

	TreeSort::~TreeSort() {}

}