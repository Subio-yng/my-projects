#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(len^2)
// Space complexity: O(len^2)

int main() {
	char buf[1 + 30];
	scanf("%s", &buf);
	std::string str(buf);
	int len = (int) str.length();
	std::vector<std::vector<int>> ways(len, std::vector<int>(len, 0));
	for (int iLen = 1; iLen <= len; iLen++) {
		for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
			int iRight = iLeft + iLen - 1;
			if (iLen == 1) {
				ways[iLeft][iRight] = 1;
			} else if (str[iLeft] == str[iRight]) {
				ways[iLeft][iRight] = ways[iLeft + 1][iRight] +
					ways[iLeft][iRight - 1] + 1;
			} else {
				ways[iLeft][iRight] = ways[iLeft + 1][iRight] +
					ways[iLeft][iRight - 1] - ways[iLeft + 1][iRight - 1];
			}
		}
	}
	printf("%d", ways[0][len - 1]);
	return 0;
}