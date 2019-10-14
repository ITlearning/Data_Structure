/*
 * Heap_Score.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;

heapType* createHeap() {
	heapType *h = (heapType *)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

void insertHeap(heapType *h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while(( i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] =item;
}


int deleteHeap(heapType *h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while(child <= h->heap_size) {
		if((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;
		if(temp >= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	heapType* heap = createHeap();

	insertHeap(heap, 91);
	insertHeap(heap, 80);
	insertHeap(heap, 74);
	insertHeap(heap, 88);
	insertHeap(heap, 65);
	insertHeap(heap, 100);
	insertHeap(heap, 79);
	insertHeap(heap, 58);
	insertHeap(heap, 75);
	insertHeap(heap, 95);

	int score1 = deleteHeap(heap);
	int score2 = deleteHeap(heap);
	int score3 = deleteHeap(heap);
	double Mean = (score1 + score2 + score3) / (double) 3;
	printf("Score1(%d) Score2(%d) Score3(%d) Mean(%f)", score1, score2, score3, Mean);
}







