#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	long long part1 = 0, part2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		part2 += list[i];
	}
	long long maxMul = 0;
	for (int i = 0; i < n - 1; i++) {
		part1 += list[i] * list[i];
		part2 -= list[i];
		if (part1 * part2 > maxMul) {
			maxMul = part1 * part2;
		}
	}
	printf("%lld", maxMul);
	return 0;
}