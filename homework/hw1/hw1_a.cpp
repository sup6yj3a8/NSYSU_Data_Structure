#include <iostream>
#include <iomanip>
#define SIZE 9
using namespace std;

void printTable(int table[][SIZE], int row);
void magic(int table[][SIZE], int row, int col);
void next(int table[][SIZE], int *m, int *n, int row, int loop);
void zeroTable(int table[][SIZE]);

int main(){
	int table[SIZE][SIZE] = {{0}};
	zeroTable(table);
	for(int i=1; i<=9; i+=2){
		zeroTable(table); // initiation
		magic(table, i, i);
		cout << "magic square #" << i << ":" << endl;
		printTable(table, i);
		cout << endl;
	}
	return 0;
}

void printTable(int table[][SIZE], int row){
	for(int i=0; i<row; i++){
		for(int j=0; j<row; j++){
			cout << setw(2) << table[i][j] << " ";
		}
		cout << endl;
	}
}

void magic(int table[][SIZE], int row, int col){
	int m=0; //start row
	int n=col/2; //start col
	
	table[m][n]=1; // start
	for(int i=2; i<=row*col; i++){
		next(table, &m, &n, row, i);
	}
}


void next(int table[][SIZE], int *m, int *n, int row, int loop){
	int t1=*m, t2=*n; //copy
	
	// Upper left
	if( --*m % row == -1){
		*m = row-1;
	}
	if( --*n % row == -1){
		*n = row-1;
	}
	
	// Add values
	if(table[*m][*n] == 0){
		table[*m][*n] = loop;
	}else{
		if( (t1+1) % row == 0){
			*m = 0;
		}else{
			*m = t1+1;
		}
		*n = t2;
		table[*m][*n] = loop;
	}	
}

void zeroTable(int table[][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			table[i][j] = 0;
		}
	}
}

