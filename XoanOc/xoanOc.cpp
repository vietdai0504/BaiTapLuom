#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int A[100][100] = {0};
void printA(int A[][100], int N, ofstream& file)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			file <<setw(2)<< A[i][j] << " ";
		}
		file << endl;
	}
}
void xoanOc(int A[][100], int N, int d)
{
	int value = 1;
	int collumnS = 0, rowS = N - 1, collumnE = N - 1, rowE = 0;
	while (collumnS <= collumnE && rowE <= rowS)
	{
		for (int i = collumnS; i <= collumnE; i++)
		{
			A[rowS][i] = value;
			value += d;
		}
		rowS--;
		for (int i = rowS; i >= rowE; i--)
		{
			A[i][collumnE] = value;
			value += d;
		}
		collumnE--;
		for (int i = collumnE; i >= collumnS; i--)
		{
			A[rowE][i] = value;
			value += d;
		}
		rowE++;
		for (int i = rowE; i <= rowS; i++)
		{
			A[i][collumnS] = value;
			value += d;
		}
		collumnS++;
	}
}
int main()
{
	ifstream fin("XoanOc.inp");
	ofstream fout("XoanOc.out");
	int N, d; fin >> N >> d;
	xoanOc(A, N, d);
	printA(A, N,fout);
}