#include "nurbanuyilmaz_yilmaz_nurbanu_hw6.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board() {

	for( int i =0; i<2; i++) {
		for (int j = 0; j<6; j++) {
			theBoard[i][j] = '-';
		}
		cout<< endl;
	}
}


void Board::displayBoard()const{

	for( int i =0; i<2; i++) {
		for (int j = 0; j<6; j++) {
			cout<< theBoard[i][j]<< " ";
		}
		cout<< endl;
	}	
}


char Board::getOwner(int row, int col)const {

	if((row>=0 && row<2) && (col>=0 && col<6)) {
		if(theBoard[row][col] == '-') {
			return '-';

		}
		if(theBoard[row][col] == 'A') {
			return theBoard[row][col] ;

		}
		if(theBoard[row][col] == 'B') {
			return theBoard[row][col] ;
		}
	}

}

void Board::setOwner(int row, int col, char z) {

	if((row>=0 && row<2) && (col>=0 && col<6)) {
		theBoard[row][col] = z;

	}

}

bool Board::isFull()const {

	for (int i = 0; i<2; i++) {
		for (int j = 0; j<6; j++) {
			if(theBoard[i][j] == '-'){
				return false;

			}
		}
	}
	return true;
}

int Board::countOwnedCells (char harf)const{
	int sayi=0;
	for (int i = 0; i<2; i++) {
		for (int j = 0; j<6; j++) {	
			if( theBoard[i][j] == harf) {
				sayi++;

			}
		}

	}
	return sayi;
}


Player::Player(Board& myboard, char id, int direction) {
	board = &myboard;
	PChar = id;
	dir= direction;
	rem1 = 0;
	rem2 = 0;

}

void Player::move(int adim){
	int count =0;


	while(count!=adim){ 
		if(dir==1) {
			
			if(rem1==1) {
				while(count!=adim && rem2>0 ) {
					count++;
					rem2--;
				}
				if(count!=adim && rem2 ==0 ) {
					count++;
					rem1--;				
				}
			}
			else if(rem1==0) {
				while(count!=adim && rem2<5){
					count++;
					rem2++;				
				}
				if(count!=adim && rem2==5) {
					count++;
					rem1++;		
				}
			}


		}
		else if(dir ==0) {
			
			 if(rem1==0){
				while(count!=adim && rem2>0) {
					count++;
					rem2--;	
				}
				if(count!=adim && rem2==0) {
					count++;
					rem1++;	
				}
			
			}
			else if(rem1==1){
				while(count!=adim && rem2 < 5) {
					count++;
					rem2++;		
				}
				if(count!=adim && rem2==5) {
					count++;
					rem1--;					
				}			
			}
		}
	}
}

void Player::claimOwnership() {
	if (board->getOwner(rem1, rem2) == '-'){
		board->setOwner(rem1, rem2, PChar);	
	}
}

bool Player::wins(){
	if(board->countOwnedCells(PChar)>=7){
		return true;
	
	}
	
	else {
		return false;
		
	}
}

int Player::getRow(){
	return rem1;


}
int Player::getCol(){
	return rem2;


}