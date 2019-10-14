/*
 * Heap_Student.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	char name[20];
	int id;
} Student;

typedef struct {
	Student heap[MAX_ELEMENT];
	int heap_size;
} heapType;

heapType* createHeap() {
	heapType* h = (heapType *)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for(i = 1; i <= h->heap_size; i++) {
		printf("[%s, %d] ", h->heap[i].name, h->heap[i].id);
	}
}

void insertHeap(heapType *h, Student item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while(( i != 1) && (item.id < h->heap[i / 2].id)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] =item;
}

Student deleteHeap(heapType *h) {
	int parent, child;
	Student item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while(child <= h->heap_size) {
		if((child < h->heap_size) && (h->heap[child].id > h->heap[child + 1].id))
			child++;
		if(temp.id <= h->heap[child].id) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

void heapSort(heapType* h) {
	int d = h->heap_size;
	Student o;
	for(int i = 1; i <= d; i++) {
		o = deleteHeap(h);
		printf("\n %s %d",o.name, o.id);
	}

}

int main() {
	heapType* heap = createHeap();
	Student temp;

	strcpy(temp.name, "°­º´ÈÆ");
	temp.id = 20181503;
	insertHeap(heap, temp);

	strcpy(temp.name, "¹Ú¼±±Õ");
	temp.id = 20181498;
	insertHeap(heap, temp);

	strcpy(temp.name, "±è¿¬ÁÖ");
	temp.id = 20181531;
	insertHeap(heap,temp);

	strcpy(temp.name, "ÀÌÁø¿ì");
	temp.id = 20181525;
	insertHeap(heap,temp);

	strcpy(temp.name, "°­ÇöÀÍ");
	temp.id = 20181521;
	insertHeap(heap, temp);

	strcpy(temp.name, "ÀÌº´¿ì");
	temp.id = 20181502;
	insertHeap(heap,temp);

	strcpy(temp.name, "±è½Â°â");
	temp.id = 20181508;
	insertHeap(heap, temp);

	strcpy(temp.name, "Àå°æÈ£");
	temp.id = 20181520;
	insertHeap(heap, temp);

	strcpy(temp.name, "À±º´¼ö");
	temp.id = 20181504;
	insertHeap(heap, temp);

	printHeap(heap);

	heapSort(heap);
}
















