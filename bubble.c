int bubble(int *arr, int len) {
    int dot = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (dot++, arr[j] > arr[j+1])
            {
                arr[j] = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j] = arr[j]^arr[j+1];
            }
        }
    }
    return dot;
}

int bubble1(int *arr, int len) {
    int dot = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1-i; j++) {
            if (dot++, arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return dot;
}

int bubble2(int *arr, int len) {
    int dot = 0;
    for (int i = 0; i < len-1; i++) {
        int isSwap = 0;
        for (int j = 0; j < len-1-i; j++) {
            if (dot++, arr[j] > arr[j+1])
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
    return dot;
}

int bubble3(int *arr, int len) {
    int dot = 0;
    int endIndex = len;
    for (int i = 0; i < len-1; i++) {
        int isSwap = 0;
        for (int j = 0, end = endIndex; j < end-1; j++) {
            if (dot++, arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                endIndex = j+1;
                isSwap = 1;
            }
        }
        if (isSwap == 0) { 
            break;
        }
    }
    return dot;
}
