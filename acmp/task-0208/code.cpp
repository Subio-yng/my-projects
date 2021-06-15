#include <stdio.h>
#include <algorithm>
#include <string>

// Time complexity: O(len(str)^2)
// Space complexity: O(1)

std::string convertToBinaryString(int n) {
	std::string a;
	while (n > 0) {
		a += n % 2 + '0';
		n >>= 1;
	}
	for (int i = 0, j = (int) a.length() - 1; i < j; i++, j--) {
		std::swap(a[i], a[j]);
	}
	return a;
}

void cyclicShiftLeft(std::string &a) {
	std::string temp = a.substr(0, (int) a.length() - 1);
	a = a.back();
	a += temp;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::string str = convertToBinaryString(n);
	int max = n;
	for (int i = 0; i < (int) str.length(); i++) {
		cyclicShiftLeft(str);
		int temp = 0;
		for (int i = 0; i < (int) str.length(); i++) {
			temp += (str[i] - '0') * (1 << (int) str.length() - i - 1);
		}
		max = std::max(max, temp);
	}
	printf("%d", max);
	return 0;
}