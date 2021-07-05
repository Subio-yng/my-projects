#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	int count = n;
	while (n > 0) {
		int maxId = 0;
		for (int i = 1; i < n; i++) {
			if (list[maxId] < list[i]) {
				maxId = i;
			}
		}
		if (list[maxId] > list[n - 1]) {
			std::swap(list[maxId], list[n - 1]);
		}
		printf("%d ", maxId);
		n--;
	}
	return 0;
}