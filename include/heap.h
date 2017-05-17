#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RIGHT_CHILD(x) ((2 * x) + 2)
#define LEFT_CHILD(x) ((2 * x) + 1)
#define PARENT(x) ((x - 1)/2)

typedef struct Node_s {
	void *data;
	int key;
} Node_t;

typedef struct Heap_s {
	int size;
	int capacity;
	Node_t **node;
} Heap_t;

Heap_t* AllocateHeap(int size);
void PrintHeapKey(Heap_t *heap);
void FreeHeap(Heap_t **heap);
void PrintNodeKey(Node_t *node);
int InsertIntoMinHeap(Heap_t **heapPtr, void *data, int key);
int MinHeapify(Heap_t **heapPtr, int idx);
Node_t* GetMinNode(Heap_t *heap);
Node_t* ExtractMin(Heap_t **heapPtr);
int InsertIntoMaxHeap(Heap_t **heapPtr, void *data, int key);
int MaxHeapify(Heap_t **heapPtr, int idx);
Node_t* GetMaxNode(Heap_t *heap);
Node_t* ExtractMax(Heap_t **heapPtr);
#endif //HEAP_H
