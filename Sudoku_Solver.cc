#include<iostream>
#include<cmath>
using namespace std;

const int Dim = 9;

bool canPlace(int board[][Dim],int x,int y,int curNum){
	// using for loop canPlace function checks whether the given curNum is present in the currrent row or col or in the subMatrix 0f 3X3   
for (int i = 0; i < Dim; ++i)
{

	if(board[i][y] == curNum) return false; //checking current row 
	if(board[x][i] == curNum) return false; // checking current col
}
// checking the subMatrix 
int rootDim = sqrt(Dim);
int subMatRow = x - x%rootDim;
int subMatCol = y - y%rootDim;
for (int i = subMatRow; i < subMatRow + rootDim; ++i)
{
	for (int j = subMatCol; j < subMatCol + rootDim; ++j)
	{
		if(board[i][j] == curNum) return false;
	}
}

return true;

}

bool sudoku(int board[][Dim],int x,int y){
// we will solve it row wise 
// so if all cells are filled 
	if(x==Dim) return true; //this means all the rows have been filled 
	if(y==Dim) { // this means the current row is filled, so we need to shift next row 
		return sudoku(board,x+1,0);
	}
// if a cell in a row is already filled so move to the next cell in that row 
	if(board[x][y]!=0){
		return sudoku(board,x,y+1);
	}
// using for loop we will generate numbers ranging from 1 to 9 in this case uptil Dim, as Dimension of the board is 9
for (int curNum = 1; curNum <= Dim; ++curNum)
	{
		if (canPlace(board,x,y,curNum))
		{   // now using canPlace function we can know whether we can place a number at the current cell, if yes, we assign that number to the current cell
			board[x][y] = curNum;
			bool success = sudoku(board,x,y+1);
			if(success) return true;
			board[x][y] = 0;
		}
	}

	return false;	
}

void input(int board[][Dim]){
	for (int i = 0; i < Dim; ++i)
	{
		for (int j = 0; j < Dim; ++j)
		{
			cin>>board[i][j];
		}
	}
}

void printBoard(int board[][Dim]){

	cout<<endl<<endl;
	for (int i = 0; i < Dim; ++i)
	{
		for (int j = 0; j < Dim; ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main ()
{
	int board[Dim][Dim];
	input(board);
	bool isSuccessful = sudoku(board,0,0);
	if(isSuccessful){
		printBoard(board);	
	}
else cout<<"Hey Man!! get it solved for me"<<endl;
}