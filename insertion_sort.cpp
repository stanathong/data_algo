#include <iostream>

using namespace std;

void insertion_sort(int * A, int n)
{
int i, j, key;

	for (j = 1; j < n; j++)
	{
		key = A[j];
		i = j-1;

		while ((i >= 0) && (A[i] > key))
			{
				A[i+1] = A[i];
				i = i-1;
			}
			A[i+1] = key;
	}
}

int main(int argc, char * argv[])
{
int n;
int i;

cout << "Enter the number of elements to be sorted: ";
cin >> n;

int * A = new int [n];
for (i = 0; i < n; i++)
cin >> A[i];

insertion_sort(&A[0], n);

// Print out the result
for (i = 0; i < n; i++)
cout << A[i] << " ";
cout << endl;

return 0;
}