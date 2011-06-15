#include "quicksort.h"
#include <stdio.h>

void print_array(int x[], unsigned int p, unsigned int q) {
	unsigned int i;
	printf("array[%d..%d]: ", p, q);
	for(i = p; i <= q; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}


int main() {
	int numbers[] = {4,6,1,2,8,13,10,7};	
	quicksort(numbers, 0, sizeof(numbers) / sizeof(int)-1);
	print_array(numbers, 0, sizeof(numbers) / sizeof(int)-1);
	return 0;
}


void swap(int* x, int* y) { 
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

unsigned int partition(int* array, unsigned int p, unsigned int q, unsigned int pivotLocation) {	
	int pivot;
	unsigned int i, j;
	
	pivot = array[pivotLocation];
	swap(&array[pivotLocation], &array[q]);
	i = p;
	for(j = p; j < q; j++) if(array[j] <= pivot) swap(&array[i++], &array[j]);
	swap(&array[q], &array[i]);
	return i;
}

void quicksort(int* array, unsigned int start, unsigned int end) {
	unsigned int r, pivot;
	if(start < end) {
		pivot = (end+start)/2;
		r = partition(array, start, end, pivot);
		quicksort(array, start, r-1);
		quicksort(array, r+1, end);
	}
}
