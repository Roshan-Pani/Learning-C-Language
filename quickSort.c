#include<stdio.h>
#include<stdlib.h>

int partition( int arr[] , int low , int high) {
    int i=low-1,j,pivot=arr[high];

    for(j=low ; j<high ; j++)
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }

    int temp = arr[high];
    arr[high]= arr[i+1];
    arr[i+1]= temp;

    return i+1;
}
void quickSort( int arr[], int low , int high ) {

    if(low >= high) return;
    int q= partition(arr,low,high);
    quickSort(arr,low,q-1);
    quickSort(arr,q+1,high);
}
int main() {

    int arr[10] = { 5,4,3,2,6,1,7,8,9,0 };

    quickSort(arr,0,9);

    for(int i=0 ; i<10 ; i++)
     printf("%d ",arr[i]);
     printf("\n");

     return 0;
}