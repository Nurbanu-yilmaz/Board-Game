#include <iostream>
#include <string>

using namespace std;

class Board{
private:

	char theBoard[2][6];

public:
	Board();
	void displayBoard()const;
	char getOwner(int row, int col)const;
	void setOwner(int x, int y, char z);
	bool isFull()const;
	int countOwnedCells (char number)const;

};

class Player {
private:

	Board* board;
	char PChar;
	int dir;
	int rem1; //yatay
	int rem2; //dikey

public:
	Player(Board& myboard, char id, int direction);
	void move(int adim);
	void claimOwnership();
	bool wins();
	int getRow();
	int getCol();

};