#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	std::sort(list.begin(), list.end());
	int prevPairLen = 0;
	int maxCount = 0;
	int curPair = 0;
	while (curPair + 1 < n) {
		if (list[curPair] == list[curPair + 1]) {
			int curPairLen = list[curPair];
			if (prevPairLen == 0) {
				prevPairLen = curPairLen;
			} else {
				if (curPairLen <= 2 * prevPairLen) {
					maxCount++;
					prevPairLen = 0;
				} else {
					prevPairLen = curPairLen;
				}
			}
			curPair += 2;
		} else {
			curPair++;
		}
	}
	printf("%d", maxCount);
	return 0;
}