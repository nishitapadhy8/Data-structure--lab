#include <stdio.h>

int binary(int a[], int n, int key) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == key) 
            return mid;  
        else if (a[mid] < key) 
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return -1;  
}

int main() {
    int n, a[100], key;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    scanf("%d", &key);

    int pos = binary(a, n, key);
    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}