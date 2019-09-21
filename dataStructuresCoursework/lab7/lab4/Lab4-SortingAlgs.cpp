#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printlist(int arr[], int size)
{
for (int i=0; i<size; i++)
	cout << " " << arr[i];
cout << endl;
}

void selectSort(int arr[], int n)
{
	int index_min_value;
	int temp;

	for (int i=0; i<n-1; i++)	// outer loop tracks the sorted portion of the list
	{
	    index_min_value = i; //set index_min_value to the current index of array

		for (int j=i+1; j < n; j++)	// inner loop finds the next smallest value
		{
		 	if (      arr[j] < arr[index_min_value]   )
                   index_min_value=j;
		}

        if (index_min_value != i)    // swap to the correct position
        {
           temp = arr[i];
           arr[i] = arr[index_min_value];
           arr[index_min_value] = temp;
        }
				printlist(arr, 7);
	}
	cout << endl;

}
	// best case  and worst case for selection sort is always n^2


void insertion_sort (int arr[], int length)
{
	int j, temp;

	for (int i = 0; i < length; i++) // outer loop tracks the sorted portion of the list
	{
		j = i;
		while (    j > 0 && arr[j] < arr[j-1]             )
		// move elements over until find the position for next element
		{
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
				printlist(arr, 7);
		}
	}
	cout << endl;
}
// Best Case O(n), worst case O(n^2)

//
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
   {
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (       arr[j] > arr[j+1]       )
              swap(&arr[j], &arr[j+1]);
	 		printlist(arr, 7);
   }
	 cout << endl;
}
// worst case = n^2 and best case is n^2


void shellSort(int arr[], int n)
{
		int gap;
    for (         gap = n/2; gap > 0; gap /= 2           ) // reduce gap by half each iteration
    {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
				printlist(arr, 7);
    }
		cout << endl;
}




// void printlist(int arr[], int size)
// {
// for (int i=0; i<size; i++)
// 	cout << " " << arr[i];
// cout << endl;
// }

int main()
{
	int arr[] = {9, 4, 7, 2, 8, 3, 5 };
	// //printlist(arr, 7);
	selectSort(arr, 7);
	//printlist(arr, 7);

	int arr2[] = {9, 4, 7, 2, 8, 3, 5 };
	insertion_sort(arr2, 7);

	int arr3[] = {9, 4, 7, 2, 8, 3, 5 };
	bubbleSort(arr3, 7);

	int arr4[] = {9, 4, 7, 2, 8, 3, 5 };
	shellSort(arr4, 7);
	return 0;
  //  int arr[] = {9, 4, 7, 2, 8, 3, 5 };
  //  int arr2[] = {9, 4, 7, 2, 8, 3, 5 };
  //  int arr3[] = {9, 4, 7, 2, 8, 3, 5 };
  //  int arr4[] = {9, 4, 7, 2, 8, 3, 5 };
  //  int arr5[] = {9, 4, 7, 2, 8, 3, 5 };
	// selectSort(arr, 7);
	// printlist(arr, 7);
	// insertion_sort(arr2, 7);
	// printlist(arr2, 7);
	// bubbleSort(arr3, 7);
	// printlist(arr3, 7);
	// shellSort(arr4, 7);
	// printlist(arr4, 7);
	//
	// int n = 10000; int rand_arr[n], rand_arr2[n], rand_arr3[n],rand_arr4[n];
	// srand((unsigned)time(NULL));    // return a seed and initialize rand()
	// for (int i=0; i<n; i++)         // generate random numbers
	// {
	// 	rand_arr[i]=rand()%32767;    //make the range of random number between 0 to 32767
	//     rand_arr2[i] = rand_arr[i];
	//     rand_arr3[i] = rand_arr[i];
	//     rand_arr4[i] = rand_arr[i];
	//     cout << rand_arr[i] << '\t';
	// }
	//
  //   clock_t start, finish;
  //   double duration;
  //   start = clock();        // start
  //   selectSort(rand_arr,n);
  //   finish = clock();       // clock ends
  //   duration = (double)(finish-start)/CLOCKS_PER_SEC;
  //   cout << " selection sort time:" << endl;
  //   cout << duration << "seconds " << endl;
	//
  //   //printlist(rand_arr, n);
	//
  //   start = clock();        // start
  //   insertion_sort(rand_arr2,n);
  //   finish = clock();       // clock ends
  //   duration = (double)(finish-start)/CLOCKS_PER_SEC;
  //   cout << " insertion sort time:" << endl;
  //   cout << duration << "seconds " << endl;
	//
  //   start = clock();        // start
  //   bubbleSort(rand_arr3,n);
  //   finish = clock();       // clock ends
  //   duration = (double)(finish-start)/CLOCKS_PER_SEC;
  //   cout << " bubble sort time:" << endl;
  //   cout << duration << "seconds " << endl;
	//
  //   start = clock();        // start
  //   shellSort(rand_arr4,n);
  //   finish = clock();       // clock ends
  //   duration = (double)(finish-start)/CLOCKS_PER_SEC;
  //   cout << " shell sort time:" << endl;
  //   cout << duration << "seconds " << endl;




}
