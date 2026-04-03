#include <stdio.h>

void selection(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) 
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    selection(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}