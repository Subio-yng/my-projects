#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	int operations;
	scanf("%d", &operations);
	for (int i = 0; i < operations; i++) {
		char buf[1 + 10];
		scanf(" %s", &buf);
		std::string inquiry(buf);
		if (inquiry == "get") {
			int id;
			scanf("%d", &id);
			id--;
			printf("%d\n", list[id]);
		}
		if (inquiry == "update") {
			int left, right, val;
			scanf("%d %d %d", &left, &right, &val);
			left--;
			right--;
			for (int j = left; j <= right; j++) {
				list[j] = val;
			}
		}
		if (inquiry == "add") {
			int left, right, val;
			scanf("%d %d %d", &left, &right, &val);
			left--;
			right--;
			for (int j = left; j <= right; j++) {
				list[j] += val;
			}
		}
		if (inquiry == "rsq") {
			int left, right;
			scanf("%d %d", &left, &right);
			left--;
			right--;
			int sum = 0;
			for (int j = left; j <= right; j++) {
				sum += list[j];
			}
			printf("%d\n", sum);
		}
		if (inquiry == "rmq") {
			int left, right;
			scanf("%d %d", &left, &right);
			left--;
			right--;
			int min = list[left];
			for (int j = left; j <= right; j++) {
				if (min > list[j]) {
					min = list[j];
				}
			}
			printf("%d\n", min);
		}
	}
	return 0;
}