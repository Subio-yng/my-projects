#include <bits/stdc++.h>

// Time complexity: O(log(val))
// Space complexity: O(1)

struct Matrix {

    int sizeI;

    int sizeJ;

    std::vector<std::vector<int>> m;

    Matrix(int sizeI, int sizeJ, int val)
            : sizeI(sizeI)
            , sizeJ(sizeJ)
    {
        m.resize(sizeI, std::vector<int>(sizeJ, val));
    }

    Matrix operator *(const Matrix &a) const {
        int sizeK = a.sizeJ;
        Matrix res(sizeI, sizeK, 0);
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                for (int k = 0; k < sizeK; k++) {
                    res.m[i][k] += this->m[i][j] * a.m[j][k];
                }
            }
        }
        return res;
    }

    static Matrix pow(const Matrix &a, int pow) {
        if (pow == 1) {
            return a;
        }
        Matrix half = Matrix::pow(a, pow / 2);
        if (pow % 2 == 0) {
            return half * half;
        }
        return half * half * a;
    }
};

int main() {
    int n, val;
    scanf("%d %d", &n, &val);
    Matrix fib(2, 2, 1);
    fib.m[0][0] = 0;
    fib = Matrix::pow(fib, n - 2);
    int a = fib.m[0][1];
    int b = fib.m[1][1];
    for (int x = 0; val >= 0; x++) {
        if (x > val / b && val % b == 0) {
            printf("%d %d", x, val / b);
            return 0;
        }
        val -= a;
    }
    printf("-1");
    return 0;
}