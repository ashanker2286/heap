#include <heap.h>
#include <test.h>

extern void initRandNumGenUniq(int num);
extern void deinitRandNumGenUniq(void);
extern int randomNumGenUniq(int num);
extern Data_t* allocateData();
extern void PrintData(Node_t *node);
extern void PrintHeap(Heap_t *heap);
extern int InsertIntoHeap(Heap_t **heapPtr, void *data, int key);
extern void sortHeapInIncreasingOrder(Heap_t **heapPtr, int size);


void print_usage() {
	printf("./testMinHeapUniq <num of elements>\n");
	return;
}

int main(int argc, char *argv[]) {
	Heap_t *heap = NULL;
	Heap_t *sortedHeap = NULL;
	Node_t *node = NULL;
	int numOfElements = 0;
	int randomNum = 0;
	int i = 0;
	Data_t *data = NULL;
	Data_t *sData = NULL;

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
		printf("Unable to Allocate Heap\n");
		return -1;
	}
       	sortedHeap = AllocateHeap(numOfElements);
       	if (sortedHeap == NULL) {
        	printf("Unable to Allocate Heap\n");
                return -1;
        }

	initRandNumGenUniq(numOfElements);
	for (i = 0; i < numOfElements; i++) {
		data = allocateData();
               	randomNum = randomNumGenUniq(numOfElements);
               	InsertIntoMinHeap(&heap, (void *)data, randomNum);
               	InsertIntoHeap(&sortedHeap, (void *)data, randomNum);
	}

        sortHeapInIncreasingOrder(&sortedHeap, numOfElements);
        printf("Sorted Heap: ");
        PrintHeap(sortedHeap);
        printf("Min Heap: ");
        PrintHeap(heap);
        printf("Print Heap Key(sorted Heap): ");
        PrintHeapKey(sortedHeap);
        printf("Print Heap Key(Min Heap): ");
        PrintHeapKey(heap);
	i = 0;
        for (i = 0; i < numOfElements; i++) {
                node = GetMinNode(heap);
                PrintNodeKey(node);
                PrintData(node);
                if (node->key != sortedHeap->node[i]->key) {
                        fprintf(stderr, "Test Failed !!\n");
                        goto cleanUp;
                }
                node = ExtractMin(&heap);
                PrintNodeKey(node);
                PrintData(node);
                if (node->key != sortedHeap->node[i]->key) {
                        fprintf(stderr, "Test Failed !!\n");
                        goto cleanUp;
                }
		sData = (Data_t *)(sortedHeap->node[i]->data);
		data = (Data_t *)(node->data);
		if (sData->item != data->item) {
                        fprintf(stderr, "Test Failed !!\n");
                        goto cleanUp;
		}
                printf("Min Heap: ");
                PrintHeap(heap);
        }
        printf("Test Passed Successfully\n");

cleanUp:
        FreeHeap(&heap);
        FreeHeap(&sortedHeap);
	deinitRandNumGenUniq();
        PrintHeapKey(heap);
	return 0;
}
