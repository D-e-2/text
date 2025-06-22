#include <stdio.h>
#include <math.h>

// Gauss - Seidel迭代法
void gaussSeidel(double a[][3], double b[], double x[], int n, int maxIter) {
    double xNew[3];
    int k, i, j;
    for (k = 0; k < maxIter; k++) {
        for (i = 0; i < n; i++) {
            double sum1 = 0, sum2 = 0;
            for (j = 0; j < i; j++) {
                sum1 += a[i][j] * xNew[j];
            }
            for (j = i + 1; j < n; j++) {
                sum2 += a[i][j] * x[j];
            }
            xNew[i] = (b[i] - sum1 - sum2) / a[i][i];
        }
        for (i = 0; i < n; i++) {
            x[i] = xNew[i];
        }
    }
}
int main() {
    int n = 3, maxIter = 3;
    double a[3][3] = {
        {4, 1, -1},
        {2, 5, 1},
        {1, -2, 6}
    };
    double b[3] = {3, 9, -4};
    double x[3] = {0, 0, 0};
    gaussSeidel(a, b, x, n, maxIter);
    printf("Gauss - Seidel迭代法3次迭代后的解：\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4lf\n", i + 1, x[i]);
    }
    return 0;
}
