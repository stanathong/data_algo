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

void heap_sort(int *A, int n)
{	
	int i;

	build_max_heap(&A[0], n);
	
	// for i = A.length downto 2
	for (i = n; i >= 2; i--)
	{
		// exchange A[1] with A[i]
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;

		n = n-1;

		max_heapify(&A[0],1,n);
	}
}

int main()
{
	// Hard-code the input
	int arrA[7] = {0};
	arrA[1] = 2;
	arrA[2] = 9;
	arrA[3] = 7;
	arrA[4] = 6;
	arrA[5] = 5;
	arrA[6] = 8;

	// Print out
	cout << "Before Heapsort" << endl;
	for (int i=1; i<7; i++)
		cout << arrA[i] << " ";
	cout << endl;

	heap_sort(&arrA[0], 6);

	// Print out
	cout << "After Heapsort" << endl;
	for (int i=1; i<7; i++)
		cout << arrA[i] << " ";
	cout << endl;

	return 0;
}