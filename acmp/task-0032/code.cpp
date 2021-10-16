#include <stdio.h>
#include <string>
#include <algorithm>

// Time complexity: O(n1 * log(n1) + n2 * log(n2))
// Space complexity: O(n1 + n2)

int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	std::string maxNum1 = std::to_string(n1);
	if (n1 < 0) {
		std::sort(maxNum1.begin(), maxNum1.end());
		int i = 1;
		while (maxNum1[i] == '0') {
			i++;
		}
		std::swap(maxNum1[i], maxNum1[1]);
	} else {
		std::sort(maxNum1.rbegin(), maxNum1.rend());
	}
	n1 = atoi(maxNum1.c_str());
	std::string minNum2 = std::to_string(n2);
	if (n2 < 0) {
		std::sort(minNum2.rbegin(), minNum2.rend());
		n2 = -1;
	} else {
		std::sort(minNum2.begin(), minNum2.end());
		int i = 0;
		while (minNum2[i] == '0') {
			i++;
		}
		std::swap(minNum2[i], minNum2[0]);
		n2 = 1;
	}
	n2 *= atoi(minNum2.c_str());
	printf("%d", n1 - n2);
	return 0;
}