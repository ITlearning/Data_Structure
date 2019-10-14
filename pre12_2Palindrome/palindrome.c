/*
 * palindrome.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>

typedef char element; 		//데크 원소(element)의 자료형을 char로 정의
typedef struct DQNode {		//이중 연결 리스트 데크의 노드 구조를 구조체로 정의
	element data;
	struct DQNode *llink;
	struct DQNode *rlink;
} DQNode;

typedef struct {		// 데크에서 사용하는 포인터 front와 rear를 구조체로 정의
	DQNode *front, *rear;
} DQueType;



// 공백 데크를 생성하는 연산
DQueType *createDQue() {
	DQueType *DQ;
	DQ = (DQueType *)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}


// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType *DQ, element item) {
	DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if(DQ->rear == NULL) {	// 데크가 공백 상태인 경우
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

int isEmpty(DQueType *DQ) {
	if(DQ->front == NULL)
		return 1;
	else
		return 0;
}

element deleteFront(DQueType *DQ) {
	DQNode *old = DQ->front;
	element item;
	if(isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if(DQ->front->rlink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQueType *DQ) {
	DQNode *old = DQ-> rear;
	element item;
	if(isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if(DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

int checkPalindrome(DQueType *DQ, char str[]) {
	int i = 0;
	char a, b;
	while(str[i] != '\0') {
		insertRear(DQ, str[i++]);
	}

	while(!isEmpty(DQ)){
		a = deleteFront(DQ);
		b = deleteRear(DQ);
		if(a != b) {
			return 0;
		}else {
			if(!isEmpty(DQ)){
				while(!isEmpty(DQ)){
					deleteRear(DQ);
				}
				return 1;
			}
			return 1;
		}
	}
	return 1;
}

int main() {
	DQueType *DQ1 = createDQue(); // 데크 생성
	char str[100];
	int ret;

	while (1) {
		printf("문자열을 입력하세요: ");
		fflush(stdout);
		scanf("%s", str);

		ret = checkPalindrome(DQ1, str);
		if(ret == 1)
			printf("회문입니다. \n");
		else {
			printf("회문이 아닙니다.\n");

			while(!isEmpty(DQ1)){
				char temp = deleteFront(DQ1);
			}
		}
	}
}









