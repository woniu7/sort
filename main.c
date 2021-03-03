#include <stdio.h>

#define FUNC_DEF(func) { func, #func },

int bubble(int *, int);
int bubble1(int *, int);
int bubble2(int *, int);
int bubble3(int *, int);

int quick(int *, int);
int pick(int *, int);
int heap(int *, int);

void sort(int (*f)(int *,int), int* arr, int len)
{
        int dot = f(arr, len);
	printf("\tdot: %d \t", dot);
}

int main(int argc, char **argv)
{
    //void* goods[] = {bubble, bubble1, bubble2, bubble3};
    struct {
        void* func;
        const char * name;
    } goods[] = {
        FUNC_DEF(bubble)
        FUNC_DEF(bubble1)
        FUNC_DEF(bubble2)
        FUNC_DEF(bubble3)
    };

    for (int j = 0; j < sizeof(goods)/(2*sizeof(void*)); j++) 
    {
	    int arr[] = {7, 4, 5, 7, 6, 2, 0, 4, 1, 3, 1000, 1001, 1002, 1003, 1004, 1005, 1005, 1006, 1007};
	    int len =  sizeof(arr) / sizeof(int);
	    //for (int i = 0; i < len; i++) printf("%d ", arr[i]);
	    //printf("\n");

            printf("%s\n", goods[j].name);
	    // sort
	    sort(goods[j].func, arr, len);

	    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
	    printf("\n");
    }
}
