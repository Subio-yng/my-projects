#include <stdio.h>
#include <string>
#include <algorithm>

// Time complexity: O(lg(n1) * log(lg(n1)) + lg(n2) * lg(log(n2)))
// Space complexity: O(lg(n1) + lg(n2))

int getMax(int n) {
	std::string maxNum = std::to_string(n);
	if (n < 0) {
		std::sort(maxNum.begin(), maxNum.end());
		int i = 1;
		while (maxNum[i] == '0') {
			i++;
		}
		std::swap(maxNum[i], maxNum[1]);
	} else {
		std::sort(maxNum.rbegin(), maxNum.rend());
	}
	return atoi(maxNum.c_str());
}

int getMin(int n) {
	std::string minNum = std::to_string(n);
	if (n < 0) {
		std::sort(minNum.rbegin(), minNum.rend());
		return -atoi(minNum.c_str());
	} else {
		std::sort(minNum.begin(), minNum.end());
		int i = 0;
		while (minNum[i] == '0') {
			i++;
		}
		std::swap(minNum[i], minNum[0]);
		return atoi(minNum.c_str());
	}
}

int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	printf("%d", getMax(n1) - getMin(n2));
	return 0;
}