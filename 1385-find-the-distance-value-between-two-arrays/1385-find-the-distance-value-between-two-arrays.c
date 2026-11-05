int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        int valid = 1;
        for (int j = 0; j < arr2Size; j++) {
            int diff = arr1[i] - arr2[j];
            if (diff < 0) diff = -diff;
            if (diff <= d) {
                valid = 0;
                break;
            }
        }
        if (valid) count++;
    }
    return count;
}