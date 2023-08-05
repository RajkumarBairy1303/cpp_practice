// Sorting_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
class SortingAlg
{
public:
	void bubblesort(int *arr, int size)
	{
		bool bflag = false;
		for (int i = 0; i < size-1; i++)
		{
			bflag = false;
			for (int j = 0; j < size-i-1; j++)
			{
				if (arr[j] > arr[j+1])
				{
					std::swap(arr[j], arr[j+1]);
					bflag = true;
				}
			}
			if (bflag == false)
				break;
		}
	}

	void insertionSort(int *arr, int size)
	{
		for (int i = 0; i < size-1; i++)
		{
			for (int j = i + 1; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					std::swap(arr[j], arr[j - 1]);
				}
			}
		}
	}

	void selectionSort(int* arr, int size)
	{
		int minindex = 0;
		for (int i = 0; i < size-1 ; i++)
		{			
			minindex = i;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[minindex] > arr[j])
				{					
					minindex = j;
				}
			}

			if (minindex != i)
			{
				std::swap(arr[i], arr[minindex]);
			}
		}
	}


	void Quicksort(int *arr, int start, int end)
	{
		auto midpoint = [=](int *arr, int low, int high)
		{
			int pivot = arr[high];
			int i = low - 1;

			for (int j = low; j < high; j++)
			{
				if (pivot > arr[j])
				{
					i++;
					std::swap(arr[i], arr[j]);
				}
			}

			std::swap(arr[i + 1], arr[high]);

			return (i + 1);
		};
		if (start < end)
		{
			int mid = midpoint(arr, start, end);
			Quicksort(arr, start, mid-1);
			Quicksort(arr, mid + 1, end);
	    }
	}
	void print(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
	}
};

int main()
{
	std::array<int,10> arr { 3,5,2,4,6,8,1,-1,0,7};
	int size  = std::size(arr);
	SortingAlg sort;
	//sort.bubblesort(arr.data(),size);
	//sort.insertionSort(arr.data(), size);
	//sort.selectionSort(arr.data(), size);
	sort.Quicksort(arr.data(), 0, size-1);
	sort.print(arr.data(), size);	
	return 0;
}

