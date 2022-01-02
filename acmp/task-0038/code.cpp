#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(len^2)
// Space complexity: O(len^2)

int main() {
	int len;
	scanf("%d", &len);
	std::vector<int> list(len);
	for (int i = 0; i < len; i++) {
		scanf("%d", &list[i]);
	}
	std::vector<std::vector<int>> winDiff(len, std::vector<int>(len));
	winDiff[0][1] = list[0];
	for (int iLen = 1; iLen <= len; iLen++) {
		for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
			int iRight = iLeft + iLen - 1;
			if (iLen == 1) {
				winDiff[iLeft][iRight] = list[iLeft];
			} else {
				winDiff[iLeft][iRight] = std::max(
					list[iLeft] - winDiff[iLeft + 1][iRight],
					list[iRight] - winDiff[iLeft][iRight - 1]
				);
			}
		}
	}
	if (winDiff[0][len - 1] > 0) {
		printf("1");
	} else if (winDiff[0][len - 1] < 0) {
		printf("2");
	} else {
		printf("0");
	}
	return 0;
}