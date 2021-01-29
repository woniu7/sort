#include <stdio.h>

void bubble(int *, int);
void quick(int *, int);
void pick(int *, int);
void heap(int *, int);

void sort(void (*f)(int *,int), int* arr, int len)
{
        f(arr, len);
}

int main(int argc, char **argv)
{
    void* goods[] = {bubble};

    for (int j = 0; j < 1; j++) 
    {
	    int arr[] = {7, 4, 5, 7, 6, 2, 0, 4, 1, 3};
	    int len =  sizeof(arr) / sizeof(int);
	    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
	    printf("\n");

	    // sort
	    sort(goods[j], arr, len);

	    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
    }
}
