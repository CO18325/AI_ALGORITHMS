#include <iostream>
#include <cstring>
using namespace std;

// N x N chessboard
int N; // KEEP IT BELOW 8 FOR NORMAL COMPUTER EXECUTION

// VARIABLE TO STORE THE RESULT
int count = 0 ;

// MATRIX TO RECORD:
// 			SQUARES WHICH ARE VISITED
//			STEP NUMBER AT WHICH THEY ARE VISITED
int visited[20][20];

// THESE ARE ALL THE POSSIBLE COMBINATIONS OF THE MOVES A KNIGHT CAN MOVE
//EACH PAIR OF ROW AND COL REPRESENTS THE L SHAPED MOVE
int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };


// THIS FUNCTION CHECKS THAT THE MOVE
// DOESN'T LEAD THE KNIGHT OUT OF BOUND OF THE CHESS BOARD
bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}

// FUNCTION TO RECURSIVELY PERFORM KNIGHT'S TOUR RECURSIVELY USING BACKTRACKING
void KnightTour(int x, int y, int pos)
{
	// SETTING THE CURRENT NODE'S STATUS TO VISITED
	// AND ASSIGNING IT THE STEP NUMBER OF THE KNIGHT
	visited[x][y] = pos;


	// IF THE STEP NUMBER INCREASES THE TOTAL NUMBER OF SQUARES
	// IT MEANS WE HAVE REACHED OUR SOLUTION
	
	if (pos >= N*N){
		count ++;
		if (count == 1){
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++)
					cout << visited[i][j] << " ";
				cout << endl;
			}
		}

		
		// backtrack before returning
		visited[x][y] = 0;
		return;
	}

	// CHECK FOR ALL 8 POSSIBLE MOVES
	for (int k = 0; k < 8; k++)
	{

		int newX = x + row[k];
		int newY = y + col[k];

		// IF THE NEW POSITION IS VALID AND NOT VISITED
		// THEN MAKE A RECURSIVE CALL TO THE KNIGHT TOUR FUNCTION
		if (isValid(newX, newY) && !visited[newX][newY])
			KnightTour(newX, newY, pos + 1);
	}

	// BACKTRACK FROM CURRENT SQUARE AND REMOVE IT FROM PATH
	visited[x][y] = 0;
}


int main()
{
	
	printf("ENTER THE BOARD DIMENSION: ");
	scanf("%d",&N);
	
	int x,y;
	
	printf("ENTER THE STARTING ROW POSITION: ");
	scanf("%d",&x);
	
	printf("ENTER THE STARTING COLUMN POSITION: ");
	scanf("%d",&y);
		

	// 0 INITIALIZATION
	memset(visited, 0, sizeof visited);

	// CURRENT STEP NUMBER STARTING FROM 0
	int pos = 1;

	// start knight tour from corner square (0, 0)
	KnightTour(x,y,pos);
	printf("\n\n");
	printf("TOTAL POSSIBLE SOLUTIONS: %d",count);
	return 0;
}
