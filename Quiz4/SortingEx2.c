#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

static int a[SIZE];

void MaxHeapSort(int n);
void MinHeapSort(int n);
void MaxHeap(int len, int parent);
void MinHeap(int len, int parent);
void swap(int* a, int* b);

int main (int argc, char** argv){
	for(int i=0;i<SIZE;i++){
		a[i] = rand();
	}
	
	MaxHeapSort(SIZE);
	
	puts("Max Heap:");
	for(int i=0;i<SIZE;i++){
		printf("%d\n", a[i]);
	}
	
	MinHeapSort(SIZE);
	
	puts("\nMin Heap:");
	for(int i=0;i<SIZE;i++){
		printf("%d\n", a[i]);
	}
}


//methods
void MaxHeapSort(int n){
	for(int i = n/2; i>=0; i--)	//step 2
		MaxHeap(n,i);
	for(int i = n-1; i > 0; i--){	//step 3
		swap(&a[i], &a[0]);
		MaxHeap(i,0);
	}
}

void MinHeapSort(int n){
	for(int i = n/2; i>=0; i--)	//step 2
		MinHeap(n,i);
	for(int i = n-1; i > 0; i--){	//step 3
		swap(&a[i], &a[0]);
		MinHeap(i,0);
	}
}

void MaxHeap(int len, int parent){
	int temp = a[parent];
	int child = 2*parent +1;
	while(child < len){
		if(child<len-1 && a[child]<a[child+1])
			child++;
		if(temp >= a[child])
			break;
		a[parent] = a[child];
		parent = child;
		child = 2*parent+1;
	}
	a[parent] = temp;
}

void MinHeap(int len, int parent){
	int temp = a[parent];
	int child = 2*parent +1;
	while(child < len){
		if(child<len-1 && a[child]>a[child+1])
			child++;
		if(temp <= a[child])
			break;
		a[parent] = a[child];
		parent = child;
		child = 2*parent+1;
	}
	a[parent] = temp;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
