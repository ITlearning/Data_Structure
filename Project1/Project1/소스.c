#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define MAZE_SIZE 7

typedef struct {
	int row;
	int col;
} element;

element stack[STACK_SIZE];
int top = -1;

element here = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
		{'1', '1', '1', '1', '1', '1', '1'},
		{'0', '0', '1', '0', '0', '0', '0'},
		{'1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '1', '0', '1'},
		{'0', '0', '1', '1', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1', 'x'},
		{'1', '0', '1', '1', '0', '0', '0'},
};


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
		return ;
	}
	else return stack[top--];	// 현재 top의 원소를 삭제한 후 top 감소
}

element peek() {			// 스택의 top 원소를 검색하는 연산
	if (isEmpty()) {		// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty ! \n");
		return;
	}
	else return stack[top];	// 현재 top의 원소 확인
}

void pushLocation(int row, int col) {
	if (row < 0 || row > MAZE_SIZE - 1 || col < 0 || col > MAZE_SIZE - 1) {
		return;
	}

	if (maze[row][col] != '1' || maze[row][col] != '.') {
		element temp;

		temp.row = row;
		temp.col = col;

		push(temp);
	}
}

void printMaze() {
	int i, j;

	system("cls");

	for (i = 0; i < MAZE_SIZE; i++) {
		for (j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}
	}
}

int main(void) {
	int r, c;

	maze[here.row][here.col] = 'e';
	printMaze();
	getchar();

	while (maze[here.row][here.col] != 'x') {
		r = here.row;
		c = here.col;
		maze[r][c] = 'm';

		printMaze();
		gerchar();

		maze[r][c] = '.';
		pushLocation(r - 1, c); //위쪽
		pushLocation(r + 1, c); //아래쪽
		pushLocation(r, c - 1); //왼쪽
		pushLocation(r, c + 1); //오른쪽

		if (isEmpty()) {
			printf("실패\n");
			return 0;
		}
		else {
			here = pop();
		}

		maze[here.row][here.col] = 'm';
		printMaze();
		printf("성공\n");
	}
}

