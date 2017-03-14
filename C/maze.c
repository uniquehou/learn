#include <stdio.h>
#include "stack.c"

// 0表示墙，1表示路
int MAZE[10][10] = { {0,0,0,0,0,0,0,0,0,0},
					 {0,1,1,0,1,1,1,0,1,0}, 
					 {0,1,1,0,1,1,1,0,1,0}, 
					 {0,1,1,1,1,0,0,1,1,0},
					 {0,1,0,0,0,1,1,1,1,0},
					 {0,1,1,1,0,1,1,1,1,0},
					 {0,1,0,1,1,1,0,1,1,0},
					 {0,1,0,0,0,1,0,0,1,0},
					 {0,0,1,1,1,1,1,1,1,0},
					 {0,0,0,0,0,0,0,0,0,0},
					};
int MAZE_begin = {1,1};
int MAZE_end = {8,8};

void InitMaze() {
	for (int i=0; i<10; i++) {
		printf("please enter the status of %d row: ", i);
		for (int j=0; j<10; j++) {
			if (i==0 || i==9) {
				MAZE[i][j] = 0;
			} else if (j==0 || j==9) {
				MAZE[i][j] = 0;
			} else {
				int status;
				scanf("%1d", &status);
				MAZE[i][j] = status;
			}
		}
	}
}

void MazeOutput() {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if ( ! MAZE[i][j] ) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int In_Stack(struct Stack * S, int row, int col) {
	struct Stack * top;
	GetTop(S, top);
	for(; top->prior; top=top->prior) {
		if ( top->data[0]=row && top->data[1]==rol ) {
			return 1;
		}
	}
	return 0;
}

// 此坐标是否可行
int Path(struct Stack * S, int row, int col) {
	if (MAZE[row][col] == 0) {
		return 0;
	}
	if (In_Stack(S, row, col)) {
		return 0;
	}
	return 1;
}

// 是否为死胡同
int DeadEnd(struct Stack * S, int row, int col) {
	int round[4][2] = { {row+1, col}, {row, col+1}, {row-1, col}, {row, col-1} };
	int status[4];
	for(int i=0; i<4; i++) {
		if ( Path(S, round[i][0], round[i][1]) ) {
			status[i] = 1;
		}
	}
	if ( status[0] && status[1] && status[2] && status[3] ) {
		return 1;
	} else {
		return 0;
	}
}

void explore(struct Stack * S) {
	struct Stack * top;
	GetTop(S, top);
	int row = top->data[0], col = top->data[1];

	if ( row == MAZE_end[0] && col == MAZE_end[1] ) {
		exit;
	}
	
	int round[4][2] = { {row+1, col}, {row, col+1}, {row-1, col}, {row, col-1} }; // 按顺时针寻找路
	for (int i=0; i<4; i++) {
		if ( round[i][0] == MAZE_end[0] && round[i][1] == MAZE_end[1] ) {
			exit;
		}
		if ( ! i ) {
			while ( top->data[0] != row && top->data[1] != col ) {
				struct Stack * temp = top;
				top = top->prior;
				free(temp);
			}
		}
		if ( Path(S, round[i]) ) {
			Push(S, round[i]);
			explore(S);
		}
	}
}

void main() {
	struct Stack * S;
	InitStack(S);
	explore(S);

	Push(S, MAZE_begin);
	explore(S);
}