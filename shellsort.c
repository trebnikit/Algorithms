#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int *interval, int size){
	int stepen1, stepen2, stepen3, counter;
	
	stepen1 = 1;
	stepen2 = 1;
	stepen3 = 1;
	counter = -1;
	do{
		if(++counter %2){
			stepen2 *=2;
			interval[counter] = 8*stepen1 - 6*stepen2 + 1;
		} else {
			interval[counter]= 9*stepen1 - 9*stepen3 + 1;
			stepen3 *= 2;
		}
		stepen1 *= 2;
	}
	while(3*interval[counter]<size);
	
	return((counter > 0)?(--counter):(0));
}

void Sort(int *arr, int size) {
	int interval,j,counter;
	int interval_arr[50];
	counter = add(interval_arr, size);

	while(counter >= 0){
		interval= interval_arr[counter--];
		for(int i = interval; i < size; i++){
			int temp = arr[i];
				for(j = i - interval;(j>=0)&&(arr[j] > temp); j -= interval)arr[j+interval] = arr[j];
				arr[j+interval] = temp;
		}
	}
}

int main(void) {
	clock_t t;
	int size;
	int o;
	scanf("%d", &o);
	size = o;
	int arr[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		arr[i] = rand()%100;
	}
	for(int i = 0; i < size; i++){
		printf("№%i %i\n", i, arr[i]);
	}
	printf("\n\n");
	t = clock();
	
	Sort(arr, size);
	
	t = clock()-t;
	for(int i = 0; i < size; i++){
		printf("№%i %i\n", i, arr[i]);
	}
	printf("%f с", (float)t/CLOCKS_PER_SEC);
	return 0;
}
 