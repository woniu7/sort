/*
int partition(int *arr, int left, int right, int *dot) {
    int pivotValue = arr[left];
    while (left < right) {
        while ((*dot)++, left < right && arr[right] >= pivotValue) right--;
        arr[left] = arr[right]; 
        while ((*dot)++, left < right && arr[left] <= pivotValue) left++;
        arr[right] = arr[left]; 
    }
    arr[left] = pivotValue;
    return left;
}

int quick(int *arr, int len) {
    int dot = 0;
    if (len > 0) {
        int pivotIndex = partition(arr, 0, len-1, &dot);
        dot += quick(arr, pivotIndex);
        dot += quick(&arr[pivotIndex+1], len-pivotIndex-1);
    }
    return dot;
}
*/

int quick(int *arr, int len) {
    static int dot = 0;
    if (len > 0) {
	int left = 0, right = len-1;
        int pivotValue = arr[left];
        while (left < right) {
            while (dot++, left < right && arr[right] >= pivotValue) right--;
            arr[left] = arr[right]; 
            while (dot++, left < right && arr[left] <= pivotValue) left++;
            arr[right] = arr[left]; 
        }
        arr[left] = pivotValue;

        quick(arr, left);
        quick(&arr[left+1], len-left-1);
    }
    return dot;
}
