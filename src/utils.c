#include <heap.h>

// Swap Elements in a given heap
void swap(Heap_t **heapPtr, int i, int j) {
	Node_t *temp = NULL;

	temp = (*heapPtr)->node[i];
	(*heapPtr)->node[i] = (*heapPtr)->node[j];
	(*heapPtr)->node[j] = temp;
}
