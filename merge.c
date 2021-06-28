#include <string.h>
#include <stdlib.h>

// O(n) space
int merge2way(int *arr, int len, int pivot)
{
	int *nArr = malloc(sizeof(int)*len);
	memcpy(nArr, arr, len*sizeof(int));
	int nLen = 0;
	int i = 0, j = pivot;
	while (i < pivot && j < len)
		nArr[nLen++] = arr[i] > arr[j] ? arr[j++]: arr[i++];
	while (i < pivot)
		nArr[nLen++] = arr[i++];
	while (j < len)
		nArr[nLen++] = arr[j++];
	memcpy(arr, nArr, nLen*sizeof(int));
	free(nArr);
	return 0;
}

// O(1) space
int merge2wayInplace(int *arr, int len, int pivot)
{
	int max = 1 + (arr[pivot-1] > arr[len-1]? arr[pivot-1]: arr[len-1]);
	
	int n = 0;
	int i = 0, j = pivot;
	while (i < pivot && j < len)
		arr[n++] += (arr[i]%max > arr[j]%max ? arr[j++]%max: arr[i++]%max) * max;
	while (i < pivot)
		arr[n++] += max*(arr[i++]%max);
	while (j < len)
		arr[n++] += max*(arr[j++]%max);

	for (int i = 0; i < len; i++) arr[i] /= max;

	return 0;
}

// O(nlogn) time
// O(1) space 
// recursive
int mergeRec(int *arr, int len)
{
	if (len <= 1) return 0;
	int pivot = len / 2;
	mergeRec(arr, pivot);
	mergeRec(arr+pivot, len-pivot);
	merge2wayInplace(arr, len, pivot);
	return 0;
}

// O(nlogn) time
// O(1) space 
int merge(int *arr, int len)
{
	if (len <= 1) return 0;
	int pivot = len / 2;
	merge(arr, pivot);
	merge(arr+pivot, len-pivot);
	merge2wayInplace(arr, len, pivot);
	return 0;
}
