/* Martin Aguilar Briones
March 7, 2024
COP 3502
Lab 7*/

#include <stdio.h>
#include <stdlib.h>
void printArray2(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printArray(int arr[], int n, int counter[])
{
    int i,temp=0;
    for (i = 0; i < n; i++)
        printf("%d: %d times is the number %d swapped\n", arr[i],counter[i],arr[i]);
    printf("\n");
    
    for (i=0;i<n;i++) {
    	temp += counter[i];
	}
	
	temp = temp/2;
	
	printf("\nThere are a total of %d swaps\n\n",temp);
}


void selectionSort(int arr[], int n, int counter[])
{
	int i, j, min_idx, temp, count;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		count = 0;
	    //printf("\nIteration# %d\n",i+1);
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx]){
		
			min_idx = j;
		}
		
		//If statement in case the item is in the correct position to not increase counter of swaps
		if(arr[min_idx]==arr[i]) {
			//printArray2(arr, n);

			continue;
		}
		
		// Swap the found minimum element with the first element
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		
		// I add the counter to the item that moves at index i
		counter[i]+=1;
		counter[min_idx]+=1;
		
		temp=counter[i];
        counter[i]=counter[min_idx];
        counter[min_idx]=temp;

		//printArray2(arr, n);
	}
	
	printf("\n\n");
	printArray(arr,n,counter);
	
}
/*
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}*/

// A function to implement bubble sort
// A function to implement bubble sort
void bubbleSort(int arr[], int n, int counter[])
{
  printf("\nUsing Bubble sort\n\n");

   int i, j,temp;
   for (i = 0; i < n-1; i++)
   {
        //printf("Iteration# %d\n",i+1);
        for (j = 0; j < n-i-1; j++)
        {

           if (arr[j] > arr[j+1])
           {//then swap
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
             
             //I add 1 to the counter of both numbers swapped and swap their numbers 
             //in the counter array to make it match indexes
             
             counter[j] +=1;
             counter[j+1] +=1;
             
             temp=counter[j];
             counter[j]=counter[j+1];
             counter[j+1]=temp;
             
           }
           //printArray2(arr, n);
        }

    }
    printf("\n\n");
    printArray(arr,n,counter);
    
}

int main() {
	
	int array1[9] = {97,16,45,61,13,22,7,58,72};
	int array2[9] = {90,80,70,60,50,40,30,20,10};
	int test[9] = {1,2,3,4,5,6,7,8,9};
	int arr[9];
	int counter[9] = {0,0,0,0,0,0,0,0,0};
	int a,n = 9;
	
	for(a=0;a<n;a++) {
		arr[a] = array1[a];
	}
	
	printf("Array bofore sorting: \n");
printArray2(arr, n);
bubbleSort(arr, n,counter);
printf("Sorted array: \n");
printArray2(arr, n);

for(a=0;a<n;a++) {
		counter[a] = 0;
	}

printf("\n\n\nSelection sort\n");
for(a=0;a<n;a++) {
		arr[a] = array1[a];
	}
	
printArray2(arr, n);
selectionSort(arr, n,counter);

//Now with the second array
printf("\n\n\nSecond array\n\n");

for(a=0;a<n;a++) {
		arr[a] = array2[a];
	}
	
for(a=0;a<n;a++) {
		counter[a] = 0;
	}

	
	printf("Array bofore sorting: \n");
printArray2(arr, n);
bubbleSort(arr, n,counter);
printf("Sorted array: \n");
printArray2(arr, n);

for(a=0;a<n;a++) {
		counter[a] = 0;
	}

printf("\n\n\nSelection sort\n");
for(a=0;a<n;a++) {
		arr[a] = array2[a];
	}
	
printArray2(arr, n);
selectionSort(arr, n,counter);
	
	return 0;
	
}