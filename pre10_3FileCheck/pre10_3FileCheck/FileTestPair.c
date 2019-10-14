//현재 소스코드의 괄호 정상성 검사하기

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

int testPair(char filename[]) {
	char symbol, open_pair;

	FILE *fp = fopen(filename, "r"); //r 읽기모드
	if (fp == NULL)
		printf("Error: 파일 존재하지 않습니다. \n");

	top = -1;

	while ((symbol = fgetc(fp)) != EOF) {
		switch (symbol)	{
		case '(':
		case '[':
		case '{':
			push(symbol);break;
		case ')':
		case ']':
		case '}':
			if (top == -1) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}

	fclose(fp);
	if (top == -1) return 1;
	else return 0;
}

int main() {
	int ret;

	ret = testPair("Reverse.c");
	(ret == 1) ? printf("Reverse.c 괄호 정상\n") : printf("Reverse.c 괄호 비정상\n");

	ret = testPair("FileTestPair.c");
	(ret == 1) ? printf("FileTestPair.c 괄호 정상\n") : printf("FileTestPair.c 괄호 비정상\n");
}