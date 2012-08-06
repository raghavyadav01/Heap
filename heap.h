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

#ifndef __HEAP__
#define __HEAP__
//data structures related to store the data type
#include<stdint.h>
/* This structure defines the Node in the heap
*/
typedef struct HeapNode_t__
{
        int size;
}HeapNode_t;

/*The structure contains the information about the heap
*/
typedef struct MinHeap_t__
{
        HeapNode_t* file_list;
        int maxSize;
        int currSize;
}MinHeap_t;
//function to create a min heap.
MinHeap_t* newMinHeap(uint64_t size );
//function deletes the minHeap 
int deleteMinHeap(MinHeap_t* heap);
//counts the number of elements in minheap
int elementCount( MinHeap_t* heap);
//function returns the root node which is minimum node
int getMin( MinHeap_t* heap );
//function deletes the Min(root) node from heap.
int delMin(MinHeap_t* heap , int *size);
//Function inserts in the heap 
int Insert(MinHeap_t* heap, int size);

#endif
