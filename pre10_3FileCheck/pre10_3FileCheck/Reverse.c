// 스택을 이용하여 사용자로부터 입력받은 문자열을 
// 역순으로 출력하기

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;		// 스택 원소 (element)의 자료형을 int로 정의

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {		// 스택이 공백 상태인지 확인하는 연산
	if (top == -1) return 1;
	else return 0;
}

int isFull() {		// 스택이 포화 상태인지 확인하는 연산
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {		// 스택의 top에 원소를 삽입하는 연산
	if (isFull()) {				// 스택이 포화 상태인 경우
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
}


element pop() {			// 스택의 top에서 원소를 삭제하는 연산
	if (isEmpty()) {	// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty!! \n");
		return 0;
	}
	else return stack[top--];	// 현재 top의 원소를 삭제한 후 top 감소
}

element peek() {			// 스택의 top 원소를 검색하는 연산
	if (isEmpty()) {		// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty ! \n");
		return 0;
	}
	else return stack[top];	// 현재 top의 원소 확인
}

void reverse(char a[], char b[]) {
	int i = 0;

	while (a[i] != '\0') {
		push(a[i]);
		i++;
	}
	i = 0;
	while (!isEmpty()) {
		b[i] = pop();
		i++;
	}

	b[i] = '\0';
}

int main() {
	char str[100];
	char rev[100];

	while (1) {
		printf("문자열을 입력하세요 : ");
		scanf("%s", str);

		reverse(str, rev);

		printf("원본 : %s		역순 : %s\n\n", str, rev);
	}
}