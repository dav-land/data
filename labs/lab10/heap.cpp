// A C++ program to demonstrate common Binary Heap Operations
#include <iostream>
#include <climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap){
	capacity = cap;
	harr = new int[cap+1];
	heap_size = 0;
}

// Return the index of parent of the node at index i
int MinHeap::parent(int i){
	if(i > 1) return i/2;
	else return -1;
}

// Return index of left child of node at index i
int MinHeap::left(int i){
	if(2 * i <= capacity) return 2*i;
	return -1;
}

// Return index of right child of node at index i
int MinHeap::right(int i){
	if(2 * i + 1 <= capacity) return 2*i+1;
	return -1;
}

// Return the minimum value in the heap
int MinHeap::getMin(){
	if(heap_size > 0) return harr[1];
	return -1;
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k){
	// Corner case: If heap is full
	if(heap_size == capacity) {
		cout << "heap is full" << endl;
		return;
	}
	// increment the heap size
	heap_size++;
	// insert the new key at the end
	harr[heap_size] = k;

	// Fix the min heap property if it is violated
	ReverseHeapify(heap_size);
	//cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
	//cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
	// --- ENTER CODE HERE --- //

	//cout<<endl;
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i){
	int p = parent(i);
	if(harr[p] > harr[i] && p > 0) {
		swap(&harr[i],&harr[p]);
		ReverseHeapify(p);
	}
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i){
	// left and right children
	int l = left(i);
	int r = right(i);
	// set given index as smallest
	int small = i;
	// compare it with its left and right children and set smallest
	if(l <= heap_size && harr[l] <= harr[small]) small = l;
	if(r <= heap_size && harr[r] <= harr[small]) small = r;
	// swap if not less than its one of the children
	if(small != i) {
		swap(&harr[i],&harr[small]);
		MinHeapify(small);
	}
	//cout<<endl<<"Index of "<<harr[i]<<" : "<<i<<endl;
	//cout<<"Parent of "<<harr[i]<<" : "<<harr[parent(i)]<<" at index : "<<parent(i)<<endl;
	//cout<<"Heapifying "<<harr[i]<<" and its subtrees"<<endl;
	//cout<<endl<<"Index of "<<harr[smallest]<<" : "<<smallest<<endl;
	// Heapify
	// ----- ENTER CODE HERE ----
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap(){
	//CORNER CASE: HEAP EMPTY, HEAP SIZE 1
	if(heap_size == 0)
		cout << "heap empty cannot pop"<< endl;
	else if(heap_size == 1)
		heap_size--;
	else{
		harr[1] = harr[heap_size];
		heap_size--;
		MinHeapify(1);
	}
	// Store the minimum value, and remove it from heap

	// Set the last element in the heap as root

	//cout<<endl<<"Replaced root with the Last element"<<endl;

	// Decrease the heap size by 1

	//cout<<"Now the root is : "<< harr[1]<<endl;
	// Move the root to its appropriate place


	// HEAPIFY

}

void MinHeap::printMinHeap(){
	for(int i=1; i<=heap_size; i++)
		cout << i << ":" << harr[i] << endl;
}
// A utility function to swap two elements
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
