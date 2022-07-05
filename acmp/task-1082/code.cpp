#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int nextChar() {
    static char buffer[1 << 16];
    static int pos = 0;
    static int size = 0;
    if (pos >= size) {
        size = (int) fread(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), stdin);
        pos = 0;
        if (pos >= size) {
            return EOF;
        }
    }
    int res = buffer[pos] & 0xFF;
    pos++;
    return res;
}

int nextInt() {
    int c = nextChar();
    while (0 <= c && c <= ' ') {
        c = nextChar();
    }
    int coef = 1;
    if (c == '-') {
        coef = -1;
        c = nextChar();
    }
    int n = c - '0';
    c = nextChar();
    while ('0' <= c && c <= '9') {
        int d = c - '0';
        c = nextChar();
        n = n * 10 + d;
    }
    return n * coef;
}

int main() {
    int sizeI = nextInt();
    int sizeJ = nextInt();
    int q = nextInt();
    std::vector<std::vector<long long>> prefixSum(sizeI + 1, std::vector<long long>(sizeJ + 1, 0));
	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			prefixSum[i][j] = nextInt() + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
		}
	}
    for (int i = 0; i < q; i++) {
        int i1 = nextInt();
        int j1 = nextInt();
        int i2 = nextInt();
        int j2 = nextInt();
        printf("%lld\n", prefixSum[i2][j2] - prefixSum[i2][j1 - 1] - prefixSum[i1 - 1][j2] + prefixSum[i1 - 1][j1 - 1]);
    }
	return 0;
}