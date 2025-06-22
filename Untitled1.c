
#include <stdio.h>
#include <math.h>

// 列主元高斯消去法
void gaussElimination(double a[][4], int n) {
    int i, j, k, maxRow;
    double temp, ratio;
    for (k = 0; k < n - 1; k++) {
        maxRow = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > fabs(a[maxRow][k])) {
                maxRow = i;
            }
        }
        if (maxRow != k) {
            for (j = k; j < n + 1; j++) {
                temp = a[k][j];
                a[k][j] = a[maxRow][j];
                a[maxRow][j] = temp;
            }
        }
        for (i = k + 1; i < n; i++) {
            ratio = a[i][k] / a[k][k];
            for (j = k; j < n + 1; j++) {
                a[i][j] = a[i][j] - ratio * a[k][j];
            }
        }
    }
}

// 回代求解
void backSubstitution(double a[][4], int n, double x[]) {
    int i, j;
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }
}
int main() {
    int n = 3;
    double a[3][4] = {
        {4, 1, -1, 3},
        {2, 5, 1, 9},
        {1, -2, 6, -4}
    };
    double x[3];
    gaussElimination(a, n);
    backSubstitution(a, n, x);
    printf("列主元高斯消去法的解：\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i + 1, x[i]);
    }
    return 0;
}
