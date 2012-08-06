/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 * Copyright 2011
 * contributeur : Raghvendra Kumar Yadav (raghavmnnit@gmail.com) 
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * ---------------------------------------
 */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include"heap.h"


/* arguments : index in heap (index is array index)
   output    : parent index in heap 
*/
int parent(int file_list_index)
{
	return (file_list_index - 1) >> 1;
}
/*arguments : index in heap (index is array index)
   output   : left child index in heap
*/
int lchild(int file_list_index)
{
	return (file_list_index << 1) + 1;
}
/* arguments : index in heap (index is array index)
   output    : right child index in heap 
*/
int rchild(int file_list_index)
{
	return (file_list_index << 1) + 2;
}
/* arguments : number of max elements in heap 
   output    : return the heap with proper initialization
*/
MinHeap_t* newMinHeap( uint64_t size )
{
	MinHeap_t* heap = malloc(sizeof(MinHeap_t));
	if(heap == NULL)
		return NULL;
	heap->file_list = malloc(sizeof(HeapNode_t) * size);
	if(heap->file_list == NULL){
		free(heap);
		return NULL;
	}
	heap->maxSize = size;
	heap->currSize = 0;
	return heap;
}
/*function deletes the minHeap .
  It is only called when heap size
  grows then maximum allowed size
*/
int deleteMinHeap(MinHeap_t* heap)
{
	if (heap == NULL) 
		return 1 ;
	if (heap->file_list != NULL) 
		free(heap->file_list);
	free(heap);
	return 1;
}
/*arguments : heap
  output    : number of elements in heap
*/
int elementCount( MinHeap_t* heap)
{
	return heap->currSize;
}

/* arguments :heap index1 and index2 
   this function is used during heapify to swap values at two index
*/
void swap(MinHeap_t* heap, int file_list_index1 , int file_list_index2)
{
	HeapNode_t temp = heap->file_list[file_list_index1];
	heap->file_list[file_list_index1] = heap->file_list[file_list_index2];
	heap->file_list[file_list_index2] = temp;
}
/* arguments: heap ,index
   function the performs the heapify operation 
   after a value is inserted in heap
*/
void moveUp(MinHeap_t* heap, int file_list_index)
{
	while ((file_list_index > 0) && (heap->file_list[parent(file_list_index)].size > heap->file_list[file_list_index].size)) {
		swap(heap, parent(file_list_index), file_list_index);
		file_list_index = parent(file_list_index);
	}
}
/* arguments: heap ,index
   function the performs the heapify operation 
   after a value is inserted in heap
*/
void moveDown(MinHeap_t* heap, int file_list_index) 
{
	int left ,right , lsize ,rsize;
	int sfile_list_index , ssize; 
	while ( 1 ) {
		left = lchild(file_list_index);
		right = rchild(file_list_index);

		lsize = left < heap->currSize ? heap->file_list[left].size : INT32_MAX;
		rsize = right < heap->currSize ? heap->file_list[right].size : INT32_MAX;

		sfile_list_index = (lsize < rsize) ? left : right;
		ssize = (lsize < rsize) ? lsize : rsize;
		if (heap->file_list[file_list_index].size > ssize) {
			swap(heap, file_list_index, sfile_list_index);
			file_list_index = sfile_list_index;
		} else {
			break;
		}
	}
}
/* arguments : heap
   output    : minimum value in the heap 
               basically root node
*/
int getMin( MinHeap_t* heap )
{
	if (heap->currSize == 0)
		return -1;//no element in heap

	return heap->file_list[0].size;
}
/* arguments : heap ,size 
   output    : delete the root node and 
               perform the heapify operation to 
               maintain property of min heap 
*/
int delMin(MinHeap_t* heap , int* size) 
{
	if (heap->currSize == 0) 
		return 1;

	*size = heap->file_list[0].size;
	swap(heap, 0, heap->currSize - 1);

	--(heap->currSize);
	moveDown(heap, 0);
	return 0;
}

/* arguments : heap , size
   This funcion is used to insert the value
   in heap and perform the heapify to retain 
   min heap prperty
*/
int Insert(MinHeap_t* heap, int size)
{
	if (heap->currSize > heap->maxSize ){
		deleteMinHeap( heap );
		return 1;
	}

	heap->file_list[heap->currSize].size = size;

	int file_list_index = (heap->currSize)++;
	moveUp(heap, file_list_index);
	return 0;
}
