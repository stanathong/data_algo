#include <iostream>

using namespace std;

int binary_search(const int * A, int n, int& K)
{
	int m;
	int l=0; 
	int r=n-1;

	while (l <= r)
	{
		m = (l+r)/2;

		if (K == A[m])
			return m;
		else if (K < A[m])
			r = m-1;
		else 
			l = m+1;
	}

	return -1;
}

int recur_binary_search(const int * A, int n, int& K, int l, int r)
{
	if (l > r)
		return -1;

	int m = (l+r)/2;
	if (K == A[m])
		return m;
	else if (K < A[m])
		recur_binary_search(&A[0], n, K, l, m-1);
	else
		recur_binary_search(&A[0], n, K, m+1, r);
}

int main(int argc, char * argv[])
{
	int n;
	int i;
	int K;

	cout << "Enter the size of sorted array: ";
	cin >> n;
	int * A = new int[n];
	cout << "Enter sorted integer from small to large: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nElement[" << i << "] = "; 
		cin >> A[i];
	}
	cout << "Enter search key: " << endl;
	cin >> K;
	
	
	//printf("binary_search returns n = %d\n", binary_search(&A[0], n, K));

	printf("recur_binary_search returns n = %d\n", recur_binary_search(&A[0], n, K, 0, n-1));

	if (A)
		delete [] A;

	return 0;
}

