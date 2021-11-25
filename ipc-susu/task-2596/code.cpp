#include <stdio.h>
#include <vector>
#include <unordered_map>

// Time complexity: O(n)
// Space complexity: O(n)

struct Pair {

	int lastId;

	int count;

	Pair() : lastId(-1), count(1)
	{}
};

int main() {
	int n, len;
	scanf("%d %d", &n, &len);
	std::unordered_map<int, Pair> list;
	int maxCount = 0;
	int greaterDish = 0;
	for (int i = 0; i < n; i++) {
		int dish;
		scanf("%d", &dish);
		if (list[dish].lastId == -1) {
			list[dish].lastId = i;
		} else if (i - list[dish].lastId > len) {
			list[dish].lastId = i;
			list[dish].count++;
		}
		if (list[dish].count > maxCount ||
			list[dish].count == maxCount && dish < greaterDish
			) {
			maxCount = list[dish].count;
			greaterDish = dish;
		}
	}
	printf("%d %d", greaterDish, maxCount);
	return 0;
}