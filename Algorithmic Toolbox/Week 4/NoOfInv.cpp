#include <bits/stdc++.h>
using namespace std;

int mergeSortA(int A[], int temp[], int left, int right);
int merge(int A[], int temp[], int left, int mid,
		int right);

int mergeSort(int A[], int array_size)
{
	int temp[array_size];
	return mergeSortA(A, temp, 0, array_size - 1);
}

int mergeSortA(int A[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		inv_count += mergeSortA(A, temp, left, mid);
		inv_count += mergeSortA(A, temp, mid + 1, right);
		inv_count += merge(A, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(int A[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; 
	j = mid; 
	k = left; 
	while ((i <= mid - 1) && (j <= right)) {
		if (A[i] <= A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];


			inv_count = inv_count + (mid - i);
		}
	}


	while (i <= mid - 1)
		temp[k++] = A[i++];


	while (j <= right)
		temp[k++] = A[j++];


	for (i = left; i <= right; i++)
		A[i] = temp[i];

	return inv_count;
}


int main()
{

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
	int ans = mergeSort(A, n);
	cout  << ans;
	return 0;
}


