#include<stdio.h>
#include<stdlib.h>
int compare (const void *a, const void *b){
return (*(int*)a - *(int*)b);
}
int findKthSmallestSorting(int arr[], int n, int k) {
qsort(arr, n, sizeof(int), compare);
return arr[k-1];
}
int main() {
int arr[]= { 7, 10,4,3,20,15};
int n= sizeof(arr)/sizeof(arr[0]);
int k=3;
print("The %dth smallest element is : %d\n",k, findKthSmallestSorting(arr,n,k));
return 0;
}
 
