#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;
class Board{
public:
	Board(){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				board[i][j] = 0;
			}
		}
	}
	void putX(int row, int col){
		board[row][col] = 1;
	}
	void putO(int row, int col){
		board[row][col] = 2;
	}
	int checkWin(){
		//check Player 1 wins
		//check horizontal
		if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 1)
			return 1;
		if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 1)
			return 1;
		if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 1)
			return 1;
		//check vertical		
		if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 1)
			return 1;
		if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 1)
			return 1;
		if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 1)
			return 1;
		//check diagonal
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 1)
			return 1;
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 1)
			return 1;
		//check Player 2 wins
		//check horizontal
		if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 2)
			return 2;
		if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 2)
			return 2;
		if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 2)
			return 2;
		//check vertical		
		if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 2)
			return 2;
		if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 2)
			return 2;
		if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 2)
			return 2;

		//check diagonal
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 2)
			return 2;
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 2)
			return 2;

		return 0;

	}
	int getAt(int row, int col){
		return board[row][col];
	}
	void showBoard(){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << board[i][j] << "|";
			}
			cout << endl;
		}
	}
	void runAI(){

		//blocking player way
		//check horizontal1
		if (board[0][0] == board[0][1] && board[0][0] == 1 && board[0][2] == 0){
			board[0][2] = 2;
			return;
		}
		if (board[0][1] == board[0][2] && board[0][1] == 1 && board[0][0] == 0){
			board[0][0] = 2;
			return;
		}
		if (board[0][0] == board[0][2] && board[0][0] == 1 && board[0][1] == 0){
			board[0][1] = 2;
			return;
		}
		//check horizontal 2
		if (board[1][0] == board[1][1] && board[1][0] == 1 && board[1][2] == 0){
			board[1][2] = 2;
			return;
		}
		if (board[1][1] == board[1][2] && board[1][1] == 1 && board[1][0] == 0){
			board[1][0] = 2;
			return;
		}
		if (board[1][0] == board[1][2] && board[1][0] == 1 && board[1][1] == 0){
			board[1][1] = 2;
			return;
		}
		//check horizontal 3
		if (board[2][0] == board[2][1] && board[2][0] == 1 && board[2][2] == 0){
			board[2][2] = 2;
			return;
		}
		if (board[2][1] == board[2][2] && board[2][1] == 1 && board[2][0] == 0){
			board[2][0] = 2;
			return;
		}
		if (board[2][0] == board[2][2] && board[2][0] == 1 && board[2][1] == 0){
			board[2][1] = 2;
			return;
		}

		//check vertical 1
		if (board[0][0] == board[1][0] && board[0][0] == 1 && board[2][0] == 0){
			board[2][0] = 2;
			return;
		}
		if (board[1][0] == board[2][0] && board[1][0] == 1 && board[0][0] == 0){
			board[0][0] = 2;
			return;
		}
		if (board[0][0] == board[2][0] && board[0][0] == 1 && board[1][0] == 0){
			board[1][0] = 2;
			return;
		}
		//check vertical 2
		if (board[0][1] == board[1][1] && board[0][1] == 1 && board[2][1] == 0){
			board[2][1] = 2;
			return;
		}
		if (board[1][1] == board[2][1] && board[1][1] == 1 && board[0][1] == 0){
			board[0][1] = 2;
			return;
		}
		if (board[0][1] == board[2][1] && board[0][1] == 1 && board[1][1] == 0){
			board[1][1] = 2;
			return;
		}
		//check vertical 3
		if (board[0][2] == board[1][2] && board[0][2] == 1 && board[2][2] == 0){
			board[2][2] = 2;
			return;
		}
		if (board[1][2] == board[2][2] && board[1][2] == 1 && board[0][2] == 0){
			board[0][2] = 2;
			return;
		}
		if (board[0][2] == board[2][2] && board[0][2] == 1 && board[1][2] == 0){
			board[1][2] = 2;
			return;
		}


		
		//check diagonal
		if (board[0][0] == board[1][1] && board[0][0] == 1 && board[2][2] == 0)
		{
			board[2][2] = 2;
			return;
		}
		if (board[1][1] == board[2][2] && board[1][1] == 1 && board[0][0] == 0)
		{
			board[0][0] = 2;
			return;
		}
		if (board[0][0] == board[2][2] && board[0][0] == 1 && board[1][1] == 0){
			board[1][1] = 2;
			return;
		}

		if (board[0][2] == board[1][1] && board[0][2] == 1 && board[2][0] == 0)
		{
			board[2][0] = 2;
			return;
		}
		if (board[1][1] == board[2][0] && board[1][1] == 1 && board[0][2] == 0)
		{
			board[0][2] = 2;
			return;
		}
		if (board[0][2] == board[2][0] && board[0][2] == 1 && board[1][1] == 0){
			board[1][1] = 2;
			return;
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (board[i][j] == 2){
					if (i < 1 && board[i + 1][j] == 0){
						board[i + 1][j] = 2;
						return;
					}
					else if (i < 2 && board[i + 2][j] == 0){
						board[i + 2][j] = 2;
						return;
					}
					else if (j < 1 && board[i][j + 1] == 0){
						board[i][j + 1] = 2;
						return;
					}

					else if (j < 2 && board[i][j + 2] == 0){
						board[i][j + 2] = 2;
						return;
					}
				}
				else if (board[i][j] == 0){
					board[i][j] = 2;
					return;
				}
			}
		}
	}
private:
	int board[3][3];
};


#endif