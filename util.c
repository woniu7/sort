#include <stdio.h>

void printInts(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	puts("");
}
