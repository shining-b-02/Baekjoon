#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int heap[100001];
	int heap_size;
}Heap;

void initialize(Heap* heap)
{
	heap->heap_size = 0;
	memset(heap->heap, 0, sizeof(heap->heap));
}

void insertheap(Heap* heap, int x)
{
	heap->heap_size = heap->heap_size + 1;
	int i = heap->heap_size;

	while (i != 1 && x > heap->heap[i / 2]) {

		heap->heap[i] = heap->heap[i / 2];
		i /= 2;
	}
	heap->heap[i] = x;
}

int delheap(Heap* heap)
{
	int x = heap->heap[1];
	int temp = heap->heap[heap->heap_size];
	int parent = 1;
	int child = 2;

	if(heap->heap_size > 0)
		heap->heap_size = heap->heap_size - 1;

	while (child <= heap->heap_size) {
		if (child < heap->heap_size && heap->heap[child] < heap->heap[child + 1]) {
			child++;
		}
		if (temp >= heap->heap[child])
			break;
		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}
	heap->heap[parent] = temp;
	if (heap->heap_size == 0)
		heap->heap[1] = 0;

	return x;
}

int main()
{
	int N;
	scanf("%d", &N);

	Heap heap;

	initialize(&heap);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		if (x == 0) {
			printf("%d\n", delheap(&heap));
		}
		else if (x != 0) {
			insertheap(&heap, x);
		}
	}

	return 0;
}