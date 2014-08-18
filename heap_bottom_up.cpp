// Implement HeapBottomUp from the green book

#include <iostream>

using namespace std;

void HeapBottomUp(int *A, int n)
{
	int i, k, v, j;
	bool heap;

	for (i = n/2; i > 0; i--)
	{
		k = i;
		v = A[k];
		heap = false;

		while ((!heap)&&(2*k <= n))
		{
			j = 2*k;
			if (j < n) // there are 2 children
			{
				if (A[j] < A[j+1])
					j = j+1; // right child
			}
			if (v >= A[j])
				heap = true;
			else
			{
				A[k] = A[j];
				k = j;
			}
		} // end while

		A[k] = v;
	}// end for

}

int main()
{
	int arrA[7] = {0};
	arrA[1] = 2;
	arrA[2] = 9;
	arrA[3] = 7;
	arrA[4] = 6;
	arrA[5] = 5;
	arrA[6] = 8;

	// Print out
	cout << "Before HeapBottomUp" << endl;
	for (int i=1; i<7; i++)
		cout << arrA[i] << " ";
	cout << endl;

	HeapBottomUp(&arrA[0], 6);

	return 0;
}

