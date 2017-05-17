#include <stdio.h>
#include <test.h>
#include <string.h>
#include <stdlib.h>
#include <heap.h>

Data_t* allocateData() {
        Data_t* data = NULL;

        data = (Data_t *)malloc(sizeof(Data_t));
        if (data == NULL) {
                fprintf(stderr, "Malloc Error\n");
                return NULL;
        }
        data->item = rand();
        return data;
}

void PrintData(Node_t *node) {
        if (node == NULL) {
                fprintf(stderr, "Node is null\n");
                return;
        }
        printf("Data(item): %d, Node(key): %d\n", ((Data_t *)(node->data))->item, node->key);
        return;
}

void PrintHeap(Heap_t *heap) {
	int i = 0;

	if (heap == NULL) {
                fprintf(stderr, "Heap is null\n");
		return;
	}
	if (heap->size == 0) {
		fprintf(stderr, "Heap is empty\n");
		return;
	}

	printf("PrintHeap():\t");
	for (i = 0; i < heap->size; i++) {
		printf("%d(%d)\t", ((Data_t *)(heap->node[i]->data))->item, heap->node[i]->key);
	}
	printf("\n");
	return;
}

// Insert element into Heap
int InsertIntoHeap(Heap_t **heapPtr, void *data, int key) {
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
        return 0;
}

void sortHeapInDecreasingOrder(Heap_t **heapPtr, int size) {
	int i = 0;
	int j = 0;
	Node_t *temp = NULL;

	for (i = 0; i < size -1; i++) {
		for (j = i+1; j < size; j++) {
			if ((*heapPtr)->node[i]->key < ((*heapPtr)->node[j]->key)) {
				temp = (*heapPtr)->node[i];
				(*heapPtr)->node[i] = (*heapPtr)->node[j];
				(*heapPtr)->node[j] = temp;
			}
		}
	}
}

void sortHeapInIncreasingOrder(Heap_t **heapPtr, int size) {
	int i = 0;
	int j = 0;
	Node_t *temp = NULL;

	for (i = 0; i < size -1; i++) {
		for (j = i+1; j < size; j++) {
			if ((*heapPtr)->node[i]->key > ((*heapPtr)->node[j]->key)) {
				temp = (*heapPtr)->node[i];
				(*heapPtr)->node[i] = (*heapPtr)->node[j];
				(*heapPtr)->node[j] = temp;
			}
		}
	}
}
