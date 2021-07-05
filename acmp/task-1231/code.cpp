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
	int count = 0;
	while (n > 0) {
		bool change = true;
		for (int i = 1; i < n; i++) {
			if (list[i - 1] > list[i]) {
				std::swap(list[i - 1], list[i]);
				count++;
				change = false;
			}
		}
		if (change) {
			break;
		}
		n--;
	}
	printf("%d", count);
	return 0;
}