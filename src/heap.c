#include <heap.h>

// Allocate Heap Data Structure
Heap_t* AllocateHeap(int size) {
	Heap_t *heap = NULL;

	heap = (Heap_t *)malloc(sizeof(Heap_t));
	if (heap == NULL) {
		fprintf(stderr, "%s:%s:%d:Malloc Error\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	memset(heap, 0, sizeof(Heap_t));
	heap->capacity = size;
	heap->node = (Node_t **)malloc(size * sizeof(Node_t*));
	if (heap->node == NULL) {
		fprintf(stderr, "%s:%s:%d:heap->node: Malloc Error\n", __FILE__, __func__, __LINE__);
		free(heap);
		return NULL;
	}
	heap->size = 0;
	memset(heap->node, 0, (size * sizeof(Node_t*)));
	return heap;
}

//Print Heap Key
void PrintHeapKey(Heap_t *heap) {
	int i = 0;

	if (heap == NULL) {
		fprintf(stderr, "%s:%s:%d: Heap is NULL\n", __FILE__, __func__, __LINE__);
		return;
	}
	if (heap->size == 0) {
		fprintf(stderr, "%s:%s:%d: Heap is empty\n", __FILE__, __func__, __LINE__);
		return;
	}
	printf("Heap Keys:\t");
	for (i = 0; i < heap->size; i++) {
		printf("%d\t", heap->node[i]->key);
	}
	printf("\n");
}

// Free Heap Data Structure
void FreeHeap(Heap_t **heapPtr) {
	int i = 0;
	if (heapPtr == NULL) {
		return;
	}
	if (*heapPtr == NULL) {
		return;
	}
	if ((*heapPtr)->node != NULL) {
		for (i = 0; i < (*heapPtr)->size; i++) {
			free((*heapPtr)->node[i]);
			(*heapPtr)->node[i] = NULL;
		}
		free((*heapPtr)->node);
		(*heapPtr)->node = NULL;
	}
	free(*heapPtr);
	*heapPtr = NULL;
	return;
}

// Print Node Key
void PrintNodeKey(Node_t *node) {
	if (node == NULL) {
		fprintf(stderr, "%s:%s:%d: Node is NULL\n", __FILE__, __func__, __LINE__);
		return;
	}
	printf("%s:%s:%d: Node(key) = %d\n", __FILE__, __func__, __LINE__, node->key);
	return;
}
