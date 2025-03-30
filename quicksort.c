#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 2

void quick_sort(int* arr, int size){
	int j = size;
	int k = 0; 
	int c = arr[(int)(j/2)];
	int tmp;
	do{
		while(arr[k] < c){
			k++;
		}
		while(arr[j] > c){
			j--;
			if(k <= j){
				tmp = arr[k];
				arr[k] = arr[j];
				arr[j]= tmp;
				k++;
				j--;
			}
			}
	}while(k <= j);
		quick_sort(arr, j);
		quick_sort(arr+k, size - k);
}

int main() {
	clock_t t;
	int size;
	scanf("%d", &size);
	int arr[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++)arr[i] = rand()%100;
	for(int i = 0; i < size; i++ ){
		printf("%i%i\n", i,arr[i]);
	}
	printf("\n\n");
	t = clock();
	
	quick_sort(arr,size-1);
	
	t = clock() - t;
	for(int i = 0; i < size; i++){
		printf("%i%i\n", i, arr[i]);
	}
	printf("Время %f", (float)t/CLOCKS_PER_SEC);
	return 0;
}
