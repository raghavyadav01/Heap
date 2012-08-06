#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
#define SIZE 7
//Global heap 
MinHeap_t* heap = NULL;
typedef enum bool{ FALSE ,TRUE} Error;

int main(int argc , char *argv[] )
{
	int a[SIZE] = {23,35,64,12,5,9,40 };//this is for test purpose inputs can be taken from user.
	int i;
	int data;
	Error error = FALSE;
	//check the correct number of arguments
	if(argc != 1){
		fprintf(stderr,"usage:program \n");
		exit(1);
	}

	//initialize the heap
	if( (heap = newMinHeap( SIZE )) == NULL){
		fprintf(stderr,"error in initilizing the heap\n");
		exit(1);
	}
	//Insert the element in heap
	for(i = 0; i< SIZE ;i++){
		if( Insert(heap , a[i]) == 1){
			fprintf(stderr,"error in inserting element %d in the heap \n",a[i]);
			error = TRUE; 
			break;
		}
	}
	//get the min of heap and print
	//after print delete the minimum from heap 
	for(i = 0 ;i < SIZE ; i++ ){
		if((data = getMin(heap) )== -1){
			fprintf(stderr,"error in getting minimum element %d in the heap \n",a[i]);
			error = TRUE;
			break;
		}
		printf("curr minimum in heap is %d \n",data);
		if(delMin( heap , &data ) == 1){
			fprintf(stderr,"error in deleting minimum element %d in the heap \n",a[i]);
			error = TRUE;
			break;
		}
	}  
	//check success of operation on heap
	if(error)
		printf("operation failed on heap now releasing the heap \n");
	else 
		printf("operation done successfully on heap now releasing the heap \n");
	//Releasing the heap
	deleteMinHeap( heap);
	return 0;
}
