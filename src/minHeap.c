#include <heap.h>

extern void swap(Heap_t **heapPtr, int i, int j);

int InsertIntoMinHeap(Heap_t **heapPtr, void *data, int key) {
	int i = 0;
	if ((*heapPtr)->size == (*heapPtr)->capacity) {
		printf("%s:%s:%d: Heap is full\n", __FILE__, __func__, __LINE__);
		return -1;
	}
	i = (*heapPtr)->size;
	(*heapPtr)->size = (*heapPtr)->size + 1;
	Node_t *node = NULL;

	node = (Node_t *)malloc(sizeof(Node_t));
	if (node == NULL) {
		printf("%s:%s:%d: Node malloc error\n", __FILE__, __func__, __LINE__);
		return -1;
	}
	node->data = data;
	node->key = key;
	(*heapPtr)->node[i] = node;

	while ((i != 0) && ((*heapPtr)->node[i]->key < (*heapPtr)->node[PARENT(i)]->key)) {
		swap(heapPtr, i, PARENT(i));
		i = PARENT(i);
	}
	return 0;
}

int MinHeapify(Heap_t **heapPtr, int idx) {
	int left = LEFT_CHILD(idx);
	int right = RIGHT_CHILD(idx);
	int min = idx;

	if (((*heapPtr)->size > left) &&
		((*heapPtr)->node[min]->key > (*heapPtr)->node[left]->key)) {
		min = left;
	}
	if (((*heapPtr)->size > right) &&
		((*heapPtr)->node[min]->key > (*heapPtr)->node[right]->key)) {
		min = right;
	}
	if (min != idx) {
		swap(heapPtr, min, idx);
		MinHeapify(heapPtr, min);
	}
}

Node_t* GetMinNode(Heap_t *heap) {
	if (heap == NULL) {
		printf("%s:%s:%d: Heap is NULL\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	if (heap->size == 0) {
		printf("%s:%s:%d: Heap is empty\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	return heap->node[0];
}

Node_t* ExtractMin(Heap_t **heapPtr) {
	Node_t *node = NULL;
	if (heapPtr == NULL) {
		printf("%s:%s:%d: Heap Pointer is NULL\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	if (*heapPtr == NULL) {
		printf("%s:%s:%d: Heap is NULL\n", __FILE__, __func__, __LINE__);
		return NULL;
	}

	if ((*heapPtr)->size <= 0) {
		printf("%s:%s:%d: Heap is empty\n", __FILE__, __func__, __LINE__);
		return NULL;
	}
	if ((*heapPtr)->size == 1) {
		node = (*heapPtr)->node[0];
		(*heapPtr)->size = (*heapPtr)->size - 1;
		return node;
	}

	node = (*heapPtr)->node[0];
	(*heapPtr)->node[0] = (*heapPtr)->node[(*heapPtr)->size - 1];
	(*heapPtr)->size = (*heapPtr)->size - 1;
	MinHeapify(heapPtr, 0);
	return node;
}
