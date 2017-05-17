#include <heap.h>
#include <test.h>

extern void initRandNumGen(void);
extern int randomNumGen(int num);
extern Data_t* allocateData();
extern void PrintData(Node_t *node);
extern void PrintHeap(Heap_t *heap);

void print_usage() {
	printf("./test1 <num of elements>\n");
	return;
}

int main(int argc, char *argv[]) {
	Heap_t *heap = NULL;
	Node_t *node = NULL;
	int numOfElements = 0;
	int i = 0;
	Data_t *data = NULL;

	if (argc != 2) {
		fprintf(stderr, "Invalid argument\n");
		print_usage();
		return -1;
	}

	numOfElements = atoi(argv[1]);
	if (numOfElements == 0) {
		fprintf(stderr, "Number of elements is zero\n");
		return -1;
	}
	heap = AllocateHeap(numOfElements);
	if (heap == NULL) {
		printf("Unable to Allocate MinHeap\n");
		return -1;
	}
	initRandNumGen();
	for (i = 0; i < numOfElements; i++) {
		data = allocateData();
		InsertIntoMinHeap(&heap, (void *)data, randomNumGen(numOfElements));
	}
	node = GetMinNode(heap);
	PrintNodeKey(node);
	PrintHeapKey(heap);
	PrintHeap(heap);
	node = ExtractMin(&heap);
	PrintNodeKey(node);
	PrintData(node);
	PrintHeapKey(heap);
	FreeHeap(&heap);
	PrintHeapKey(heap);
	return 0;
}
