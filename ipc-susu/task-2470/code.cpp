nclude <stdio.h>

// Time complexity: O(k)
// Space complexity: O(1)

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int m = n, x = n;
	while (k > 0) {
		int r;
		scanf("%d", &r);
		if (m > r) {
			m = r;
		}
		x = r - (n - x);
		if (x < 0) {
			x = 0;
		}
		k--;
	}
	printf("%d %d", x, m);
	return 0;
}