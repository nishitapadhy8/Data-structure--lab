#include <stdio.h>

void transpose(int a[10][10], int t[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[j][i] = a[i][j];
}

void disp(int a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);   // fixed here
        printf("\n");                 // fixed here
    }
}

int main() {
    int a[10][10], t[10][10], n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    transpose(a, t, n);
    disp(t, n);

    return 0;
}