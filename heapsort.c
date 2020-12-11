#include <stdio.h>
#include <stdlib.h>

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
void heapSort(int *arr, int array_size) {
  for (int i = (array_size / 2) - 1; i >= 0; i--){
    tree_sort(arr, i, array_size - 1);
  	
  }
  for (int i = array_size - 1; i >= 1; i--){
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    tree_sort(arr, 0, i - 1);
  }
}
int main(){
  int a[10];
  for (int i = 0; i<10; i++){
    a[i] = rand() % 100;
  }
  for (int i = 0; i<10; i++){
    printf("%d ", a[i]);
  printf("\n");
  }
  heapSort(a, 10); 
  for (int i = 0; i<10; i++){
    printf("%d ", a[i]);
  }
  return 0;}
