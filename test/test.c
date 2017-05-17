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
