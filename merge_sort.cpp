#include <iostream>

using namespace std;

void Mergesort(int *& A, int n);
void Merge(int *& L, int nL, int *& R, int nR, int *& A);

int main(int argc, char * argv[])
{
	int i;
	int n;
	n = 8;

    // Hardcode the input
	int * A = new int[n];
	A[0] = 2;
	A[1] = 4;
	A[2] = 1;
	A[3] = 6;
	A[4] = 8;
	A[5] = 5;
	A[6] = 3;
	A[7] = 7;

	cout << "0 1 2 3 4 5 6 7" << endl;
	for (i=0; i<8; i++)
		cout << A[i] << " ";
	cout << endl;

	Mergesort(A, n);

	for (i=0; i<8; i++)
		cout << A[i] << " ";
	cout << endl;

	delete [] A;

	return 0;
}

// Mergesort is to divide the array and merge it back at the end
void Mergesort(int *& A, int n)
{
	int i;

	// Print out A and n
	for (i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;

	// n <-- lenght(A)
	if (n < 2)	// We will not proceed if #element = 1
		return;

	int mid = n/2;

	// Allocate a left and right array
	int * left = new int[mid]; // where to delete
	int * right = new int[n-mid];

	// Initialize the left array using the passed-in array A
	for (i = 0; i < mid; ++i)
		left[i] = A[i];
	
	// Initialize the right array using the passed-in array A
	for (i = mid; i < n; ++i)
		right[i-mid] = A[i];

	// Recursively divide the array left right
	Mergesort(left, mid);
	Mergesort(right, n-mid);

	// Combine the result
	Merge(left, mid, right, n-mid, A);

	// Delete the memory
	delete [] left;
	delete [] right;
}

void Merge(int *& L, int nL, int *& R, int nR, int *& A)
{
	// nL <-- length of L
	// nR <-- length of R
	int i,j,k;
	i = j = k = 0;

	while ((i < nL) && (j < nR))
	{
		if (L[i] < R[j])
		{
			A[k] = L[i];
			++i;
			++k;
		}
		else 
		{
			A[k] = R[j];
			++j;
			++k;
		}
	}

	// Copy the remaining in left array to A
	while (i < nL)
	{
		A[k] = L[i];
		++i;
		++k;
	}

	// Copy the remaining in the right arry to A
	while (j < nR)
	{
		A[k] = R[j];
		++j;
		++k;
	}

}
