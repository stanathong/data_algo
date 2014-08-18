#include <iostream>

using namespace std;

int Partition(int *& A, int l, int r)
{
	int temp;
	int i, j;
	i = l;	// Less than the left most by 1 (actual start is l+1)
			// Since A[l] is pivot
	j = r+1;	// More than the right most by 1

	int pivot = A[l];
	
	/*
		repeat
			....
		until condition is true

		-----
		In this case, condition is i >= j
	
	*/

	do
	{
		// Repeat until A[i] >= pivot
		do
		{
			i = i+1;
		} while (A[i] < pivot);

		// Repeat until A[j] <= pivot
		do
		{
			j = j-1;
		} while (A[j] > pivot);

		// Swap A[i] with A[j]
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;

	} while (i<j); // If i<j, we continue. If not, it is cross-over.
	
	// After crossing over, undo last swap when i>=j
	// Swap A[i] with A[j]
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;

	// Swap A[j] with pivot
	A[l] = A[j];
	A[j] = pivot;

	// Above code is equivalent with
	/*
	A[l] = A[i];
	A[i] = A[j];
	A[j] = pivot;
	*/

	return j;
}

void Quicksort(int *& A, int l, int r)
{
	if (l < r) // if l=r, we don't have to partition
	{
		int s = Partition(A, l, r);
		Quicksort(A, l, s-1); // Left side of A
		Quicksort(A, s+1, r); // Right side of A
	}
}

int main(int argc, char * argv[])
{
	//			0  1  2  3  4  5  6  7
	// int A[8] = {5, 3, 1, 9, 8, 2, 4, 7};

	int * A = new int[8];
	A[0] = 5;
	A[1] = 3;
	A[2] = 1;
	A[3] = 9;
	A[4] = 8;
	A[5] = 2;
	A[6] = 4;
	A[7] = 7;

	int i;
	for (i=0; i<8; i++)
		cout << i << " ";
	cout << endl;

	for (i=0; i<8; i++)
		cout << A[i] << " ";
	cout << endl;

	Quicksort(A, 0, 7);

	for (i=0; i<8; i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}