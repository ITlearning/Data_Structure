/*
 * maze.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */

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

element here = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
		{'1','1','1','1','1','1','1'},
		{'0','0','1','0','0','0','0'},
		{'1','0','0','0','1','0','1'},
		{'1','0','1','0','1','0','1'},
		{'0','0','1','1','0','0','1'},
		{'1','0','1','0','0','1','x'},
		{'1','0','1','1','0','0','0'},
};

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if(isFull()){
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;
}


element pop() {
	if(isEmpty()) {
		printf("\n\n Stack is Empty!! \n");
		element temp = {-1, -1};
		return temp;
	}
	else return stack[top--];
}


element peek() {
	if(isEmpty()) {
		printf("\n\n Stack is Empty! \n");
		element temp = {-1, -1};
		return temp;
	}
	else return stack[top];
}

void pushLocation(int row, int col) {
	if ((0 > row || row > MAZE_SIZE-1) || (0 > col || col > MAZE_SIZE-1)){
		return;
	}

	if((maze[row][col] != '1') && (maze[row][col] != '.')){
		element temp;
		temp.row = row;
		temp.col = col;
		push(temp);
	}
}


void printMaze() {
	int i, j;

	system("cls");

	for(i = 0; i < MAZE_SIZE; i++){
		for(j = 0; j < MAZE_SIZE; j++){
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int r, c;

	maze[here.row][here.col] = 'e';
	printMaze();
	fflush(stdout);
	getchar();

	while(maze[here.row][here.col] != 'x'){
		r = here.row;
		c = here.col;
		maze[r][c] = 'm';

		printMaze();
		getchar();

		maze[r][c] = '.';
		pushLocation(r - 1, c); //r-1, c; 위쪽
		pushLocation(r + 1, c); //r+1, c; 아래쪽
		pushLocation(r, c - 1); //r, c-1; 왼쪽
		pushLocation(r, c + 1); //r, c+1; 오른쪽

		if(isEmpty()) {
			printf("실패\n");
			return 0;
		}
		else
		     here = pop();
 	}

	maze[here.row][here.col] = 'm';
	printMaze();
	printf("성공\n");
}










