#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printlist(int arr[], int size);

void selectSort(int arr[], int n)
{
	int index_min_value;
	int temp;

	for (int i=0; i<n-1; i++)	// outer loop tracks the sorted portion of the list
	{
	    index_min_value = i; //set index_min_value to the current index of array

		for (int j=i+1; j < n; j++)	// inner loop finds the next smallest value
		{
		 	if (arr[j] < arr[index_min_value])
                   index_min_value=j;
		}

        if (index_min_value != i)    // swap to the correct position
        {
           temp = arr[i];
           arr[i] = arr[index_min_value];
           arr[index_min_value] = temp;
        }
				cout << "selection"<< endl;
				cout << i << endl;
				printlist(arr,n);
	}
}


void insertion_sort (int arr[], int length)
{
	int j, temp;

	for (int i = 0; i < length; i++) // outer loop tracks the sorted portion of the list
	{
		j = i;
		while (arr[j-1] > arr[j] && j >= 1)
		// move elements over until find the position for next element
		{
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
		}
		printlist(arr,length);
		cout << i << endl;
	}
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int count=0;
   int i, j;
   for (i = 0; i < n-1; i++)
   {
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
							count++;
						}
					}
			cout << i << endl;
			printlist(arr,n);
   }
	 cout << "count: " << count << endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap = gap/2) // reduce gap by half each iteration
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
    }
}




void printlist(int arr[], int size)
{
for (int i=0; i<size; i++)
	cout << " " << arr[i];
cout << endl;
}

int main()
{
   int arr[]  = {51,72,9,90,60,38};
   int arr2[] = {90,78,60,45,32,9};
   int arr3[] = {94 , 8, 74, 28, 62, 48};
   int arr4[] = {9, 4, 7, 2, 8, 3, 5 };
//   int arr5[] = {9, 4, 7, 2, 8, 3, 5 };
//	selectSort(arr, 6);
//	cout << "Select Sort" << endl;
	//	printlist(arr, 6);
//  insertion_sort(arr2, 6);
//  cout << "Insertion Sort" << endl;
//	printlist(arr2, 6);
		bubbleSort(arr3, 6);
		cout << "Bubble Sort" << endl;
		printlist(arr3, 6);
//	shellSort(arr4, 7);
//	cout << "Shell Sort" << endl;
//	printlist(arr4, 7);
/*
	int n = 10000; int rand_arr[n], rand_arr2[n], rand_arr3[n],rand_arr4[n];
	srand((unsigned)time(NULL));    // return a seed and initialize rand()
	for (int i=0; i<n; i++)         // generate random numbers
	{
		rand_arr[i]=rand()%32767;    //make the range of random number between 0 to 32767
	    rand_arr2[i] = rand_arr[i];
	    rand_arr3[i] = rand_arr[i];
	    rand_arr4[i] = rand_arr[i];
	    cout << rand_arr[i] << '\t';
	}

    clock_t start, finish;
    double duration;
    start = clock();        // start
	  selectSort(rand_arr,n);
    finish = clock();       // clock ends
    duration = (double)(finish-start)/CLOCKS_PER_SEC;
    cout << " selection sort time:" << endl;
    cout << duration << "seconds " << endl;

    //printlist(rand_arr, n);

    start = clock();        // start
    insertion_sort(rand_arr2,n);
    finish = clock();       // clock ends
    duration = (double)(finish-start)/CLOCKS_PER_SEC;
    cout << " insertion sort time:" << endl;
    cout << duration << "seconds " << endl;

    start = clock();        // start
    bubbleSort(rand_arr3,n);
    finish = clock();       // clock ends
    duration = (double)(finish-start)/CLOCKS_PER_SEC;
    cout << " bubble sort time:" << endl;
    cout << duration << "seconds " << endl;

    start = clock();        // start
    shellSort(rand_arr4,n);
    finish = clock();       // clock ends
    duration = (double)(finish-start)/CLOCKS_PER_SEC;
    cout << " shell sort time:" << endl;
    cout << duration << "seconds " << endl;
	//	printlist(rand_arr4,n);
*/

}
