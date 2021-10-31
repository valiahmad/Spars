#include <iostream>
#include <conio.h>
using namespace std;


int A[100][3], B[100][3], C[200][3];
int row_C = 0;


void display() {
	for (int i = 0; i < row_C; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++) {
			cout << "  ";
			cout << C[i][j];
		}
	}

}
void insert(int* A, int* B) {
	C[row_C][0] = *A;
	A++;
	C[row_C][1] = *A;
	A++;
	C[row_C][2] = *A + *B;
	row_C++;
}
bool check_AinC(int i) {
	int j;
	for (j = 1; j < row_C; j++) {
		if ((A[i][0] == C[j][0]) && (A[i][1] == C[j][1]))
			return false;
	}
}
bool check_BinC(int i) {
	int j;
	for (j = 1; j < row_C; j++) {
		if ((B[i][0] == C[j][0]) && (B[i][1] == C[j][1]))
			return false;
	}
}
bool check_A(int row_i, int i) {
	int  j;
	for (j = 1; j < row_i; j++) {
		if ((A[i][0] == B[j][0]) && (A[i][1] == B[j][1]) && ((A[i][2] + B[j][2]) == 0))//check row and column
			return false;
	}
}
bool check_B(int row_i, int i) {
	int  j;
	for (j = 1; j < row_i; j++) {
		if ((B[i][0] == A[j][0]) && (B[i][1] == A[j][1]) && ((B[i][2] + A[j][2]) == 0))//check row and column
			return false;
	}
}
void sum_matrix(int row_A, int row_B) {
	int i, j;
	row_C++;
	C[0][0] = A[0][0];//becuase A's row and A's column are the same than i use one of it
	C[0][1] = A[0][1];
	for (i = 1; i < row_A; i++) {
		for (j = 1; j < row_B; j++) {
			if ((A[i][0] == B[j][0]) && (A[i][1] == B[j][1])) {//check row and column
				if ((A[i][2] + B[j][2]) != 0) {// if the answer is 0 ignore it
					insert(&A[i][0], &B[j][2]);
				}
			}
		}
	}
	for (i = 1; i < row_A; i++)
		if ((check_A(row_B, i)) && (check_AinC(i))) {
			C[row_C][0] = A[i][0];
			C[row_C][1] = A[i][1];
			C[row_C][2] = A[i][2];
			row_C++;
		}
	for (i = 1; i < row_B; i++)
		if (check_B(row_A, i) && check_BinC(i)) {
			C[row_C][0] = B[i][0];
			C[row_C][1] = B[i][1];
			C[row_C][2] = B[i][2];
			row_C++;
		}
	row_C--;
	C[0][2] = row_C;
	display();
}
void get_spars() {
	int i, j;
	int row_A, row_B;
	cout << "\nEnter First Spars\n";
	cout << "Enter First Row\n";
	for (j = 0; j < 3; j++) {
		cin >> A[0][j];
	}
	row_A = A[0][2] + 1;
	for (i = 1; i < row_A; i++) {
		cout << "Enter Row  " << i << "th\n";
		for (j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	cout << "\nEnter Second Spars\n";
	cout << "Enter First Row\n";
	for (j = 0; j < 3; j++) {
		cin >> B[0][j];
	}
	row_B = B[0][2] + 1;
	for (i = 1; i < row_B; i++) {
		cout << "Enter Row  " << i << "th\n";
		for (j = 0; j < 3; j++) {
			cin >> B[i][j];
		}
	}
	sum_matrix(row_A, row_B);
}


int main()
{
	get_spars();

	return 0;
}