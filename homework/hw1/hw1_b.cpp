#include <iostream>
#define SIZE 101
using namespace std;

int* factorial(int num, int big[], int *ptr);
void zero(int num[]);

int main(){
	int num;
	int big[SIZE]={1, 0};
	int *ptr;
	
	while(cin >> num){
		// Initiation
		zero(big);
		ptr = big;
		
		// Factorial
		for (int i=1; i<=num; i++){
			ptr = factorial(i, big, ptr);
		}
		cout << endl; // New line
	}
	return 0;
}

int* factorial(int num, int big[], int *ptr){
	ptr += 2;
	int len = ptr-big;
	
	// Multiplication
	for (int i=0; i<len; i++){
		big[i] *= num;
	}
	
	// Carrying
	for (int i=0; i<len; i++){
		if (big[i]>=10){
			big[i+1] += (big[i] / 10);
			big[i] %= 10;
		}
	}
	
	// Find max digits
	while( *(ptr-1) == 0){
		ptr--;
	}
	len = ptr-big;
	
	// Printing
	cout << num << "!=";
	for (int i=len-1; i>=0; i--){
		cout << big[i];
	}
	cout << endl;
	
	return ptr;
}


void zero(int num[]){
	num[0] = 1;
	for (int i=1; i<101; i++){
		num[i] = 0;
	}
}

