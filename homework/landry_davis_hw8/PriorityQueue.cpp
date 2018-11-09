#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;

void swap(PatientNode *x,PatientNode *y);

PriorityQueue::PriorityQueue(int _queueSize){
	maxQueueSize = _queueSize;
	priorityQueue = new PatientNode[maxQueueSize + 1];
	currentQueueSize = 0;
}

PriorityQueue::~PriorityQueue(){
	delete[] priorityQueue;
	priorityQueue = nullptr;
}

void PriorityQueue::enqueue (std::string _name, int _injurySeverity, int _treatmentTime){
	PatientNode temp;
	temp.name = _name;
	temp.injurySeverity = _injurySeverity;
	temp.treatmentTime = _treatmentTime;

	if(currentQueueSize == maxQueueSize){
		return;
	}

	currentQueueSize++;
	priorityQueue[currentQueueSize] = temp;
	repairUpward(currentQueueSize);
}

string PriorityQueue::peekName(){
	if(currentQueueSize > 0) return priorityQueue[1].name;
	else{
		return "Empty";
	}
}

int PriorityQueue::peekInjurySeverity(){
	if(currentQueueSize > 0) return priorityQueue[1].injurySeverity;
	else{
		return -1;
	}
}

int PriorityQueue::peekTreatmentTime(){
	if(currentQueueSize > 0) return priorityQueue[1].treatmentTime;
	else{
		return -1;
	}
}

void PriorityQueue::dequeue(){
	if(currentQueueSize == 0);
	else if(currentQueueSize == 1) currentQueueSize--;
	else{
		priorityQueue[1] = priorityQueue[currentQueueSize];
		currentQueueSize--;
		repairDownward(1);
	}
}

bool PriorityQueue::isFull(){
	if(currentQueueSize == maxQueueSize) return true;
	return false;
}

bool PriorityQueue::isEmpty(){
	if(currentQueueSize == 0) return true;
	return false;
}


void PriorityQueue::repairUpward(int nodeIndex){
	int p = nodeIndex/2;
	if(priorityQueue[p].injurySeverity < priorityQueue[nodeIndex].injurySeverity && p > 0){
		swap(&priorityQueue[p], &priorityQueue[nodeIndex]);
		repairUpward(p);
	}
	if(priorityQueue[p].injurySeverity == priorityQueue[nodeIndex].injurySeverity && p > 0){
		if(priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime){
			swap(&priorityQueue[p], &priorityQueue[nodeIndex]);
			repairUpward(p);
		}
	}
}

void PriorityQueue::repairDownward(int nodeIndex){
	int l = 2*nodeIndex;
	int r = 2*nodeIndex+1;
	int big = nodeIndex;

	if(l <= currentQueueSize && (priorityQueue[l].injurySeverity > priorityQueue[big].injurySeverity || (priorityQueue[l].injurySeverity == priorityQueue[big].injurySeverity && priorityQueue[l].treatmentTime < priorityQueue[big].treatmentTime))) big = l;
	if(r <= currentQueueSize && (priorityQueue[r].injurySeverity > priorityQueue[big].injurySeverity || (priorityQueue[r].injurySeverity == priorityQueue[big].injurySeverity && priorityQueue[r].treatmentTime < priorityQueue[big].treatmentTime))) big = r;

	if(big != nodeIndex){
		swap(&priorityQueue[big], &priorityQueue[nodeIndex]);
		repairDownward(big);
	}
}

void swap(PatientNode *x,PatientNode *y){
	PatientNode temp = *x;
	*x = *y;
	*y = temp;
}
