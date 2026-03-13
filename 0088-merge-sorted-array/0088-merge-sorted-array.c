void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Quicksort(int a[], int low, int high) {
    if (low < high) {
        int i = low-1;
        int pivot = a[high];
        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i+1], &a[high]);
        Quicksort(a, low, i);
        Quicksort(a, i+2, high);
    }
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int j = 0;
    int i = m;
    while (j < n) {
        nums1[i] = nums2[j];
        i++;
        j++;
    }
    Quicksort(nums1, 0, m+n-1);
}