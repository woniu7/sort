int bubble(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (arr[j] > arr[j+1])
            {
                arr[j] = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j] = arr[j]^arr[j+1];
            }
        }
    }
    return 0;
}

int bubble1(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1-i; j++) {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return 0;
}

int bubble2(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        int isSwap = 0;
        for (int j = 0; j < len-1-i; j++) {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                isSwap = 1;
            }
        }
        if (isSwap == 0) { 
            break;
        }
    }
    return 0;
}

int bubble3(int *arr, int len) {
    int lastSwap = len - 1;
    for (int i = 0; i < len-1; i++) {
	int end = lastSwap;
        for (int j = 0; j < end; j++) {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                lastSwap = j; //the index of last swap, remain is sorted
            }
        }
        if (end == lastSwap) {  // swap nothing => sorted
            break;
        }
    }
    return 0;
}
