#include <stdio.h>
#include <vector>
#include <unordered_map>

// Time complexity: O(n)
// Space complexity: O(n)

struct DishStats {

	int lastId;

	int count;

	DishStats()
	: lastId(-1)
	, count(0)
	{}
};

int main() {
	int n, len;
	scanf("%d %d", &n, &len);
	std::unordered_map<int, DishStats> list;
	int maxCount = 0;
	int greaterDish = 0;
	for (int i = 0; i < n; i++) {
		int dish;
		scanf("%d", &dish);
		if (list[dish].lastId == -1 || i - list[dish].lastId > len) {
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