#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ЦУКЕНГШЛОРИМАПРОГРТИРОШЛОТasas

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void tree_sort(int *arr, int root, int size){
	int maxChild;
	while (root * 2+1<= size) {
    	if (root * 2 == size){
		maxChild = root * 2;    
		}
    else {
	    if (arr[root * 2] > arr[root * 2 + 1]){
	      maxChild = root * 2;
	    }
    else{
    	maxChild = root * 2 + 1;
    	}
}
    if (arr[root] < arr[maxChild]) {
      int temp = arr[root];
      arr[root] = arr[maxChild];
      arr[maxChild] = temp;
      root = maxChild;
    }
}
}

void heapSort(int *arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
		tree_sort(arr, i, size);
	for (int i = size - 1; i > 0; --i) 
	{
		swap(&arr[0], &arr[i]);
		tree_sort(arr, 0, i);
	}
}

void quickSort(int* arr, int size, int i){
	if (i < log(size)){
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
			quickSort(arr, j,i);
			quickSort(arr+k, size - k,i);
	}
}

void introsort(int * arr, int size){	
	quickSort(arr, size, 0);
	heapSort(arr, size);
}

int main(int argc, char * argv[])
{	
	clock_t t;
	int size;
	scanf("%d", &size);
	int * arr = malloc(size * sizeof(int));
	if(arr == NULL){
	 	return 0;
	}
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	t = clock();
	introsort(arr, size);
	t = clock() - t;
	for(int i = 0; i < size-1; i++){
		printf("%d ", arr[i]);
	}
	printf("Время %f", (float)t/CLOCKS_PER_SEC);
	free(arr);
	return 0;
}
