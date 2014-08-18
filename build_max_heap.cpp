#include <iostream>

using namespace std;

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i + 1;
}

void max_heapify(int *A, int i, int n)
{
	int l,r,largest, temp;

	l = left(i);
	r = right(i);
	if ((l <= n) && A[l] > A[i])
		largest = l;
	else 
		largest = i;
	if ((r <= n) && (A[r] > A[largest]))
		largest = r;
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		
		max_heapify(&A[0], largest, n);
	}
}

void build_max_heap(int *A, int n)
{
	for (int i = n/2; i >= 1; i--)
	{
		max_heapify(&A[0], i, n);
	}
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
	cout << "Before BuildHeap" << endl;
	for (int i=1; i<7; i++)
		cout << arrA[i] << " ";
	cout << endl;

	build_max_heap(&arrA[0], 6);

	// Print out
	cout << "After BuildHeap" << endl;
	for (int i=1; i<7; i++)
		cout << arrA[i] << " ";
	cout << endl;

	return 0;
}