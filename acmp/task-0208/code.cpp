#include <stdio.h>
#include <algorithm>
#include <string>

// Time complexity: O(len(str)^2)
// Space complexity: O(1)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	std::string str;
	int max = n;
	while (n > 0) {
		str += n % 2 + '0';
		n /= 2;
	}
	for (int i = 0, j = (int) str.length() - 1; i < j; i++, j--) {
		std::swap(str[i], str[j]);
	}
	for (int i = 0; i < (int) str.length(); i++) {
		char back = str.back();
		for (int j = (int) str.length() - 1; j > 0; j--) {
			str[j] = str[j - 1];
		}
		str[0] = back;
		int temp = 0;
		for (int i = 0; i < (int) str.length(); i++) {
			temp += (str[i] - '0') * (1 << (int) str.length() - i - 1);
		}
		if (temp > max) {
			max = temp;
		}
	}
	printf("%d", max);
	return 0;
}