#include <stdio.h>
#include <algorithm>

// Time complexity: O(len)
// Space complexity: O(1)

void printMaxNumber(int sum, int len) {
	for (int i = 0; i < len; i++) {
		if (sum >= 9) {
			printf("9");
			sum -= 9;
		} else {
			printf("%d", sum);
			sum = 0;
		}
	}
	printf(" ");
}

void printMinNumber(int sum, int len) {
	if (len == 1) {
		printf("%d", sum);
		return;
	}
	if (sum > 9) {
		printMinNumber(sum - 9, len - 1);
		printf("9");
		sum -= 9;
	} else {
		printMinNumber(1, len - 1);
		printf("%d", sum - 1);
		sum = 1;
	}
}

int main() {
	int sum, len;
	scanf("%d %d", &sum, &len);
	printMaxNumber(sum, len);
	printMinNumber(sum, len);
	return 0;
}