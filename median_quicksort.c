#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SIZE;
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void show(int arr[]) {
	int i;
	for(i = 0; i < SIZE; ++i) printf("%d ", arr[i]);
	printf("\n");
}

int pickPivot(int* arr, int a, int b) { // median-of-three
	int i = (a+b)>>1, x = arr[a], y = arr[i], z = arr[b];
	if(x > y) {
		if(y > z) return i;
		if(x > z) return b;
		return a;
	}
	if(y < z) return i;
	if(x < z) return b;
	return a;
}

int partition(int* arr, int a, int b, int pivotPosition) {
	int pivotValue = arr[pivotPosition];
	int i, newPivot;
	
	if(a != pivotPosition) swap(arr, a, pivotPosition);

	for(i = newPivot = a+1; i <= b; ++i) {
		if(arr[i] > pivotValue) continue;
		swap(arr, i, newPivot);
		++newPivot;
	}
	
	--newPivot;
	swap(arr, newPivot, a);
	return newPivot;
}

void quicksort(int* arr, int a, int b) {
	if(b-a < 2) {
		if(b-a == 1 && arr[a] > arr[b]) swap(arr, a, b);
		return;
	}
	
	int p = pickPivot(arr, a, b);
	int newPivot = partition(arr, a, b, p);

	quicksort(arr, a, newPivot-1);
	quicksort(arr, newPivot+1, b);
}


void quick(int arr[]) {
	quicksort(arr, 0, SIZE-1);
}

int main(int argc, char** argv) {
	SIZE = argc > 1 ? atoi(argv[1]) : 100;
	int* arr = malloc(SIZE*sizeof(int));
	int i;

	srand(time(NULL));
	for(i = 0; i < SIZE; i++) arr[i] = rand() % SIZE;

	printf("Before: ");
	show(arr);
	
	quick(arr);
	
	printf("After: ");
	show(arr);

	free(arr);
	
	return 0;
}
