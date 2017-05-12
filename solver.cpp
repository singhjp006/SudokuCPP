#include <iostream>
using namespace std;
int n=9;
int ** grid;
bool findUnassigned(int & row, int &col){
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			if(grid[i][j]==0){
				row=i;
				col=j;
				return true;
			}
			
		}
	}
	return false;
} 
bool isLegal(int row, int col, int num){
	// check in its row , column and block whether the number is already present or not
	for(int j=0; j<n; j++){
		if(grid[row][j]==num){
			return false;
		}
	}
	for(int i=0; i<n; i++){
		if(grid[i][col]==num){
			return false;
		}
	}
	int blockRow=(row/3)*3;
	int blockCol=(col/3)*3;
	
	for(int i=blockRow; i<=blockRow+2;i++){
		for(int j=blockCol; j<=blockCol + 2 ;j++){
			if(grid[i][j]==num)
				return false;
		}
	}
	return true;
}
void printGrid(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<grid[i][j]<<" ";
			}
		cout<<endl;
	}
}
bool solveSudoku(){
	int currentRow;
	int currentCol;
	bool checkUnassigned=findUnassigned(currentRow, currentCol);
	if(!checkUnassigned){
		cout<<"sudoku solved"<<endl;
		return true;
	}
	else{
		for(int i=1; i<=9; i++){
			if(isLegal(currentRow, currentCol,  i)){
				grid[currentRow][currentCol]=i;
				if(solveSudoku()){
					return true;
				}
				grid[currentRow][currentCol]=0;
					
				
			}
			
		}
	}
	
	return false;
}
int main(){
	// input the sudoku problem
	
	grid= new int*[n];
	for(int i=0;i<n; i++){
		grid[i]=new int [n];
	}
	// 0 denotes empty space while rest numbers 1-9 as in sudoku
	
	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			cin>>grid[i][j];	
		}
	}
	int count=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			if(grid[i][j]==0)
			 count++;
		}
	}
	if(count==0){
		cout<<"the grid is already filled";
		return 0;
	}
	
	if(solveSudoku())
		printGrid();
}
// this one works
